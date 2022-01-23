// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: counter.proto

#ifndef PROTOBUF_INCLUDED_counter_2eproto
#define PROTOBUF_INCLUDED_counter_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_counter_2eproto 

namespace protobuf_counter_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_counter_2eproto
namespace example {
class CounterResponse;
class CounterResponseDefaultTypeInternal;
extern CounterResponseDefaultTypeInternal _CounterResponse_default_instance_;
class FetchAddRequest;
class FetchAddRequestDefaultTypeInternal;
extern FetchAddRequestDefaultTypeInternal _FetchAddRequest_default_instance_;
class GetRequest;
class GetRequestDefaultTypeInternal;
extern GetRequestDefaultTypeInternal _GetRequest_default_instance_;
class Snapshot;
class SnapshotDefaultTypeInternal;
extern SnapshotDefaultTypeInternal _Snapshot_default_instance_;
}  // namespace example
namespace google {
namespace protobuf {
template<> ::example::CounterResponse* Arena::CreateMaybeMessage<::example::CounterResponse>(Arena*);
template<> ::example::FetchAddRequest* Arena::CreateMaybeMessage<::example::FetchAddRequest>(Arena*);
template<> ::example::GetRequest* Arena::CreateMaybeMessage<::example::GetRequest>(Arena*);
template<> ::example::Snapshot* Arena::CreateMaybeMessage<::example::Snapshot>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace example {

// ===================================================================

class Snapshot : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.Snapshot) */ {
 public:
  Snapshot();
  virtual ~Snapshot();

  Snapshot(const Snapshot& from);

  inline Snapshot& operator=(const Snapshot& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Snapshot(Snapshot&& from) noexcept
    : Snapshot() {
    *this = ::std::move(from);
  }

  inline Snapshot& operator=(Snapshot&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Snapshot& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Snapshot* internal_default_instance() {
    return reinterpret_cast<const Snapshot*>(
               &_Snapshot_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Snapshot* other);
  friend void swap(Snapshot& a, Snapshot& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Snapshot* New() const final {
    return CreateMaybeMessage<Snapshot>(NULL);
  }

  Snapshot* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Snapshot>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Snapshot& from);
  void MergeFrom(const Snapshot& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Snapshot* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int64 value = 1;
  bool has_value() const;
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int64 value() const;
  void set_value(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:example.Snapshot)
 private:
  void set_has_value();
  void clear_has_value();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int64 value_;
  friend struct ::protobuf_counter_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FetchAddRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.FetchAddRequest) */ {
 public:
  FetchAddRequest();
  virtual ~FetchAddRequest();

  FetchAddRequest(const FetchAddRequest& from);

  inline FetchAddRequest& operator=(const FetchAddRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FetchAddRequest(FetchAddRequest&& from) noexcept
    : FetchAddRequest() {
    *this = ::std::move(from);
  }

  inline FetchAddRequest& operator=(FetchAddRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FetchAddRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FetchAddRequest* internal_default_instance() {
    return reinterpret_cast<const FetchAddRequest*>(
               &_FetchAddRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(FetchAddRequest* other);
  friend void swap(FetchAddRequest& a, FetchAddRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FetchAddRequest* New() const final {
    return CreateMaybeMessage<FetchAddRequest>(NULL);
  }

  FetchAddRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FetchAddRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FetchAddRequest& from);
  void MergeFrom(const FetchAddRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FetchAddRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int64 value = 1;
  bool has_value() const;
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int64 value() const;
  void set_value(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:example.FetchAddRequest)
 private:
  void set_has_value();
  void clear_has_value();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int64 value_;
  friend struct ::protobuf_counter_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CounterResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.CounterResponse) */ {
 public:
  CounterResponse();
  virtual ~CounterResponse();

  CounterResponse(const CounterResponse& from);

  inline CounterResponse& operator=(const CounterResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CounterResponse(CounterResponse&& from) noexcept
    : CounterResponse() {
    *this = ::std::move(from);
  }

  inline CounterResponse& operator=(CounterResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CounterResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CounterResponse* internal_default_instance() {
    return reinterpret_cast<const CounterResponse*>(
               &_CounterResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(CounterResponse* other);
  friend void swap(CounterResponse& a, CounterResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CounterResponse* New() const final {
    return CreateMaybeMessage<CounterResponse>(NULL);
  }

  CounterResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<CounterResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const CounterResponse& from);
  void MergeFrom(const CounterResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CounterResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string redirect = 3;
  bool has_redirect() const;
  void clear_redirect();
  static const int kRedirectFieldNumber = 3;
  const ::std::string& redirect() const;
  void set_redirect(const ::std::string& value);
  #if LANG_CXX11
  void set_redirect(::std::string&& value);
  #endif
  void set_redirect(const char* value);
  void set_redirect(const char* value, size_t size);
  ::std::string* mutable_redirect();
  ::std::string* release_redirect();
  void set_allocated_redirect(::std::string* redirect);

  // optional int64 value = 2;
  bool has_value() const;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int64 value() const;
  void set_value(::google::protobuf::int64 value);

  // required bool success = 1;
  bool has_success() const;
  void clear_success();
  static const int kSuccessFieldNumber = 1;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:example.CounterResponse)
 private:
  void set_has_success();
  void clear_has_success();
  void set_has_value();
  void clear_has_value();
  void set_has_redirect();
  void clear_has_redirect();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr redirect_;
  ::google::protobuf::int64 value_;
  bool success_;
  friend struct ::protobuf_counter_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GetRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.GetRequest) */ {
 public:
  GetRequest();
  virtual ~GetRequest();

  GetRequest(const GetRequest& from);

  inline GetRequest& operator=(const GetRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetRequest(GetRequest&& from) noexcept
    : GetRequest() {
    *this = ::std::move(from);
  }

  inline GetRequest& operator=(GetRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetRequest* internal_default_instance() {
    return reinterpret_cast<const GetRequest*>(
               &_GetRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(GetRequest* other);
  friend void swap(GetRequest& a, GetRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetRequest* New() const final {
    return CreateMaybeMessage<GetRequest>(NULL);
  }

  GetRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GetRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GetRequest& from);
  void MergeFrom(const GetRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GetRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:example.GetRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_counter_2eproto::TableStruct;
};
// ===================================================================

class CounterService_Stub;

class CounterService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline CounterService() {};
 public:
  virtual ~CounterService();

  typedef CounterService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void fetch_add(::google::protobuf::RpcController* controller,
                       const ::example::FetchAddRequest* request,
                       ::example::CounterResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void get(::google::protobuf::RpcController* controller,
                       const ::example::GetRequest* request,
                       ::example::CounterResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CounterService);
};

class CounterService_Stub : public CounterService {
 public:
  CounterService_Stub(::google::protobuf::RpcChannel* channel);
  CounterService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~CounterService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements CounterService ------------------------------------------

  void fetch_add(::google::protobuf::RpcController* controller,
                       const ::example::FetchAddRequest* request,
                       ::example::CounterResponse* response,
                       ::google::protobuf::Closure* done);
  void get(::google::protobuf::RpcController* controller,
                       const ::example::GetRequest* request,
                       ::example::CounterResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CounterService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Snapshot

// required int64 value = 1;
inline bool Snapshot::has_value() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Snapshot::set_has_value() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Snapshot::clear_has_value() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Snapshot::clear_value() {
  value_ = GOOGLE_LONGLONG(0);
  clear_has_value();
}
inline ::google::protobuf::int64 Snapshot::value() const {
  // @@protoc_insertion_point(field_get:example.Snapshot.value)
  return value_;
}
inline void Snapshot::set_value(::google::protobuf::int64 value) {
  set_has_value();
  value_ = value;
  // @@protoc_insertion_point(field_set:example.Snapshot.value)
}

// -------------------------------------------------------------------

// FetchAddRequest

// required int64 value = 1;
inline bool FetchAddRequest::has_value() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FetchAddRequest::set_has_value() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FetchAddRequest::clear_has_value() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FetchAddRequest::clear_value() {
  value_ = GOOGLE_LONGLONG(0);
  clear_has_value();
}
inline ::google::protobuf::int64 FetchAddRequest::value() const {
  // @@protoc_insertion_point(field_get:example.FetchAddRequest.value)
  return value_;
}
inline void FetchAddRequest::set_value(::google::protobuf::int64 value) {
  set_has_value();
  value_ = value;
  // @@protoc_insertion_point(field_set:example.FetchAddRequest.value)
}

// -------------------------------------------------------------------

// CounterResponse

// required bool success = 1;
inline bool CounterResponse::has_success() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CounterResponse::set_has_success() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CounterResponse::clear_has_success() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CounterResponse::clear_success() {
  success_ = false;
  clear_has_success();
}
inline bool CounterResponse::success() const {
  // @@protoc_insertion_point(field_get:example.CounterResponse.success)
  return success_;
}
inline void CounterResponse::set_success(bool value) {
  set_has_success();
  success_ = value;
  // @@protoc_insertion_point(field_set:example.CounterResponse.success)
}

// optional int64 value = 2;
inline bool CounterResponse::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CounterResponse::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CounterResponse::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CounterResponse::clear_value() {
  value_ = GOOGLE_LONGLONG(0);
  clear_has_value();
}
inline ::google::protobuf::int64 CounterResponse::value() const {
  // @@protoc_insertion_point(field_get:example.CounterResponse.value)
  return value_;
}
inline void CounterResponse::set_value(::google::protobuf::int64 value) {
  set_has_value();
  value_ = value;
  // @@protoc_insertion_point(field_set:example.CounterResponse.value)
}

// optional string redirect = 3;
inline bool CounterResponse::has_redirect() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CounterResponse::set_has_redirect() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CounterResponse::clear_has_redirect() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CounterResponse::clear_redirect() {
  redirect_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_redirect();
}
inline const ::std::string& CounterResponse::redirect() const {
  // @@protoc_insertion_point(field_get:example.CounterResponse.redirect)
  return redirect_.GetNoArena();
}
inline void CounterResponse::set_redirect(const ::std::string& value) {
  set_has_redirect();
  redirect_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:example.CounterResponse.redirect)
}
#if LANG_CXX11
inline void CounterResponse::set_redirect(::std::string&& value) {
  set_has_redirect();
  redirect_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:example.CounterResponse.redirect)
}
#endif
inline void CounterResponse::set_redirect(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_redirect();
  redirect_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:example.CounterResponse.redirect)
}
inline void CounterResponse::set_redirect(const char* value, size_t size) {
  set_has_redirect();
  redirect_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:example.CounterResponse.redirect)
}
inline ::std::string* CounterResponse::mutable_redirect() {
  set_has_redirect();
  // @@protoc_insertion_point(field_mutable:example.CounterResponse.redirect)
  return redirect_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CounterResponse::release_redirect() {
  // @@protoc_insertion_point(field_release:example.CounterResponse.redirect)
  if (!has_redirect()) {
    return NULL;
  }
  clear_has_redirect();
  return redirect_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CounterResponse::set_allocated_redirect(::std::string* redirect) {
  if (redirect != NULL) {
    set_has_redirect();
  } else {
    clear_has_redirect();
  }
  redirect_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), redirect);
  // @@protoc_insertion_point(field_set_allocated:example.CounterResponse.redirect)
}

// -------------------------------------------------------------------

// GetRequest

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace example

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_counter_2eproto