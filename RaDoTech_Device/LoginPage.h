#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    void tooManyAccounts();


signals:
    void CreateButtonClicked();
    void EnterButtonClicked();


private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
