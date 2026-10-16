#ifndef USER_STORAGE_H
#define USER_STORAGE_H
#include <string>
#include <vector>
#include "User.h"

class UserStorage
{
public:
    int registerUser(const User& user);
    bool loginUser(const string& username, const string& password);
    User getUserByUsername(const string& username);
    vector<User> loadUsers();
    bool saveUser(const User& user);
};

#endif