#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include <memory>

#include <thrift_generated.h>
#include <middleware.h>
#include <task_handler.h>
#include <thrift/server/TNonblockingServer.h>

namespace sdcita
{
const std::string localhost = "localhost";

class Server
{
public:
    // Constructor
    Server(int port, const std::string& configFile, const std::string& host = localhost);

    // Start thriftServer
    void Start() const;

    // Stop thriftServer
    void Stop() const;
private:
    const std::string host_;
    const int port_;

    std::string configFile_;
    std::vector<std::string> clientsConfigFile_;

//    std::unique_ptr<::apache::thrift::server::TSimpleServer> thriftServer_;
    std::unique_ptr<::apache::thrift::server::TNonblockingServer> thriftServer_;
    std::unique_ptr<TaskHandler> taskHandler_;
};

} // namespace sdcita

#endif // SERVER_H
