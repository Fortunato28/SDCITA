/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef description_for_thrift_TYPES_H
#define description_for_thrift_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>




class FileChunk;

class Task;

class ClientData;

typedef struct _FileChunk__isset {
  _FileChunk__isset() : fileFormat(false), hash(false) {}
  bool fileFormat :1;
  bool hash :1;
} _FileChunk__isset;

class FileChunk : public virtual ::apache::thrift::TBase {
 public:

  FileChunk(const FileChunk&);
  FileChunk& operator=(const FileChunk&);
  FileChunk() : fileName(), data(), fileFormat(), isExecutable(0), hash() {
  }

  virtual ~FileChunk() throw();
  std::string fileName;
  std::string data;
  std::string fileFormat;
  bool isExecutable;
  std::string hash;

  _FileChunk__isset __isset;

  void __set_fileName(const std::string& val);

  void __set_data(const std::string& val);

  void __set_fileFormat(const std::string& val);

  void __set_isExecutable(const bool val);

  void __set_hash(const std::string& val);

  bool operator == (const FileChunk & rhs) const
  {
    if (!(fileName == rhs.fileName))
      return false;
    if (!(data == rhs.data))
      return false;
    if (__isset.fileFormat != rhs.__isset.fileFormat)
      return false;
    else if (__isset.fileFormat && !(fileFormat == rhs.fileFormat))
      return false;
    if (!(isExecutable == rhs.isExecutable))
      return false;
    if (__isset.hash != rhs.__isset.hash)
      return false;
    else if (__isset.hash && !(hash == rhs.hash))
      return false;
    return true;
  }
  bool operator != (const FileChunk &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FileChunk & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FileChunk &a, FileChunk &b);

std::ostream& operator<<(std::ostream& out, const FileChunk& obj);

typedef struct _Task__isset {
  _Task__isset() : otherData(false), estimatedLeadTime(false) {}
  bool otherData :1;
  bool estimatedLeadTime :1;
} _Task__isset;

class Task : public virtual ::apache::thrift::TBase {
 public:

  Task(const Task&);
  Task& operator=(const Task&);
  Task() : taskName(), taskDescription(), otherData(), estimatedLeadTime(0) {
  }

  virtual ~Task() throw();
  std::string taskName;
  std::string taskDescription;
  std::vector<FileChunk>  files;
  std::string otherData;
  int64_t estimatedLeadTime;

  _Task__isset __isset;

  void __set_taskName(const std::string& val);

  void __set_taskDescription(const std::string& val);

  void __set_files(const std::vector<FileChunk> & val);

  void __set_otherData(const std::string& val);

  void __set_estimatedLeadTime(const int64_t val);

  bool operator == (const Task & rhs) const
  {
    if (!(taskName == rhs.taskName))
      return false;
    if (!(taskDescription == rhs.taskDescription))
      return false;
    if (!(files == rhs.files))
      return false;
    if (__isset.otherData != rhs.__isset.otherData)
      return false;
    else if (__isset.otherData && !(otherData == rhs.otherData))
      return false;
    if (__isset.estimatedLeadTime != rhs.__isset.estimatedLeadTime)
      return false;
    else if (__isset.estimatedLeadTime && !(estimatedLeadTime == rhs.estimatedLeadTime))
      return false;
    return true;
  }
  bool operator != (const Task &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Task & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Task &a, Task &b);

std::ostream& operator<<(std::ostream& out, const Task& obj);

typedef struct _ClientData__isset {
  _ClientData__isset() : language(false) {}
  bool language :1;
} _ClientData__isset;

class ClientData : public virtual ::apache::thrift::TBase {
 public:

  ClientData(const ClientData&);
  ClientData& operator=(const ClientData&);
  ClientData() : OS(), osVersions(), CPU(), timeZone(0), clientId(0), language() {
  }

  virtual ~ClientData() throw();
  std::string OS;
  std::string osVersions;
  std::string CPU;
  int32_t timeZone;
  int64_t clientId;
  std::string language;

  _ClientData__isset __isset;

  void __set_OS(const std::string& val);

  void __set_osVersions(const std::string& val);

  void __set_CPU(const std::string& val);

  void __set_timeZone(const int32_t val);

  void __set_clientId(const int64_t val);

  void __set_language(const std::string& val);

  bool operator == (const ClientData & rhs) const
  {
    if (!(OS == rhs.OS))
      return false;
    if (!(osVersions == rhs.osVersions))
      return false;
    if (!(CPU == rhs.CPU))
      return false;
    if (!(timeZone == rhs.timeZone))
      return false;
    if (!(clientId == rhs.clientId))
      return false;
    if (__isset.language != rhs.__isset.language)
      return false;
    else if (__isset.language && !(language == rhs.language))
      return false;
    return true;
  }
  bool operator != (const ClientData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ClientData &a, ClientData &b);

std::ostream& operator<<(std::ostream& out, const ClientData& obj);



#endif