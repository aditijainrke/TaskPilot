#include "Reminder.h"

Reminder::Reminder()
    : taskId(-1), message(""), reminderDate(""), completed(false) {
}

Reminder::Reminder(
    int taskId,
    const std::string& message,
    const std::string& reminderDate
)
    : taskId(taskId),
      message(message),
      reminderDate(reminderDate),
      completed(false) {
}

int Reminder::getTaskId() const {
    return taskId;
}

std::string Reminder::getMessage() const {
    return message;
}

std::string Reminder::getReminderDate() const {
    return reminderDate;
}

bool Reminder::isCompleted() const {
    return completed;
}

void Reminder::setMessage(const std::string& message) {
    this->message = message;
}

void Reminder::setReminderDate(const std::string& reminderDate) {
    this->reminderDate = reminderDate;
}

void Reminder::markCompleted() {
    completed = true;
}