#include "../include/ConflictManager.h"
#include "../include/Task.h"
#include <iostream>
using namespace std;

bool ConflictManager::checkConflict(
    const Task& task1,
    const Task& task2) const
{
    return task1.getTitle() != task2.getTitle() &&
           task1.getDeadline() == task2.getDeadline();
}

void ConflictManager::findConflicts(
    const Task tasks[], int size) const
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (checkConflict(tasks[i], tasks[j]))
            {
                cout << "\nConflict detected!\n";
                cout << "Task 1: " << tasks[i].getTitle() << '\n';
                cout << "Task 2: " << tasks[j].getTitle() << '\n';
                cout << "Shared deadline: "
                     << tasks[i].getDeadline() << '\n';

                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "\nNo conflicts found.\n";
    }
}