void ReminderSchedule::setReminder(int taskId,
                                   string reminderDateTime)
{
    reminders[taskId] = reminderDateTime;

    cout << "Reminder set successfully for Task ID: "
         << taskId << endl;
}