#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <string>

namespace Ui{
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);

    ~LoginWindow();

public slots:
    void login();
private:
    Ui::LoginWindow *ui;
    QLineEdit *pUserLineEdit;
    QLineEdit *pPasswordLineEdit;
    QPushButton *pLoginButton;
    QFormLayout *pLayout;
};

#endif // LOGINWINDOW_H
