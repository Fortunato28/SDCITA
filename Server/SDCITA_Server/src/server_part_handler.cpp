#include "server_part_handler.h"
#include <string>
#include <memory>
#include <thread>

#include <middleware.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/transport/TNonblockingServerSocket.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using namespace sdcita;

Server::Server(int port, const std::string& configFile, const std::string& host) :
    host_(host),
    port_(port),
    configFile_(configFile)
{
//    std::shared_ptr<FileReceiverHandler> handler(new FileReceiverHandler());
//    std::shared_ptr<TProcessor> processor(new FileReceiverProcessor(handler));
//    std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(host_, port_));
//    std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
//    std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    std::shared_ptr<FileReceiverHandler> handler(new FileReceiverHandler());
    std::shared_ptr<TProcessor> processor(new FileReceiverProcessor(handler));
    std::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    std::shared_ptr<TNonblockingServerTransport> serverTransport(new TNonblockingServerSocket(host_, port_));
    std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    std::shared_ptr<PosixThreadFactory> threadFactory = std::shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

//    TNonblockingServer server(processor, protocolFactory, serverTransport, threadManager);

    thriftServer_ = std::make_unique<::apache::thrift::server::TNonblockingServer>(processor, protocolFactory, serverTransport, threadManager);
//    thriftServer_ = std::make_unique<::apache::thrift::server::TSimpleServer>(processor, serverTransport, transportFactory, protocolFactory);

    taskHandler_ = std::make_unique<TaskHandler>();
}

void Server::Start() const
{
    // TODO в отдельный поток
    thriftServer_->serve();
}

void Server::Stop() const
{
    thriftServer_->stop();
}

