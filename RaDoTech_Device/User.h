#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <vector>
#include "HealthMetrics.h"
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
    //vector<map<string, int>> allScans;
    //vector<vector<int>> endOfScanNotes;
    HealthMetrics userScans;

public:
    User();
    User(string firstName, string lastName, string gender, float weightKG, float heightCM, string daob, string country, string phoneNumber, string email, string password);
    ~User();
    void updateUser();
    string getEmail();
    string getPassword();
    string getFirstName();
    string getLastName();
    void addReading(map<string, int>, map<string, string>);
    void addNote(vector<int>);
    map<string, string> getAnalysis(int);
    map<string, int> getScan(int);
    vector<int> getNotes(int);
    int getScansNum();
};



#endif // USER_H


