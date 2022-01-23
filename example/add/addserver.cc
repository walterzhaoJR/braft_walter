/*
 * addsever.cc
 *
 *  Created on: 2019年4月23日
 *      Author: teddyzhu
 */

#include <map>
#include <string>
#include <gflags/gflags.h>
#include <brpc/controller.h>            // brpc::Controller
#include <brpc/server.h>                // brpc::Server
#include <braft/raft.h>
#include <braft/util.h>
#include <braft/storage.h>
#include <butil/sys_byteorder.h>
#include "add.pb.h"


DEFINE_int32(port, 8100, "Listen port of this peer");
DEFINE_bool(h, false, "print help information");
DEFINE_string(group, "add", "Id of the replication group");
DEFINE_string(conf, "", "Initial configuration of the replication group");
DEFINE_string(data_path, "./data", "Path of data stored on");
DEFINE_int32(election_timeout_ms, 5000,
            "Start election in such milliseconds if disconnect with the leader");

using namespace std;

namespace example {

class AddStateMachine ;

class AddClosure : public braft::Closure {
public:
	AddClosure(AddStateMachine* statemachine,const AddRequest* request,AddResponse* response
			,google::protobuf::Closure* done)
			:statemachine_(statemachine),request_(request),response_(response),done_(done){

	};
	void Run();
	const AddRequest* Request(){
		return request_;
	}
	AddResponse* Response(){
		return response_;
	}
private:
	AddStateMachine* statemachine_;
	const AddRequest* request_;
	AddResponse* response_;
	google::protobuf::Closure* done_;
};

class AddStateMachine : public braft::StateMachine {
public:
	AddStateMachine():_node(NULL),leader_term_(-1){};

	~AddStateMachine(){}

	int start();

    virtual void on_apply(::braft::Iterator& iter) ;


/*    virtual void on_shutdown();


    virtual void on_snapshot_save(::braft::SnapshotWriter* writer,
                                  ::braft::Closure* done);


    virtual int on_snapshot_load(::braft::SnapshotReader* reader);*/

    void on_shutdown() {
        LOG(INFO) << "This node is down";
    }
    void on_error(const ::braft::Error& e) {
        LOG(ERROR) << "Met raft error " << e;
    }
    void on_configuration_committed(const ::braft::Configuration& conf) {
        LOG(INFO) << "Configuration of this group is " << conf;
    }
    void on_stop_following(const ::braft::LeaderChangeContext& ctx) {
        LOG(INFO) << "Node stops following " << ctx;
    }
    void on_start_following(const ::braft::LeaderChangeContext& ctx) {
        LOG(INFO) << "Node start following " << ctx;
    }

    void on_leader_start(int64_t term) {
        leader_term_.store(term, butil::memory_order_release);
        LOG(INFO) << "Node becomes leader";
    }
    void on_leader_stop(const butil::Status& status) {
        leader_term_.store(-1, butil::memory_order_release);
        LOG(INFO) << "Node stepped down : " << status;
    }

    bool is_leader() const
        { return leader_term_.load(butil::memory_order_acquire) > 0; }

    void redirect(AddResponse* response) {
        response->set_success(false);
        response->set_result(-1);
        if (_node) {
            braft::PeerId leader = _node->leader_id();
            if (!leader.is_empty()) {
            	LOG(DEBUG) <<"redirect : " << leader;
                response->set_redirect(leader.to_string());
            }
        }

    }

    void write(const ::example::AddRequest* request,::example::AddResponse* response
    		,::google::protobuf::Closure* done);

    void reallyWrite(const string& key ,long long number,AddResponse* response);

    // Shut this node down.
    void shutdown() {
        if (_node) {
            _node->shutdown(NULL);
        }
    }

    // Blocking this thread until the node is eventually down.
    void join() {
        if (_node) {
            _node->join();
        }
    }
private:
    map<string,long long> number_map_;
    braft::Node* volatile _node;
    butil::atomic<int64_t> leader_term_;
};

int AddStateMachine::start(){
	butil::EndPoint addr(butil::my_ip(), FLAGS_port);
    braft::Node* node = new braft::Node(FLAGS_group, braft::PeerId(addr));
    braft::NodeOptions node_options;
    if (!butil::CreateDirectory(butil::FilePath(FLAGS_data_path))) {
        LOG(ERROR) << "Fail to create directory " << FLAGS_data_path;
        return -1;
    }
    node_options.election_timeout_ms = FLAGS_election_timeout_ms;
    node_options.fsm = this;
    std::string prefix = "local://" + FLAGS_data_path;
    node_options.log_uri = prefix + "/log";
    node_options.raft_meta_uri = prefix + "/raft_meta";
    node_options.snapshot_uri = prefix + "/snapshot";
    if (node_options.initial_conf.parse_from(FLAGS_conf) != 0) {
        LOG(ERROR) << "Fail to parse configuration `" << FLAGS_conf << '\'';
        return -1;
    }
    if (node->init(node_options) != 0) {
        LOG(ERROR) << "Fail to init raft node";
        delete node;
        return -1;
    }
    _node = node;
    return 0;
}

void AddStateMachine::on_apply(braft::Iterator& iter) {

	 for (; iter.valid(); iter.next()) {
		braft::AsyncClosureGuard closure_guard(iter.done());
        butil::IOBuf data;
        string key;
        long long number;
        AddResponse* response = NULL;
		if (iter.done()) {
		  // This task is applied by this node, get value from this
		  // closure to avoid additional parsing.
		  LOG(DEBUG) << "iter.done";
		  AddClosure* c = dynamic_cast<AddClosure*>(iter.done());
		  LOG(INFO) <<"request ptr:" <<c->Request();
		  key = c->Request()->key();
		  number = c->Request()->number();
		  response = c->Response();
		} else {
		  // Have to parse BlockRequest from this log.
			 LOG(DEBUG) << "parse from iter.data";
		  uint32_t meta_size = 0;
		  butil::IOBuf saved_log = iter.data();
		  saved_log.cutn(&meta_size, sizeof(uint32_t));
		  // Remember that meta_size is in network order which hould be
		  // covert to host order
		  meta_size = butil::NetToHost32(meta_size);
		  butil::IOBuf meta;
		  saved_log.cutn(&meta, meta_size);
		  butil::IOBufAsZeroCopyInputStream wrapper(meta);
		  AddRequest request;
		  CHECK(request.ParseFromZeroCopyStream(&wrapper));
		  key = request.key();
		  number = request.number();
		}
		reallyWrite(key,number,response);
	 }
}

void AddStateMachine::write(const ::example::AddRequest* request,::example::AddResponse* response
		,::google::protobuf::Closure* done){
	brpc::ClosureGuard done_guard(done);

    const int64_t term = leader_term_.load(butil::memory_order_relaxed);
    LOG(DEBUG) <<"term:" <<term;
    if (term < 0) {
    	LOG(DEBUG) <<"redirect";
        return redirect(response);
    }
	LOG(INFO) <<"request ptr:" <<request;
	LOG(INFO) <<"done ptr:" <<done;
	LOG(INFO) << "request message ,key:" << request->key() << ",number:" << request->number();
    // Apply this log as a braft::Task
    butil::IOBuf log;
    const uint32_t meta_size_raw = butil::HostToNet32(request->ByteSize());
    log.append(&meta_size_raw, sizeof(uint32_t));
    butil::IOBufAsZeroCopyOutputStream wrapper(&log);
    if (!request->SerializeToZeroCopyStream(&wrapper)) {
        LOG(ERROR) << "Fail to serialize request";
        response->set_success(false);
        return;
    }
    braft::Task task;
    task.data = &log;
    task.done = new AddClosure( this,request,response,done_guard.release());
    // Now the task is applied to the group, waiting for the result.
    _node->apply(task);
    LOG(INFO) <<"apply done";
    return;
}

void AddStateMachine::reallyWrite(const string& key ,long long number,AddResponse* response){
	LOG(INFO) << "request message ,key:" << key << ",number:" << number;
	long long result = number;
	if (number_map_.find(key) == number_map_.end()) {
		number_map_.insert(make_pair(key,result));
	}
	else {
		result += number_map_[key];
		number_map_[key] = result;
	}
	LOG(INFO) << "reslut:" << result;
	if (response) {
		LOG(DEBUG) << "response isn't NULL,set response";
		response->set_success(true);
		response->set_result(result);
	}
}

class AddServiceImpl :public AddService{
public:
	AddServiceImpl(AddStateMachine* sm):statemachine_(sm){

	}
	void write(::google::protobuf::RpcController* controller,
	                       const ::example::AddRequest* request,
	                       ::example::AddResponse* response,
	                       ::google::protobuf::Closure* done) {
		brpc::ClosureGuard done_guard(done);
		statemachine_->write(request,response, done_guard.release());
		return;
	}
private:
	AddStateMachine* statemachine_;
};

void AddClosure::Run(){
    // Auto delete this after Run()
    std::unique_ptr<AddClosure> self_guard(this);
    // Repsond this RPC.
    LOG(INFO) <<"done ptr:" <<done_;
    brpc::ClosureGuard done_guard(done_);
    if (status().ok()) {
        return;
    }
    statemachine_->redirect(response_);
}

}

int main(int argc, char* argv[]){
	gflags::SetVersionString("0.1");
	gflags::SetUsageMessage("Usage: xxxx");
	gflags::ParseCommandLineFlags(&argc, &argv, true);
    brpc::Server server;
    example::AddStateMachine statemachine;
    example::AddServiceImpl service(&statemachine);

    // Add your service into RPC rerver
    if (server.AddService(&service,
                          brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add service";
        return -1;
    }

    if (braft::add_service(&server, FLAGS_port) != 0) {
        LOG(ERROR) << "Fail to add raft service";
        return -1;
    }

    if (server.Start(FLAGS_port, NULL) != 0) {
        LOG(ERROR) << "Fail to start Server";
        return -1;
    }

    if (statemachine.start() != 0) {
        LOG(ERROR) << "Fail to start state machine";
        return -1;
    }

    LOG(INFO) << "add service is running on " << server.listen_address();
    // Wait until 'CTRL-C' is pressed. then Stop() and Join() the service
    while (!brpc::IsAskedToQuit()) {
        sleep(1);
    }
    LOG(INFO) << "add service is going to quit";

    statemachine.shutdown();
    server.Stop(0);

    statemachine.join();
    server.Join();
    return 0;
}
