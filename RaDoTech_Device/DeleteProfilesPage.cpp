#include "DeleteProfilesPage.h"
#include "ui_DeleteProfilesPage.h"
#include <QDebug>
#include <QMessageBox>
using namespace std;

DeleteProfilesPage::DeleteProfilesPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProfilesPage)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &DeleteProfilesPage::backButtonClicked);
    setupConnections();

}

DeleteProfilesPage::~DeleteProfilesPage()
{
    delete ui;
}

void DeleteProfilesPage::populateUserWidgets(vector<User*> users) {
    QList<QLabel*> userLabels = {ui->user_1, ui->user_2, ui->user_3, ui->user_4, ui->user_5};
    QList<QPushButton*> deleteButtons = {ui->DeleteProfile_1, ui->DeleteProfile_2, ui->DeleteProfile_3, ui->DeleteProfile_4, ui->DeleteProfile_5};

    for (int i = 0; i < 5; ++i) {
        userLabels[i]->setVisible(false);
        deleteButtons[i]->setVisible(false);
    }

    for (int i = 0; i < users.size(); ++i) {
        QString userInfo = QString::fromStdString(users[i]->getFirstName() + " " + users[i]->getLastName());
        userLabels[i]->setText(userInfo);
        userLabels[i]->setVisible(true);
        deleteButtons[i]->setVisible(true);
    }
}

void DeleteProfilesPage::deleteUser(int index) {
    QList<QLabel*> userLabels = {ui->user_1, ui->user_2, ui->user_3, ui->user_4, ui->user_5};
    QList<QPushButton*> deleteButtons = {ui->DeleteProfile_1, ui->DeleteProfile_2, ui->DeleteProfile_3, ui->DeleteProfile_4, ui->DeleteProfile_5};

    if (!userLabels[index]->text().isEmpty()) {
        QString userName = userLabels[index]->text();
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Delete User", "Are you sure you want to delete " + userName + "?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            userLabels[index]->setVisible(false);
            deleteButtons[index]->setVisible(false);

            emit userDeleted(index);
        }
    }

}

void DeleteProfilesPage::setupConnections() {
    QList<QPushButton*> deleteButtons = {ui->DeleteProfile_1, ui->DeleteProfile_2, ui->DeleteProfile_3, ui->DeleteProfile_4, ui->DeleteProfile_5};

    for (int i = 0; i < deleteButtons.size(); ++i) {
        connect(deleteButtons[i], &QPushButton::clicked, this, [this, i]() {
            this->deleteUser(i);
        });
    }
}

QPushButton* DeleteProfilesPage::getDeleteButton(int index) const {
    switch (index) {
        case 0: return ui->DeleteProfile_1;
        case 1: return ui->DeleteProfile_2;
        case 2: return ui->DeleteProfile_3;
        case 3: return ui->DeleteProfile_4;
        case 4: return ui->DeleteProfile_5;
        default: return nullptr;
    }
}

