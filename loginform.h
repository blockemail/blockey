#ifndef LOGINFORM_H
#define LOGINFORM_H
#include <QWidget>
#include "simpletextform.h"
#include "./src/SmtpMime"
namespace Ui{
class LoginForm;
}
class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(SmtpClient *email,QWidget *parent = 0);
    ~LoginForm();
public slots:
    void login();
private:
    SmtpClient *emailCore;
    Ui::LoginForm *ui;
};
#endif // LOGINFORM_H

