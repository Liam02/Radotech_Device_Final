#ifndef HOMESCREENPAGE_H
#define HOMESCREENPAGE_H

#include "User.h"
#include "Battery.h"
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
    void setBattery(Battery* battery);

public slots:
    void handleBattery();

signals:
    void logoutButtonClicked();

private:
    Ui::HomeScreenPage *ui;
    User* user = new User();

    Battery* battery;

};

#endif // HOMESCREENPAGE_H
