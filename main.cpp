#include "mainwindow.h"
#include "smtpmime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    SmtpClient smtp("smtp.gmail.com",465);

    smtp.connectToHost();
    smtp.login("HtmlBlockEditor@gmail.com","htmlBLOCK");

    MimeMessage message;

    message.setSender(new EmailAddress("HtmlBlockEditor@gmail.com","BlockEditor"));
    message.addRecipient(new EmailAddress("ebc9af@mailinator.com","sup"));
    message.setSubject("First message");

    MimeText text;
    text.setText("sup mailinator");

    message.addPart(&text);
    smtp.sendMail(message);
    smtp.quit();

    return a.exec();
}
