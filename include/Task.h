#include <string>
using namespace std;

class Task
{
private:
    int taskId;
    string title;
    string category;
    string deadline;
    int priority;
    string status;
    bool recurring;

public:
    Task();

    Task(int id, string title, string category,
         string deadline, int priority,
         string status, bool recurring);

    int getId();
    string getTitle();
    string getCategory();
    string getDeadline();
    int getPriority();
    string getStatus();
    bool isRecurring();

    void setPriority(int priority);
    void setStatus(string status);
    void setDeadline(string deadline);
    void setCategory(string category);
    void setRecurring(bool recurring);
};