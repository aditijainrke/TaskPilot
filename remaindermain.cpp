#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

// Task class
class Task
{
private:
    int taskId;
    string title, category, deadline, status;
    int priority;
    bool recurring;

public:
    Task() : taskId(0), status("Pending"), priority(1),
             recurring(false) {}

    Task(int id, const string& t, const string& c, const string& d,
         int p, const string& s, bool r)
        : taskId(id), title(t), category(c), deadline(d),
          status(s), priority(p), recurring(r) {}

    int getId() const { return taskId; }
    string getTitle() const { return title; }
    string getCategory() const { return category; }
    string getDeadline() const { return deadline; }
    int getPriority() const { return priority; }
    string getStatus() const { return status; }
    bool isRecurring() const { return recurring; }

    void setPriority(int p) { priority = p; }
    void setStatus(const string& s) { status = s; }
    void setDeadline(const string& d) { deadline = d; }
    void setCategory(const string& c) { category = c; }
    void setRecurring(bool r) { recurring = r; }
};

// ReminderSchedule class
class ReminderSchedule
{
private:
    map<int, string> reminders;
    vector<Task> schedule;

public:
    void setReminder(int taskId, const string& reminderDateTime)
    {
        reminders[taskId] = reminderDateTime;
    }

    bool isReminderDue(int taskId, const string& currentDateTime) const
    {
        map<int, string>::const_iterator it = reminders.find(taskId);

        if (it == reminders.end())
            return false;

        return it->second <= currentDateTime;
    }

    void showReminders() const
    {
        for (map<int, string>::const_iterator it = reminders.begin();
             it != reminders.end(); ++it)
        {
            cout << "Task ID: " << it->first
                 << ", Reminder: " << it->second << endl;
        }
    }

    void generateSchedule(const vector<Task>& tasks)
    {
        schedule = tasks;

        for (int i = 1; i < (int)schedule.size(); i++)
        {
            Task current = schedule[i];
            int j = i - 1;

            while (j >= 0 &&
                   (schedule[j].getPriority() < current.getPriority() ||
                    (schedule[j].getPriority() == current.getPriority() &&
                     schedule[j].getDeadline() > current.getDeadline())))
            {
                schedule[j + 1] = schedule[j];
                j--;
            }

            schedule[j + 1] = current;
        }
    }

    void displaySchedule() const
    {
        for (int i = 0; i < (int)schedule.size(); i++)
        {
            cout << "\nTask ID: " << schedule[i].getId()
                 << "\nTitle: " << schedule[i].getTitle()
                 << "\nPriority: " << schedule[i].getPriority()
                 << "\nStatus: " << schedule[i].getStatus()
                 << "\n";
        }
    }

    int calculateTaskLoad(const vector<Task>& tasks) const
    {
        int count = 0;

        for (int i = 0; i < (int)tasks.size(); i++)
        {
            if (tasks[i].getStatus() != "Completed")
                count++;
        }

        return count;
    }

    void reviewTaskLoad(const vector<Task>& tasks) const
    {
        cout << "\nIncomplete tasks: "
             << calculateTaskLoad(tasks) << endl;
    }
};

// Main function
int main()
{
    Task t1(101, "DSA Assignment", "Academic",
            "2026-10-22 18:00", 5, "Pending", false);

    Task t2(102, "Project Report", "Project",
            "2026-10-23 12:00", 3, "Pending", false);

    vector<Task> tasks;
    tasks.push_back(t1);
    tasks.push_back(t2);

    ReminderSchedule rs;

    rs.setReminder(101, "2026-10-22 17:00");

    cout << "REMINDERS\n";
    rs.showReminders();

    if (rs.isReminderDue(101, "2026-10-22 18:00"))
        cout << "\nReminder is due.\n";
    else
        cout << "\nReminder is not due.\n";

    rs.generateSchedule(tasks);

    cout << "\nTASK SCHEDULE\n";
    rs.displaySchedule();

    rs.reviewTaskLoad(tasks);

    return 0;
}
