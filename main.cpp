#include <iostream>
#include "include/Task.h"

using namespace std;

int main()
{
    Task task(
        101,
        "Complete DSA assignment",
        "Academic",
        "10/10/2026",
        5,
        "Pending",
        false
    );

    cout << "Task ID: " << task.getId() << endl;
    cout << "Title: " << task.getTitle() << endl;
    cout << "Category: " << task.getCategory() << endl;
    cout << "Deadline: " << task.getDeadline() << endl;
    cout << "Priority: " << task.getPriority() << endl;
    cout << "Status: " << task.getStatus() << endl;

    return 0;
}