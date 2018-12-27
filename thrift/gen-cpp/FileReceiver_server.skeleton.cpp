// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "FileReceiver.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class FileReceiverHandler : virtual public FileReceiverIf {
 public:
  FileReceiverHandler() {
    // Your initialization goes here
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void GetFile(FileChunk& _return, const std::string& fileName) {
    // Your implementation goes here
    printf("GetFile\n");
  }

  void GetTask(Task& _return, const ClientData& data) {
    // Your implementation goes here
    printf("GetTask\n");
  }

  bool SendResult(const FileChunk& result) {
    // Your implementation goes here
    printf("SendResult\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<FileReceiverHandler> handler(new FileReceiverHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new FileReceiverProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
