#include "../include/PriorityQueue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() {
    size = 0;
}

void PriorityQueue::addTaskToPriorityQueue(const Task& task) {
    if (size >= 100) {
        cout << "Priority queue is full.\n";
        return;
    }

    int i = size - 1;

    // Shift lower-priority tasks to the right.
    while (i >= 0 &&
           tasks[i].getPriority() > task.getPriority()) {
        tasks[i + 1] = tasks[i];
        i--;
    }

    tasks[i + 1] = task;
    size++;

    cout << "Task added to priority queue.\n";
}

bool PriorityQueue::getHighestPriorityTask(Task& result) const {
    if (size == 0) {
        cout << "Priority queue is empty.\n";
        return false;
    }

    result = tasks[0];
    return true;
}

bool PriorityQueue::removeHighestPriorityTask() {
    if (size == 0) {
        cout << "No task to remove.\n";
        return false;
    }

    for (int i = 0; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    size--;

    cout << "Highest priority task removed.\n";
    return true;
}

void PriorityQueue::displayPriorityTasks() const {
    if (size == 0) {
        cout << "No tasks in priority queue.\n";
        return;
    }

    cout << "\nTasks in Priority Order:\n";

    for (int i = 0; i < size; i++) {
        cout << "Priority: " << tasks[i].getPriority()
             << " | Task: " << tasks[i].getTitle()
             << " | Deadline: " << tasks[i].getDeadline()
             << '\n';
    }
}
