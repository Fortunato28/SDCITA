#include <iostream>
#include <fstream>
#include <string>

#include <middleware.h>
#include <server_part_handler.h>
#include <task_handler.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace std;

FileReceiverHandler::FileReceiverHandler()
{
}

void FileReceiverHandler::ping()
{
        // Your implementation goes here
        printf("ping\n");
}

void FileReceiverHandler::GetFile(FileChunk& _return, const std::string& fileName)
{
    printf("GetFile\n");
}

void FileReceiverHandler::GetTask(Task& _return, const ClientData& data)
{
    std::cout << "Task received" << "\n";

    auto returnedData = taskHandler_.GetTask();

    _return = returnedData;
}

bool FileReceiverHandler::SendResult(const FileChunk& result)
{
    // Your implementation goes here
    cout << "SendResult" << "\n";
    cout << result.fileName << "\n";

    // Save all files filesystem
        std::ofstream fileOnFS(result.fileName);
        fileOnFS << result.data;

        fileOnFS.close();

        return 0;
}
