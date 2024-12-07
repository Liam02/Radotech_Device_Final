#ifndef DEVICEOVERVIEW_H
#define DEVICEOVERVIEW_H

#include <string>
using namespace std;

#include <vector>
#include "User.h"

class DeviceOverview{
private:
    vector<User*> users;


public:
    void createUser();
    bool doesUserExist(string email) const;
    void addUser(User* user);
    bool doesAUserHaveEmailAndPassword(string email, string password);
    User* getUser(string email);
    int numUsers();
    vector<User*> getUsers() const { return users; }
    void removeUser(int index);
};

#endif // DEVICEOVERVIEW_H
