#ifndef REMINDER_MANAGER_H
#define REMINDER_MANAGER_H

#include "Reminder.h"
#include "ReminderStorage.h"
#include <vector>
#include <string>

class ReminderManager {
private:
    ReminderStorage storage;
    std::vector<Reminder> reminders;

public:
    bool addReminder(const Reminder& reminder);
    std::vector<Reminder> getReminders(int taskId);
    bool deleteReminders(int taskId);
    void displayReminders(int taskId);
    bool hasDueReminder(int taskId, const std::string& currentDate);
};

#endif