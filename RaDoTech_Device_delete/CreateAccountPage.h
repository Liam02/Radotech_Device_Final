#ifndef CREATEACCOUNTPAGE_H
#define CREATEACCOUNTPAGE_H

#include <QDialog>

#include <regex>
#include <string>
using namespace std;

namespace Ui {
class CreateAccountPage;
}

class CreateAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccountPage(QWidget *parent = nullptr);
    ~CreateAccountPage();
    bool isValidDateOfBirth(const string& dob);
    bool isValidEmail(string email);
    void userAlreadyExist();
    void resetPage();

signals:
    void successfulAccountCreation(string firstName, string lastName, string gender, float weightKG, float heightCM, string daob, string country, string phoneNumber, string email, string password);
    void backButtonClicked();

private:
    Ui::CreateAccountPage *ui;
};

#endif // CREATEACCOUNTPAGE_H
