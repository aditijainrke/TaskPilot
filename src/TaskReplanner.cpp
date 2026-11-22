
#include "../include/TaskReplanner.h"
#include "../include/Task.h"
#include "../include/ConflictManager.h"
#include <iostream>

using namespace std;

void TaskReplanner::replanTasks(Task tasks[], int size)
{
    if (size <= 0)
    {
        cout << "No tasks available for replanning.\n";
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tasks[i].getPriority() > tasks[j].getPriority())
            {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    cout << "\nTasks sorted by priority for replanning:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Task: " << tasks[i].getTitle()
             << " | Priority: " << tasks[i].getPriority()
             << " | Deadline: " << tasks[i].getDeadline()
             << '\n';
    }

    ConflictManager manager;
    bool conflictFound = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (manager.checkConflict(tasks[i], tasks[j]))
            {
                cout << "\nConflict detected!\n";

                cout << "Task 1: "
                     << tasks[i].getTitle() << '\n';

                cout << "Task 2: "
                     << tasks[j].getTitle() << '\n';

                cout << "Shared deadline: "
                     << tasks[i].getDeadline() << '\n';

                cout << "Higher-priority task: "
                     << tasks[i].getTitle() << '\n';

                cout << "Consider rescheduling: "
                     << tasks[j].getTitle() << '\n';

                conflictFound = true;
            }
        }
    }

    if (!conflictFound)
    {
        cout << "\nNo conflicts found. "
             << "No replanning required.\n";
    }
    else
    {
        cout << "\nReplanning analysis completed.\n";
        cout << "Review the suggested tasks for rescheduling.\n";
    }
}
