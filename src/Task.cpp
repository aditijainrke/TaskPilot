#include "../include/Task.h"

Task::Task()
{
    taskId = 0;
    title = "";
    category = "";
    deadline = "";
    priority = 1;
    status = "Pending";
    recurring = false;
}

Task::Task(int id, string title, string category,
           string deadline, int priority,
           string status, bool recurring)
{
    this->taskId = id;
    this->title = title;
    this->category = category;
    this->deadline = deadline;
    this->priority = priority;
    this->status = status;
    this->recurring = recurring;
}

int Task::getId() const
{
    return taskId;
}

string Task::getTitle() const
{
    return title;
}

string Task::getCategory() const
{
    return category;
}

string Task::getDeadline() const
{
    return deadline;
}

int Task::getPriority() const
{
    return priority;
}

string Task::getStatus() const
{
    return status;
}

bool Task::isRecurring() const
{
    return recurring;
}

void Task::setPriority(int priority)
{
    this->priority = priority;
}

void Task::setStatus(string status)
{
    this->status = status;
}

void Task::setDeadline(string deadline)
{
    this->deadline = deadline;
}

void Task::setCategory(string category)
{
    this->category = category;
}

void Task::setRecurring(bool recurring)
{
    this->recurring = recurring;
}
void Task::setTitle(string title)
{
    this->title = title;
}