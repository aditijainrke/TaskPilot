
#ifndef TASK_REPLANNER_H
#define TASK_REPLANNER_H

#include "Task.h"
#include <vector>

class TaskReplanner
{
public:
    void replanTasks(Task tasks[], int size);

    std::vector<Task> getReplannedTasks(
        const std::vector<Task>& tasks
    ) const;
};

#endif
