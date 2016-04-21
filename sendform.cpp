#include "sendform.h"
#include "ui_sendform.h"

SendForm::SendForm(SmtpClient *email,QString part, QWidget *parentForm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendForm)
{
    emailCore = email;
    ui->setupUi(this);
    this->part = part;
    this->parentForm = parentForm;
    connect(ui->sendButton,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(back()));
}

SendForm::~SendForm()
{
    delete ui;
}
void SendForm::send(){


    MimeMessage message;
    MimeHtml html;

    html.setHtml(part);
    message.setSender(new EmailAddress(emailCore->getUser(), ui->fromLineEdit->text()));
    message.addRecipient(new EmailAddress(ui->toLineEdit->text()));
    message.setSubject(ui->subjectLineEdit->text());
    //QByteArray a = part->getContent();
    message.addPart(&html);

    if (!emailCore->sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        QMessageBox::information(0, "Warning!", "You are not fill all fields!");
    } else {
        QMessageBox::information(0, "Information", "Message send succesfully!");
    }


}

void SendForm::back() {
    this->hide();
    parentForm->show();
}
