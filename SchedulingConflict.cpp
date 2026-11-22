
#include "../include/SchedulingConflict.h"

SchedulingConflict::SchedulingConflict()
{
    firstTaskId = 0;
    secondTaskId = 0;
    sharedDeadline = "";
    description = "";
}

SchedulingConflict::SchedulingConflict(
    int firstId,
    int secondId,
    std::string deadline,
    std::string description)
{
    firstTaskId = firstId;
    secondTaskId = secondId;
    sharedDeadline = deadline;
    this->description = description;
}

int SchedulingConflict::getFirstTaskId() const
{
    return firstTaskId;
}

int SchedulingConflict::getSecondTaskId() const
{
    return secondTaskId;
}

std::string SchedulingConflict::getSharedDeadline() const
{
    return sharedDeadline;
}

std::string SchedulingConflict::getDescription() const
{
    return description;
}
