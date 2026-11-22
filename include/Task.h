
#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
private:
    int taskId;
    std::string title;
    std::string category;
    std::string deadline;
    int priority;
    std::string status;
    bool recurring;

public:
    Task();

    Task(int id,
         std::string title,
         std::string category,
         std::string deadline,
         int priority,
         std::string status,
         bool recurring);

    int getId() const;
    std::string getTitle() const;
    std::string getCategory() const;
    std::string getDeadline() const;
    int getPriority() const;
    std::string getStatus() const;
    bool isRecurring() const;

    void setTitle(std::string title);
    void setCategory(std::string category);
    void setDeadline(std::string deadline);
    void setPriority(int priority);
    void setStatus(std::string status);
    void setRecurring(bool recurring);
};

#endif
