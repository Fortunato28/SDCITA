#ifndef TASK_EXECUTOR_H
#define TASK_EXECUTOR_H

#include <thrift_generated.h>
#include <boost/filesystem.hpp>

class Task_executor
{
public:
    Task_executor(const Task& gettedTask);

    // Запуск выполнения задания
    bool Execute();

    // Получение результата задания
    FileChunk GetResult();

private:
    void PrepareFiles();
    void setPermissions(const std::string& fileName);
    void createDirectory(const std::string& directoryName);

    Task gettedTask_;
    std::string pathToFiles_;
};

#endif // TASK_EXECUTOR_H
