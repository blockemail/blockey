#include "simpletextform.h"
#include "ui_simpletextform.h"

SimpleTextForm::SimpleTextForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleTextForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->sendButton,SIGNAL(clicked(bool)),this,SLOT(send()));
}

SimpleTextForm::~SimpleTextForm()
{
    delete ui;
}
void SimpleTextForm::send(){

    MimeMessage message;
    EmailAddress sender(emailCore->getUser(), "Your Name");
    message.setSender(&sender);
    EmailAddress to(ui->recepientLineEdit->text(),"sup");
    message.addRecipient(&to);
    message.setSubject("Demo");
    MimeText text;
    text.setText(ui->plainTextEdit->toPlainText());
    message.addPart(&text);

    if (!emailCore->sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
    } else {
        QMessageBox::information(0, "Information", "Message send succesfully!");
    }

}
