// DeleteProfilesPage.h
#ifndef DELETEPROFILESPAGE_H
#define DELETEPROFILESPAGE_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "User.h"
#include "DeviceOverview.h"

using namespace std;

namespace Ui {
class DeleteProfilesPage;
}

class DeleteProfilesPage : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteProfilesPage(QWidget *parent = nullptr);
    ~DeleteProfilesPage();
    void populateUserWidgets(vector<User*> users);
    QPushButton* getDeleteButton(int index) const;

signals:
    void backButtonClicked();
    void userDeleted(int index);

private slots:
    void deleteUser(int index);

private:
    void setupConnections();
    Ui::DeleteProfilesPage *ui;  // Pointer to the UI
};

#endif // DELETEPROFILESPAGE_H



