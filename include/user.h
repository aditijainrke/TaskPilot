#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    int userId;
    string name;
    string username;
    string password;

public:
    User();

    User(int id, string name, string username, string password);

    int getUserId() const;
    string getName() const;
    string getUsername() const;
    string getPassword() const;
};

#endif