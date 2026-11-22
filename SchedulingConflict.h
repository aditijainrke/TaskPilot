
#ifndef SCHEDULING_CONFLICT_H
#define SCHEDULING_CONFLICT_H

#include <string>

class SchedulingConflict
{
private:
    int firstTaskId;
    int secondTaskId;
    std::string sharedDeadline;
    std::string description;

public:
    SchedulingConflict();

    SchedulingConflict(
        int firstId,
        int secondId,
        std::string deadline,
        std::string description
    );

    int getFirstTaskId() const;
    int getSecondTaskId() const;

    std::string getSharedDeadline() const;
    std::string getDescription() const;
};

#endif
