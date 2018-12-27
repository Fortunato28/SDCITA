#ifndef TASK_HANDLER_H
#define TASK_HANDLER_H

#include <thrift_generated.h>

class TaskHandler
{
public:
    TaskHandler();

    // Return balanced task
    Task GetTask();
private:
    // Balanced - mean task has only needed files for each client
    Task fileBalancing();

    Task currentTask_;
};

#endif // TASK_HANDLER_H
