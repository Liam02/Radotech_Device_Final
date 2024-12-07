#ifndef HOMESCREENPAGE_H
#define HOMESCREENPAGE_H

#include "User.h"
#include <QDialog>
#include <QString>
#include <QTimer>

namespace Ui {
class HomeScreenPage;
}

class HomeScreenPage : public QDialog
{
    Q_OBJECT

public:
    explicit HomeScreenPage(QWidget *parent = nullptr);
    ~HomeScreenPage();
    void setUser(User* user);
    User* getUser();

signals:
    void logoutButtonClicked();
    void deleteProfilesButtonClicked();

private:
    Ui::HomeScreenPage *ui;
    User* user = new User();

};

#endif // HOMESCREENPAGE_H
