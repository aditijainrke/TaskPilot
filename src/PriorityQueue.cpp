
#include "../include/PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue()
{
}

void PriorityQueue::addTaskToPriorityQueue(const Task& task)
{
    int i = 0;

    while (i < static_cast<int>(tasks.size()) &&
           tasks[i].getPriority() <= task.getPriority())
    {
        i++;
    }

    tasks.insert(tasks.begin() + i, task);
}

bool PriorityQueue::getHighestPriorityTask(Task& result) const
{
    if (tasks.empty())
    {
        return false;
    }

    result = tasks.front();
    return true;
}

bool PriorityQueue::removeHighestPriorityTask()
{
    if (tasks.empty())
    {
        return false;
    }

    tasks.erase(tasks.begin());
    return true;
}

void PriorityQueue::displayPriorityTasks() const
{
    if (tasks.empty())
    {
        std::cout << "No tasks in priority queue.\n";
        return;
    }

    std::cout << "\nTasks in Priority Order:\n";

    for (const Task& task : tasks)
    {
        std::cout << "Priority: " << task.getPriority()
                  << " | Task: " << task.getTitle()
                  << " | Deadline: " << task.getDeadline()
                  << '\n';
    }
}

int PriorityQueue::getSize() const
{
    return static_cast<int>(tasks.size());
}

bool PriorityQueue::isEmpty() const
{
    return tasks.empty();
}
