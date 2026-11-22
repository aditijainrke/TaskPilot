
#include <iostream>
#include "include/Task.h"
#include "include/PriorityQueue.h"
#include "include/ConflictManager.h"
#include "include/TaskReplanner.h"

using namespace std;

int main()
{
    // Create sample tasks
    Task t1(1, "Complete DSA", "Academic",
            "2026-10-25 10:00", 3, "Pending", false);

    Task t2(2, "Complete OOP", "Academic",
            "2026-10-25 10:00", 1, "Pending", false);

    Task t3(3, "Prepare PBL Report", "Project",
            "2026-10-26 14:00", 2, "Pending", false);

    Task tasks[3] = {t1, t2, t3};

    // =====================================
    // TEST 1: PRIORITY QUEUE
    // =====================================
    cout << "\n========== PRIORITY QUEUE ==========\n";

    PriorityQueue pq;

    pq.addTaskToPriorityQueue(t1);
    pq.addTaskToPriorityQueue(t2);
    pq.addTaskToPriorityQueue(t3);

    pq.displayPriorityTasks();

    Task highest;

    if (pq.getHighestPriorityTask(highest))
    {
        cout << "\nHighest priority task: "
             << highest.getTitle() << endl;
    }

    cout << "\nRemoving highest priority task...\n";
    pq.removeHighestPriorityTask();
    pq.displayPriorityTasks();


    // =====================================
    // TEST 2: CONFLICT DETECTION
    // =====================================
    cout << "\n========== CONFLICT DETECTION ==========\n";

    ConflictManager cm;

    if (cm.checkConflict(t1, t2))
    {
        cout << "Conflict detected between "
             << t1.getTitle() << " and "
             << t2.getTitle() << endl;
    }
    else
    {
        cout << "No conflict between these tasks.\n";
    }

    cout << "\nChecking all tasks:\n";
    cm.findConflicts(tasks, 3);


    // =====================================
    // TEST 3: TASK REPLANNING
    // =====================================
    cout << "\n========== TASK REPLANNING ==========\n";

    TaskReplanner tr;

    cout << "\nBefore replanning:\n";

    for (int i = 0; i < 3; i++)
    {
        cout << tasks[i].getTitle()
             << " | Deadline: "
             << tasks[i].getDeadline() << endl;
    }

    // Assumes your TaskReplanner interface is:
    // void replanTasks(Task tasks[], int size);
    tr.replanTasks(tasks, 3);

    cout << "\nAfter replanning:\n";

    for (int i = 0; i < 3; i++)
    {
        cout << tasks[i].getTitle()
             << " | Deadline: "
             << tasks[i].getDeadline() << endl;
    }

    cout << "\n========== TESTING COMPLETED ==========\n";

    return 0;
}
