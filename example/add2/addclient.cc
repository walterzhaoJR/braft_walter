/*
 * addclient.cc
 *
 *  Created on: 2019年4月23日
 *      Author: teddyzhu
 */

#include <string>
#include <gflags/gflags.h>
#include <brpc/controller.h>            // brpc::Controller
#include <brpc/channel.h>
#include "add.pb.h"

DEFINE_string(serverport, "8100", "Listen port of this peer");
DEFINE_string(severip, "127.0.0.1", "Listen ip of this peer");
DEFINE_string(key, "default", "add key");
DEFINE_int64(value, 1, "add value");
DEFINE_bool(start_new_statemachine, false, "start_new_statemachine");

int main(int argc, char* argv[]){
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	std::string host = FLAGS_severip + ":" + FLAGS_serverport;
    brpc::Channel channel;
    if (channel.Init(host.c_str(), NULL) != 0) {
        LOG(ERROR) << "Fail to init channel to " << host;
        return -1;
    }
    example::AddService_Stub stub(&channel);
    brpc::Controller cntl;
    if (!FLAGS_start_new_statemachine) {
		example::AddRequest request;
		example::AddResponse response;
		request.set_key(FLAGS_key);
		request.set_number(FLAGS_value);
		stub.write(&cntl,&request,&response,NULL);
		if (cntl.Failed()) {
			LOG(ERROR) << "errorcode:" << cntl.ErrorCode();
			LOG(ERROR) << "errortxt:" << cntl.ErrorText();
			return -1;
		}
		LOG(INFO) << "result:" <<response.result();
		LOG(DEBUG) << "response:" ;
		response.PrintDebugString();
		return 0;
    }
    else {
    	example::NewStateMachineRequest request;
		example::NewStateMachineResponse response;
		request.set_id(1);
		stub.start_new_statemachine(&cntl,&request,&response,NULL);
		if (cntl.Failed()) {
			LOG(ERROR) << "errorcode:" << cntl.ErrorCode();
			LOG(ERROR) << "errortxt:" << cntl.ErrorText();
			return -1;
		}
		LOG(INFO) << "success:" <<response.success();
		LOG(DEBUG) << "response:" ;
		response.PrintDebugString();
		return 0;
    }
}
