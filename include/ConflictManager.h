
#ifndef CONFLICT_MANAGER_H
#define CONFLICT_MANAGER_H

#include "Task.h"
#include "SchedulingConflict.h"
#include <vector>

class ConflictManager
{
public:
    bool checkConflict(
        const Task& task1,
        const Task& task2
    ) const;

    void findConflicts(
        const Task tasks[],
        int size
    ) const;

    std::vector<SchedulingConflict> getConflicts(
        const std::vector<Task>& tasks
    ) const;
};

#endif
