
#include "../include/TaskStorage.h"
#include <fstream>
#include <sstream>
#include <string>

vector<Task> TaskStorage::loadTasks(int userId)
{
    vector<Task> tasks;
    ifstream file("tasks.csv");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string ownerId, taskId, title, category;
        string deadline, priority, status, recurring;

        getline(ss, ownerId, ',');
        getline(ss, taskId, ',');
        getline(ss, title, ',');
        getline(ss, category, ',');
        getline(ss, deadline, ',');
        getline(ss, priority, ',');
        getline(ss, status, ',');
        getline(ss, recurring, ',');

        if (!ownerId.empty() && stoi(ownerId) == userId)
        {
            tasks.push_back(Task(
                stoi(taskId),
                title,
                category,
                deadline,
                stoi(priority),
                status,
                recurring == "1"
            ));
        }
    }

    file.close();
    return tasks;
}

bool TaskStorage::saveTask(int userId, const Task& task)
{
    ofstream file("tasks.csv", ios::app);

    if (!file.is_open())
        return false;

    file << userId << ","
         << task.getId() << ","
         << task.getTitle() << ","
         << task.getCategory() << ","
         << task.getDeadline() << ","
         << task.getPriority() << ","
         << task.getStatus() << ","
         << (task.isRecurring() ? 1 : 0)
         << "\n";

    file.close();
    return true;
}
bool TaskStorage::deleteTask(int userId, int taskId)
{
    vector<Task> tasks = loadTasks(userId);
    bool found = false;

    for (const Task& task : tasks)
    {
        if (task.getId() == taskId)
        {
            found = true;
            break;
        }
    }

    if (!found)
        return false;

    ifstream inFile("tasks.csv");
    ofstream outFile("tasks_temp.csv");

    if (!inFile.is_open() || !outFile.is_open())
        return false;

    string line;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string ownerId, storedTaskId;

        getline(ss, ownerId, ',');
        getline(ss, storedTaskId, ',');

        if (ownerId == to_string(userId) &&
            storedTaskId == to_string(taskId))
        {
            continue;
        }

        outFile << line << '\n';
    }

    inFile.close();
    outFile.close();

    if (remove("tasks.csv") != 0)
        return false;

    if (rename("tasks_temp.csv", "tasks.csv") != 0)
        return false;

    return true;
}
bool TaskStorage::updateTask(int userId, const Task& updatedTask)
{
    vector<Task> tasks = loadTasks(userId);
    bool found = false;

    for (Task& task : tasks)
    {
        if (task.getId() == updatedTask.getId())
        {
            task = updatedTask;
            found = true;
            break;
        }
    }

    if (!found)
        return false;

    ifstream inFile("tasks.csv");
    ofstream outFile("tasks_temp.csv");

    if (!inFile.is_open() || !outFile.is_open())
        return false;

    string line;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string ownerId, storedTaskId;

        getline(ss, ownerId, ',');
        getline(ss, storedTaskId, ',');

        if (ownerId == to_string(userId) &&
            storedTaskId == to_string(updatedTask.getId()))
        {
            outFile << userId << ","
                    << updatedTask.getId() << ","
                    << updatedTask.getTitle() << ","
                    << updatedTask.getCategory() << ","
                    << updatedTask.getDeadline() << ","
                    << updatedTask.getPriority() << ","
                    << updatedTask.getStatus() << ","
                    << (updatedTask.isRecurring() ? 1 : 0)
                    << '\n';
        }
        else
        {
            outFile << line << '\n';
        }
    }

    inFile.close();
    outFile.close();

    if (remove("tasks.csv") != 0)
        return false;

    if (rename("tasks_temp.csv", "tasks.csv") != 0)
        return false;

    return true;
}