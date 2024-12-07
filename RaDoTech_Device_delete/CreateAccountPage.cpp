#include "CreateAccountPage.h"
#include "ui_CreateAccountPage.h"

CreateAccountPage::CreateAccountPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccountPage)
{
    ui->setupUi(this);

    connect(ui->backButton, &QPushButton::clicked, this, [=]() {emit backButtonClicked();});

    connect(ui->maleSelect, &QPushButton::clicked, this, [=](){
        if(ui->maleSelect->isChecked() and ui->femaleSelect->isChecked()){
            ui->femaleSelect->setChecked(false);
        }
    });
    connect(ui->femaleSelect, &QPushButton::clicked, this, [=](){
        if(ui->femaleSelect->isChecked() and ui->maleSelect->isChecked()){
            ui->maleSelect->setChecked(false);
        }
    });

    connect(ui->SaveAndContinue, &QPushButton::clicked, this, [=]() {
        if(ui->Weigth->text().toFloat()==0.0){
            ui->errorText->setText("Invalid weight input");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }
        else if(ui->Height->text().toFloat()==0.0){
            ui->errorText->setText("Invalid height input");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }
        else if(!isValidDateOfBirth(ui->DateOfBirth->text().toStdString())){
            ui->errorText->setText("Invalid date of birth input");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }

        else if(!isValidEmail(ui->Email->text().toStdString())){
            ui->errorText->setText("Invalid email input");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }

        else if(ui->Password->text().toStdString()!=ui->confirmPassword->text().toStdString()){
            ui->errorText->setText("Entered passwords do not match");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }

        else if(ui->FirstName->text()!="" and ui->LastName->text()!="" and (ui->maleSelect->isChecked() or ui->femaleSelect->isChecked()) and ui->Weigth->text()!=""
           and ui->Weigth->text()!="" and ui->Height->text()!="" and ui->DateOfBirth->text()!="" and ui->Country->text()!="" and ui->phoneNumber->text()!=""
           and ui->Email->text()!="" and ui->Password->text()!="" and ui->confirmPassword->text()!=""){
            emit successfulAccountCreation(ui->FirstName->text().toStdString(), ui->LastName->text().toStdString(), ui->maleSelect->isChecked() ? "male" : "female", ui->Weigth->text().toFloat(),
                                           ui->Height->text().toFloat(), ui->DateOfBirth->text().toStdString(), ui->Country->text().toStdString(), ui->phoneNumber->text().toStdString(), ui->Email->text().toStdString(), ui->Password->text().toStdString());
        }
        else{
            ui->errorText->setText("All input fields must be filled");
            ui->errorText->setStyleSheet("QLabel { color : red; }");
        }
    });
}
bool CreateAccountPage::isValidDateOfBirth(const std::string& dob) {
    std::regex dobPattern(R"((0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(1\d{3}|2\d{3}))");
    return std::regex_match(dob, dobPattern);
}

bool CreateAccountPage::isValidEmail(std::string email) {
    for(int i = 0; i<int(email.length()); ++i){
        if(email[i] == '@'){
            return true;
        }
    }
    return false;
}

void CreateAccountPage::userAlreadyExist(){
    ui->errorText->setText("User with email: (" + ui->Email->text() + ") already exist");
    ui->errorText->setStyleSheet("QLabel { color : red; }");
}

void CreateAccountPage::resetPage(){
    for (QLineEdit* lineEdit : this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
    for (QRadioButton* radioButton : this->findChildren<QRadioButton*>()) {
        radioButton->setChecked(false);
    }
    ui->errorText->clear();
}

CreateAccountPage::~CreateAccountPage()
{
    delete ui;
}
