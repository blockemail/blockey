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
    /*
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("htmlblockeditor@gmail.com");
    smtp.setPassword("blockemail1234");

    // Create a MimeMessage

    MimeMessage message;

    message.setSender(new EmailAddress("htmlblockeditor@gmail.com", "Your Name"));
    message.addRecipient(new EmailAddress("blockemail@mailinator.com", "Recipient's Name"));
    message.setSubject("SmtpClient for Qt - Example 3 - Html email with images");


    // Now we need to create a MimeHtml object for HTML content
    MimeHtml html;

    html.setHtml("<h1> Hello! </h1>"
                 "<h2> This is the first image </h2>"
                 "<img src='cid:image1' />"
                 "<h2> This is the second image </h2>"
                 "<img src='cid:image2' />");



    message.addPart(&html);

    // Now the email can be sended

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
*/
    return a.exec();


}
