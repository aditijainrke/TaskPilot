#include "ReminderManager.h"
#include <iostream>
#include <algorithm>

bool ReminderManager::addReminder(const Reminder& reminder) {
    if (reminder.getMessage().empty() ||
        reminder.getReminderDate().empty()) {
        return false;
    }

    if (!storage.saveReminder(reminder)) {
        return false;
    }

    reminders.push_back(reminder);
    return true;
}

std::vector<Reminder> ReminderManager::getReminders(int taskId) {
    return storage.loadReminders(taskId);
}

bool ReminderManager::deleteReminders(int taskId) {
    if (!storage.deleteReminder(taskId)) {
        return false;
    }

    reminders.erase(
        std::remove_if(
            reminders.begin(),
            reminders.end(),
            [taskId](const Reminder& reminder) {
                return reminder.getTaskId() == taskId;
            }
        ),
        reminders.end()
    );

    return true;
}

void ReminderManager::displayReminders(int taskId) {
    std::vector<Reminder> taskReminders = getReminders(taskId);

    std::cout << "\n--- Reminders for Task "
              << taskId << " ---\n";

    if (taskReminders.empty()) {
        std::cout << "No reminders found.\n";
        return;
    }

    for (const auto& reminder : taskReminders) {
        std::cout << "Message: " << reminder.getMessage()
                  << " | Date: " << reminder.getReminderDate()
                  << " | Status: "
                  << (reminder.isCompleted() ? "Completed" : "Pending")
                  << '\n';
    }
}

bool ReminderManager::hasDueReminder(
    int taskId,
    const std::string& currentDate
) {
    std::vector<Reminder> taskReminders = getReminders(taskId);

    for (const auto& reminder : taskReminders) {
        if (!reminder.isCompleted() &&
            reminder.getReminderDate() <= currentDate) {
            return true;
        }
    }

    return false;
}