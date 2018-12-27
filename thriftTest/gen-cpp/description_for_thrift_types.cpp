/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "description_for_thrift_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




FileChunk::~FileChunk() throw() {
}


void FileChunk::__set_fileName(const std::string& val) {
  this->fileName = val;
}

void FileChunk::__set_data(const std::string& val) {
  this->data = val;
}

void FileChunk::__set_fileFormat(const std::string& val) {
  this->fileFormat = val;
__isset.fileFormat = true;
}

void FileChunk::__set_isExecutable(const bool val) {
  this->isExecutable = val;
}

void FileChunk::__set_hash(const std::string& val) {
  this->hash = val;
__isset.hash = true;
}
std::ostream& operator<<(std::ostream& out, const FileChunk& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t FileChunk::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_fileName = false;
  bool isset_data = false;
  bool isset_isExecutable = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->fileName);
          isset_fileName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->data);
          isset_data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->fileFormat);
          this->__isset.fileFormat = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isExecutable);
          isset_isExecutable = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->hash);
          this->__isset.hash = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_fileName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_data)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_isExecutable)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t FileChunk::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FileChunk");

  xfer += oprot->writeFieldBegin("fileName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->fileName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->data);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.fileFormat) {
    xfer += oprot->writeFieldBegin("fileFormat", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->fileFormat);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("isExecutable", ::apache::thrift::protocol::T_BOOL, 4);
  xfer += oprot->writeBool(this->isExecutable);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.hash) {
    xfer += oprot->writeFieldBegin("hash", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeBinary(this->hash);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FileChunk &a, FileChunk &b) {
  using ::std::swap;
  swap(a.fileName, b.fileName);
  swap(a.data, b.data);
  swap(a.fileFormat, b.fileFormat);
  swap(a.isExecutable, b.isExecutable);
  swap(a.hash, b.hash);
  swap(a.__isset, b.__isset);
}

FileChunk::FileChunk(const FileChunk& other0) {
  fileName = other0.fileName;
  data = other0.data;
  fileFormat = other0.fileFormat;
  isExecutable = other0.isExecutable;
  hash = other0.hash;
  __isset = other0.__isset;
}
FileChunk& FileChunk::operator=(const FileChunk& other1) {
  fileName = other1.fileName;
  data = other1.data;
  fileFormat = other1.fileFormat;
  isExecutable = other1.isExecutable;
  hash = other1.hash;
  __isset = other1.__isset;
  return *this;
}
void FileChunk::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FileChunk(";
  out << "fileName=" << to_string(fileName);
  out << ", " << "data=" << to_string(data);
  out << ", " << "fileFormat="; (__isset.fileFormat ? (out << to_string(fileFormat)) : (out << "<null>"));
  out << ", " << "isExecutable=" << to_string(isExecutable);
  out << ", " << "hash="; (__isset.hash ? (out << to_string(hash)) : (out << "<null>"));
  out << ")";
}


Task::~Task() throw() {
}


void Task::__set_taskName(const std::string& val) {
  this->taskName = val;
}

void Task::__set_taskDescription(const std::string& val) {
  this->taskDescription = val;
}

void Task::__set_files(const std::vector<FileChunk> & val) {
  this->files = val;
}

void Task::__set_otherData(const std::string& val) {
  this->otherData = val;
__isset.otherData = true;
}
std::ostream& operator<<(std::ostream& out, const Task& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Task::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_taskName = false;
  bool isset_taskDescription = false;
  bool isset_files = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->taskName);
          isset_taskName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->taskDescription);
          isset_taskDescription = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->files.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->files.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += this->files[_i6].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_files = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->otherData);
          this->__isset.otherData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_taskName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_taskDescription)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_files)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Task::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Task");

  xfer += oprot->writeFieldBegin("taskName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->taskName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("taskDescription", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->taskDescription);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("files", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->files.size()));
    std::vector<FileChunk> ::const_iterator _iter7;
    for (_iter7 = this->files.begin(); _iter7 != this->files.end(); ++_iter7)
    {
      xfer += (*_iter7).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  if (this->__isset.otherData) {
    xfer += oprot->writeFieldBegin("otherData", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->otherData);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Task &a, Task &b) {
  using ::std::swap;
  swap(a.taskName, b.taskName);
  swap(a.taskDescription, b.taskDescription);
  swap(a.files, b.files);
  swap(a.otherData, b.otherData);
  swap(a.__isset, b.__isset);
}

Task::Task(const Task& other8) {
  taskName = other8.taskName;
  taskDescription = other8.taskDescription;
  files = other8.files;
  otherData = other8.otherData;
  __isset = other8.__isset;
}
Task& Task::operator=(const Task& other9) {
  taskName = other9.taskName;
  taskDescription = other9.taskDescription;
  files = other9.files;
  otherData = other9.otherData;
  __isset = other9.__isset;
  return *this;
}
void Task::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Task(";
  out << "taskName=" << to_string(taskName);
  out << ", " << "taskDescription=" << to_string(taskDescription);
  out << ", " << "files=" << to_string(files);
  out << ", " << "otherData="; (__isset.otherData ? (out << to_string(otherData)) : (out << "<null>"));
  out << ")";
}


