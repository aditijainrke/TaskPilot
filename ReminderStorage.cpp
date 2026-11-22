#include "ReminderStorage.h"
#include <fstream>
#include <sstream>
#include <cstdio>

bool ReminderStorage::saveReminder(const Reminder& reminder) {
    std::ofstream file("reminders.csv", std::ios::app);

    if (!file.is_open()) {
        return false;
    }

    file << reminder.getTaskId() << ","
         << reminder.getMessage() << ","
         << reminder.getReminderDate() << ","
         << (reminder.isCompleted() ? 1 : 0) << "\n";

    return file.good();
}

std::vector<Reminder> ReminderStorage::loadReminders(int taskId) {
    std::vector<Reminder> reminders;
    std::ifstream file("reminders.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, message, date, completed;

        if (!std::getline(ss, id, ',') ||
            !std::getline(ss, message, ',') ||
            !std::getline(ss, date, ',') ||
            !std::getline(ss, completed, ',')) {
            continue;
        }

        try {
            int storedTaskId = std::stoi(id);

            if (storedTaskId == taskId) {
                Reminder reminder(storedTaskId, message, date);

                if (completed == "1") {
                    reminder.markCompleted();
                }

                reminders.push_back(reminder);
            }
        } catch (...) {
            continue;
        }
    }

    return reminders;
}

bool ReminderStorage::deleteReminder(int taskId) {
    std::ifstream input("reminders.csv");

    if (!input.is_open()) {
        return false;
    }

    std::ofstream output("reminders_temp.csv");

    if (!output.is_open()) {
        return false;
    }

    std::string line;

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string id;

        if (!std::getline(ss, id, ',')) {
            continue;
        }

        try {
            if (std::stoi(id) != taskId) {
                output << line << "\n";
            }
        } catch (...) {
            output << line << "\n";
        }
    }

    input.close();
    output.close();

    if (std::remove("reminders.csv") != 0) {
        return false;
    }

    return std::rename("reminders_temp.csv", "reminders.csv") == 0;
}