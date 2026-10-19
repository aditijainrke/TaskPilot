#include "Task.h"

class PriorityQueue
{
private:
    Task tasks[100];
    int size;

public:
    PriorityQueue();

    void addTaskToPriorityQueue(const Task& task);
    bool getHighestPriorityTask(Task& result) const;
    bool removeHighestPriorityTask();
    void displayPriorityTasks() const;
};