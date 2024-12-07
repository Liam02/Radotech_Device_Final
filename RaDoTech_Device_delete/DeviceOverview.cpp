#include "DeviceOverview.h"

bool DeviceOverview::doesUserExist(string email) const{
    for(int i = 0; i<int(users.size()); ++i){
        if(users[i]->getEmail()==email){
            return true;
        }
    }
    return false;
}

void DeviceOverview::addUser(User* user){
    users.push_back(user);
}

bool DeviceOverview::doesAUserHaveEmailAndPassword(string email, string password){
    for(int i = 0; i<int(users.size()); ++i){
        if(users[i]->getEmail()==email and users[i]->getPassword()==password){
            return true;
        }
    }
    return false;
}

User* DeviceOverview::getUser(string email){
    for(int i = 0; i<int(users.size()); ++i){
        if(users[i]->getEmail()==email){
            return users[i];
        }
    }
    return nullptr;
}

int DeviceOverview::numUsers(){
    return users.size();
}

void DeviceOverview::removeUser(int index) {
    if (index >= 0 && index < users.size()) {
        users.erase(users.begin() + index);
    }
}

