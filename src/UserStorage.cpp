#include "../include/UserStorage.h"
#include <fstream>
#include <sstream>

vector<User> UserStorage::loadUsers()
{
    vector<User> users;
    ifstream file("users.csv");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, username, password;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');

        if (!id.empty())
        {
            users.push_back(User(stoi(id), name, username, password));
        }
    }

    file.close();
    return users;
}

bool UserStorage::saveUser(const User& user)
{
    ofstream file("users.csv", ios::app);

    if (!file.is_open())
        return false;

    file << user.getUserId() << ","
         << user.getName() << ","
         << user.getUsername() << ","
         << user.getPassword() << "\n";

    file.close();
    return true;
}


int UserStorage::registerUser(const User& user)
{
    vector<User> users = loadUsers();

    for (const User& existingUser : users)
    {
        if (existingUser.getUsername() == user.getUsername())
            return -1;
    }

    int newId = 1;

    for (const User& existingUser : users)
    {
        if (existingUser.getUserId() >= newId)
            newId = existingUser.getUserId() + 1;
    }

    User newUser(
        newId,
        user.getName(),
        user.getUsername(),
        user.getPassword()
    );

    if (saveUser(newUser))
        return newId;

    return -1;
}


bool UserStorage::loginUser(const string& username, const string& password)
{
    vector<User> users = loadUsers();

    for (const User& user : users)
    {
        if (user.getUsername() == username &&
            user.getPassword() == password)
        {
            return true;
        }
    }

    return false;
}

User UserStorage::getUserByUsername(const string& username)
{
    vector<User> users = loadUsers();

    for (const User& user : users)
    {
        if (user.getUsername() == username)
            return user;
    }

    return User();
}
