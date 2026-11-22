#ifndef REMINDER_STORAGE_H
#define REMINDER_STORAGE_H

#include "Reminder.h"
#include <vector>
#include <string>

class ReminderStorage {
public:
    bool saveReminder(const Reminder& reminder);
    std::vector<Reminder> loadReminders(int taskId);
    bool deleteReminder(int taskId);
};

#endif