
#include <iostream>
#include <string>
#include "include/Task.h"
#include "include/User.h"
#include "include/UserStorage.h"
#include "include/TaskStorage.h"

using namespace std;

int main()
{
    UserStorage userStorage;
    TaskStorage taskStorage;
    int choice;

    do
    {
        cout << "\n===== TaskPilot =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            string name, username, password;

            cout << "Enter your name: ";
            getline(cin, name);

           cout << "Choose a username: ";
           getline(cin, username);

           while (username.empty() ||
           username.find(' ') != string::npos)
        {
           cout << "Username cannot be empty or contain spaces. "
           << "Please try again: ";
           getline(cin, username);
        }

            cout << "Choose a password: ";
            getline(cin, password);

            User newUser(0, name, username, password);
            int userId = userStorage.registerUser(newUser);

            if (userId != -1)
                cout << "Registration successful! Your user ID is "
                     << userId << "." << endl;
            else
                cout << "Registration failed. Username may already exist."
                     << endl;
        }
        else if (choice == 2)
        {
            string username, password;

            cout << "Username: ";
            getline(cin, username);

            cout << "Password: ";
            getline(cin, password);

            if (userStorage.loginUser(username, password))
            {
                User currentUser =
                    userStorage.getUserByUsername(username);

                cout << "\nLogin successful! Welcome, "
                     << currentUser.getName() << "." << endl;
                     int taskChoice;

do
{
    cout << "\n===== Task Menu =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View My Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout <<"4. Edit Task" << endl;
    cout << "5. Logout" << endl;
    cout << "Enter your choice: ";
    cin >> taskChoice;
    cin.ignore(10000, '\n');

    if (taskChoice == 1)
    {
        int taskId, priority;
        string title, category, deadline, status;
        char recurringChoice;

        cout << "Enter Task ID: ";
        cin >> taskId;
        cin.ignore(10000, '\n');

       cout << "Enter title: ";
       getline(cin, title);

       while (title.empty())
   {
       cout << "Title cannot be empty. Enter title: ";
       getline(cin, title);
    }

        cout << "Enter category: ";
        getline(cin, category);

        cout << "Enter deadline: ";
        getline(cin, deadline);

        cout << "Enter priority (1-5): ";
        cin >> priority;

        while (cin.fail() || priority < 1 || priority > 5)
{
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Invalid priority! Enter a number between 1 and 5: ";
        cin >> priority;
}
        

        cout << "Enter status (Pending/In Progress/Completed): ";
        getline(cin, status);

        cout << "Is this a recurring task? (y/n): ";
        cin >> recurringChoice;
        cin.ignore(10000, '\n');

        Task newTask(
            taskId,
            title,
            category,
            deadline,
            priority,
            status,
            recurringChoice == 'y' || recurringChoice == 'Y'
        );

        if (taskStorage.saveTask(currentUser.getUserId(), newTask))
        {
            cout << "Task saved successfully!" << endl;
        }
        else
        {
            cout << "Unable to save task." << endl;
        }
    }
    else if (taskChoice == 2)
    {
        vector<Task> tasks =
            taskStorage.loadTasks(currentUser.getUserId());

        if (tasks.empty())
        {
            cout << "You have no saved tasks yet." << endl;
        }
        else
        {
            for (const Task& task : tasks)
            {
                cout << "\nTask ID: " << task.getId() << endl;
                cout << "Title: " << task.getTitle() << endl;
                cout << "Category: " << task.getCategory() << endl;
                cout << "Deadline: " << task.getDeadline() << endl;
                cout << "Priority: " << task.getPriority() << endl;
                cout << "Status: " << task.getStatus() << endl;
                cout << "Recurring: " << task.isRecurring() << endl;
            }
        }
    }
    else if (taskChoice == 4)
{
    int taskId;

    cout << "Enter Task ID to edit: ";
    cin >> taskId;
    cin.ignore(10000, '\n');

    vector<Task> tasks =
        taskStorage.loadTasks(currentUser.getUserId());

    bool found = false;

    for (Task task : tasks)
    {
        if (task.getId() == taskId)
        {
            string title, category, deadline, status;
            int priority;
            char recurringChoice;

            cout << "Enter new title: ";
            getline(cin, title);

            cout << "Enter new category: ";
            getline(cin, category);

            cout << "Enter new deadline: ";
            getline(cin, deadline);

            cout << "Enter new priority (1-5): ";
            cin >> priority;
            cin.ignore(10000, '\n');

            cout << "Enter new status: ";
            getline(cin, status);

            cout << "Recurring task? (y/n): ";
            cin >> recurringChoice;
            cin.ignore(10000, '\n');

            task.setTitle(title);
            task.setCategory(category);
            task.setDeadline(deadline);
            task.setPriority(priority);
            task.setStatus(status);
            task.setRecurring(
                recurringChoice == 'y' ||
                recurringChoice == 'Y'
            );

            if (taskStorage.updateTask(
                    currentUser.getUserId(), task))
            {
                cout << "Task updated successfully!" << endl;
            }
            else
            {
                cout << "Unable to update task." << endl;
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Task not found." << endl;
    }
}
    else if (taskChoice == 3)
{
    int taskId;

    cout << "Enter Task ID to delete: ";
    cin >> taskId;

    if (taskStorage.deleteTask(currentUser.getUserId(), taskId))
        cout << "Task deleted successfully!" << endl;
    else
        cout << "Task not found or could not be deleted." << endl;
}
else if (taskChoice == 5)
{
    cout << "Invalid choice. Try again." << endl;
}

} while (taskChoice != 5);

                vector<Task> tasks =
                    taskStorage.loadTasks(currentUser.getUserId());

                if (tasks.empty())
                {
                    cout << "You have no saved tasks yet." << endl;
                }
                else
                {
                    cout << "\n===== Your Tasks =====" << endl;

                    for (const Task& task : tasks)
                    {
                        cout << "\nTask ID: " << task.getId() << endl;
                        cout << "Title: " << task.getTitle() << endl;
                        cout << "Category: " << task.getCategory() << endl;
                        cout << "Deadline: " << task.getDeadline() << endl;
                        cout << "Priority: " << task.getPriority() << endl;
                        cout << "Status: " << task.getStatus() << endl;
                        cout << "Recurring: "
                             << task.isRecurring() << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
        }
        else if (choice != 3)
        {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 3);

    cout << "Thank you for using TaskPilot!" << endl;
    return 0;
}
