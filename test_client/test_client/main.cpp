#include <iostream>

#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TTransportUtils.h>

#include <stdlib.h>
#include <thrift_generated.h>
#include <task_executor.h>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main()
{
//    stdcxx::shared_ptr<TTransport> socket(new TSocket("fort-pc", 9091));
//    stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
//    stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));


    stdcxx::shared_ptr<TSocket> socket(new TSocket("fort-pc", 9091));
    stdcxx::shared_ptr<TTransport> transport(new TFramedTransport(socket));
    stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    FileReceiverClient client(protocol);

    try
    {
        transport->open();

        FileChunk testedFile;
        client.ping();

        Task task;
        ClientData clientData;
        client.GetTask(task, clientData);


        Task_executor executor(task);
        executor.Execute();


        client.SendResult(executor.GetResult());

        transport->close();
    }

    catch (TException& tx)
    {
        cout << "ERROR: " << tx.what() << endl;
    }
}
