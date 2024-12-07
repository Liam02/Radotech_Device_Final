#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{

private:
    string firstName;
    string lastName;
    string gender;
    float weightKG;
    float heightCM;
    string daob;
    string country;
    string phoneNumber;
    string email;
    string password;


public:
    User();
    User(string firstName, string lastName, string gender, float weightKG, float heightCM, string daob, string country, string phoneNumber, string email, string password);
    ~User();
    void updateUser();
    string getEmail();
    string getPassword();
    string getFirstName();
    string getLastName();
};



#endif // USER_H


