#include "LoginPage.h"
#include "CreateAccountPage.h"
#include "EnterAccountPage.h"
#include "HomeScreenPage.h"
#include "measuringpage.h"
#include "endofscannotes.h"

#include <QApplication>
#include "DeviceOverview.h"

#include <QDebug>

#include <string>
using namespace std;


int main(int argc, char *argv[])
{
    DeviceOverview DO;
    DO.addUser(new User("Emma", "Williams", "Female", 60.5, 165, "10-12-1995", "Canada", "+1 416-555-1234", "emma.williams@example.com", "Password123"));
    DO.addUser(new User("Liam", "Johnson", "Male", 80.2, 180, "15-03-1990", "USA", "+1 202-555-5678", "liam.johnson@example.com", "MySecretPass"));
    DO.addUser(new User("Olivia", "Brown", "Female", 55.4, 160, "22-07-1992", "Australia", "+61 3 9876 4321", "olivia.brown@example.com", "Summer2024"));
    DO.addUser(new User("Ethan", "Smith", "Male", 75.0, 175, "01-01-1988", "UK", "+44 20 7946 0701", "ethan.smith@example.com", "SecurePass456"));

    QApplication a(argc, argv);
    LoginPage *loginPage = new LoginPage();  // Create on the heap
    CreateAccountPage  *createAccountPage = new CreateAccountPage();
    EnterAccountPage *enterAccountPage = new EnterAccountPage();
    HomeScreenPage *homeScreenPage = new HomeScreenPage();
    MeasuringPage *measuringpage = new MeasuringPage();
    endOfScanNotes *endofScanPage = new endOfScanNotes();

    loginPage->show();
    //MainWindow* w = new MainWindow();

    QObject::connect(loginPage, &LoginPage::CreateButtonClicked, [loginPage, createAccountPage, &DO]() {
        if(DO.numUsers()==5){
            loginPage->tooManyAccounts();
        }
        else{
            loginPage->hide();
            createAccountPage->show();
        }
    });

    QObject::connect(createAccountPage, &CreateAccountPage::backButtonClicked, [createAccountPage, loginPage](){
        createAccountPage->hide();
        loginPage->show();
    });

    QObject::connect(createAccountPage, &CreateAccountPage::successfulAccountCreation, [createAccountPage, enterAccountPage, homeScreenPage, &DO](string firstName, string lastName,
                     string gender, float weightKG, float heightCM,
                     string daob, string country,
                     string phoneNumber, string email, string password) {
        if(DO.doesUserExist(email)){
            createAccountPage->userAlreadyExist();
        }
        else{
            User* user = new User(firstName, lastName, gender, weightKG, heightCM, daob, country, phoneNumber, email, password);
            DO.addUser(user);
            homeScreenPage->setUser(user);
            createAccountPage->resetPage();
            enterAccountPage->resetPage();
            createAccountPage->hide();
            homeScreenPage->show();
        }
    });

    QObject::connect(loginPage, &LoginPage::EnterButtonClicked, [loginPage, enterAccountPage]() {
        loginPage->hide();
        enterAccountPage->show();
    });

    QObject::connect(enterAccountPage, &EnterAccountPage::backButtonClicked, [enterAccountPage, loginPage](){
        enterAccountPage->hide();
        loginPage->show();
    });

    QObject::connect(enterAccountPage, &EnterAccountPage::signInButtonClicked, [enterAccountPage, createAccountPage, homeScreenPage, &DO](string email, string password){
        if(DO.doesAUserHaveEmailAndPassword(email, password)){
            enterAccountPage->resetPage();
            createAccountPage->resetPage();
            enterAccountPage->hide();
            homeScreenPage->setUser(DO.getUser(email));
            homeScreenPage->show();
        }
        else{
            enterAccountPage->wrongEmailOrPassword();
        }
    });

    QObject::connect(homeScreenPage, &HomeScreenPage::logoutButtonClicked, [homeScreenPage, loginPage](){
        homeScreenPage->hide();
        loginPage->show();
    });

    QObject::connect(homeScreenPage, &HomeScreenPage::measureNowButtonClicked, [homeScreenPage, measuringpage](){
       homeScreenPage->hide();
       measuringpage->show();
    });

    QObject::connect(measuringpage, &MeasuringPage::backButtonClicked, [measuringpage, homeScreenPage](){
        measuringpage->hide();
        homeScreenPage->show();
    });
    QObject::connect(measuringpage, &MeasuringPage::sendReadingToUser, [measuringpage, createAccountPage, enterAccountPage, homeScreenPage, &DO](map<string, int> scan, map<string, string> analysis) {
        homeScreenPage->setaNewReading(scan, analysis);
    });

    QObject::connect(measuringpage, &MeasuringPage::saveButtonClicked, [measuringpage, endofScanPage](){
       measuringpage->hide();
       endofScanPage->show();
    });
    QObject::connect(endofScanPage, &endOfScanNotes::sendNotesToUser, [endofScanPage,homeScreenPage](int a, int b, int c, int d, int e, int f, int g) {
        homeScreenPage->addEndOfScan(a,b,c,d,e,f,g);
        endofScanPage->hide();
        homeScreenPage->show();
    });
    return a.exec();
}
