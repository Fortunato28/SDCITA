#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include "FileReceiver.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <task_handler.h>

class FileReceiverHandler : virtual public FileReceiverIf {
public:
    FileReceiverHandler();

    void ping() override;

    void GetFile(FileChunk& _return, const std::string& fileName) override;

    void GetTask(Task& _return, const ClientData& data) override;

    bool SendResult(const FileChunk& result) override;

private:
    TaskHandler taskHandler_;

};

#endif // FILERECEIVER_H
