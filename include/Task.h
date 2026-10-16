#ifndef TASK_H
#define TASK_H
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

    int getId() const;
    string getTitle() const;
    string getCategory() const;
    string getDeadline() const;
    int getPriority() const;
    string getStatus() const;
    bool isRecurring() const;

    void setTitle(string title);
    void setPriority(int priority);
    void setStatus(string status);
    void setDeadline(string deadline);
    void setCategory(string category);
    void setRecurring(bool recurring);
};
#endif