#ifndef REMINDER_H
#define REMINDER_H

#include <string>

class Reminder {
private:
    int taskId;
    std::string message;
    std::string reminderDate;
    bool completed;

public:
    Reminder();
    Reminder(int taskId, const std::string& message,
             const std::string& reminderDate);

    int getTaskId() const;
    std::string getMessage() const;
    std::string getReminderDate() const;
    bool isCompleted() const;

    void setMessage(const std::string& message);
    void setReminderDate(const std::string& reminderDate);
    void markCompleted();
};

#endif