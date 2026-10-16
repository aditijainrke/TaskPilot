
#ifndef TASK_STORAGE_H
#define TASK_STORAGE_H

#include <vector>
#include "Task.h"

using namespace std;

class TaskStorage
{
public:
    bool saveTask(int userId, const Task& task);
    vector<Task> loadTasks(int userId);
    bool deleteTask(int userId, int taskId);
    bool updateTask(int userId, const Task& updatedTask);
};

#endif
