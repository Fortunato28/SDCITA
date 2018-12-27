#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <fstream>
#include <stdlib.h>

#include <../../Server/SDCITA_Server/inc/thrift_generated.h>
#include <../../Server/SDCITA_Server/inc/middleware.h>


using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main() {
  stdcxx::shared_ptr<TTransport> socket(new TSocket("fort-pc", 9090));
  stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  FileReceiverClient client(protocol);

  try {
    transport->open();

    FileChunk testedFile;
    client.ping();

    Task task;
    client.GetTask(task);

    transport->close();
  }

  catch (TException& tx)
  {
        cout << "ERROR: " << tx.what() << endl;
  }
}
