class Task;

class ConflictManager
{
public:
    bool checkConflict(const Task& task1, const Task& task2) const;
    void findConflicts(const Task tasks[], int size) const;
};