#include "../include/Task.h"

// Default constructor
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

// Parameterized constructor
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

// Getters

int Task::getId()
{
    return taskId;
}

string Task::getTitle()
{
    return title;
}

string Task::getCategory()
{
    return category;
}

string Task::getDeadline()
{
    return deadline;
}

int Task::getPriority()
{
    return priority;
}

string Task::getStatus()
{
    return status;
}

bool Task::isRecurring()
{
    return recurring;
}

// Setters

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