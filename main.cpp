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
void cont(SmtpClient *smtp){


    smtp->setUser("htmlblockeditor@gmail.com");
    smtp->setPassword("blockemail1234");

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender("your_email_address@host.com", "Your Name");
    message.setSender(&sender);

    EmailAddress to("blockemail@mailinator.com", "Recipient's Name");
    message.addRecipient(&to);

    message.setSubject("SmtpClient for Qt - Demo");

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText("Hi,\nThis is a simple 2 email message.\n");

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    if (!smtp->connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
        //return -1;
    }

    if (!smtp->login()) {
        qDebug() << "Failed to login!" << endl;
        //return -2;
    }

    if (!smtp->sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        //return -3;
    }

    smtp->quit();

}
