#include "User.h"

User::User(){
    this->firstName = "";
    this->lastName = "";
    this->gender = "";
    this->weightKG = 0.0;
    this->heightCM = 0.0;
    this->daob = "";
    this->country = "";
    this->phoneNumber = "";
    this->email = "";
    this->password = "";
}

User::User(string firstName, string lastName, string gender, float weightKG, float heightCM, string daob, string country, string phoneNumber, string email, string password){
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->weightKG = weightKG;
    this->heightCM = heightCM;
    this->daob = daob;
    this->country = country;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->password = password;
}

User::~User(){
    delete this;
}

void User::updateUser(){

}

string User::getEmail(){
    return this->email;
}

string User::getPassword(){
    return this->password;
}

string User::getFirstName(){
    return this->firstName;
}
string User::getLastName(){
    return this->lastName;
}
