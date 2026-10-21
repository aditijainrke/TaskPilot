bool ReminderSchedule::isReminderDue(
    int taskId, string currentDateTime)
{
    map<int, string>::iterator it = reminders.find(taskId);

    if (it == reminders.end())
        return false;

    return it->second <= currentDateTime;
}