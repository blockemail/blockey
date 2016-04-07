#include "loginform.h"
#include <QApplication>
#include "./src/SmtpMime"
void cont(SmtpClient *cl);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    LoginForm login(&smtp);
    login.show();

    return a.exec();


}
