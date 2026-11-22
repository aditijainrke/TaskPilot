#include "../include/ConflictManager.h"
#include <iostream>

bool ConflictManager::checkConflict(
    const Task& task1,
    const Task& task2) const
{
    return task1.getTitle() != task2.getTitle() &&
           task1.getDeadline() == task2.getDeadline();
}

std::vector<SchedulingConflict> ConflictManager::getConflicts(
    const std::vector<Task>& tasks) const
{
    std::vector<SchedulingConflict> conflicts;

    for (int i = 0; i < static_cast<int>(tasks.size()); i++)
    {
        for (int j = i + 1; j < static_cast<int>(tasks.size()); j++)
        {
            if (checkConflict(tasks[i], tasks[j]))
            {
                SchedulingConflict conflict(
                    tasks[i].getId(),
                    tasks[j].getId(),
                    tasks[i].getDeadline(),
                    "Two different tasks have the same deadline."
                );

                conflicts.push_back(conflict);
            }
        }
    }

    return conflicts;
}

void ConflictManager::findConflicts(
    const Task tasks[],
    int size) const
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (checkConflict(tasks[i], tasks[j]))
            {
                std::cout << "\nConflict detected!\n";

                std::cout << "Task 1: "
                          << tasks[i].getTitle() << '\n';

                std::cout << "Task 2: "
                          << tasks[j].getTitle() << '\n';

                std::cout << "Shared deadline: "
                          << tasks[i].getDeadline() << '\n';

                found = true;
            }
        }
    }

    if (!found)
    {
        std::cout << "\nNo conflicts found.\n";
    }
}
