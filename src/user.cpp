#include "../include/User.h"

User::User()
{
    userId = 0;
    name = "";
    username = "";
    password = "";
}

User::User(int id, string name, string username, string password)
{
    userId = id;
    this->name = name;
    this->username = username;
    this->password = password;
}

int User::getUserId() const
{
    return userId;
}

string User::getName() const
{
    return name;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}