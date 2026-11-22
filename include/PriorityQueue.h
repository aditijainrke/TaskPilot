
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Task.h"
#include <vector>

class PriorityQueue
{
private:
    std::vector<Task> tasks;

public:
    PriorityQueue();

    void addTaskToPriorityQueue(const Task& task);

    bool getHighestPriorityTask(Task& result) const;

    bool removeHighestPriorityTask();

    void displayPriorityTasks() const;

    int getSize() const;

    bool isEmpty() const;
};

#endif
