#include "simpletextform.h"
#include "ui_simpletextform.h"

SimpleTextForm::SimpleTextForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleTextForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->sendButton,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(back()));
}

SimpleTextForm::~SimpleTextForm()
{
    delete ui;
}
void SimpleTextForm::send(){

    MimeMessage message;
    EmailAddress sender(emailCore->getUser(), ui->fromNameLineEdit->text());
    message.setSender(&sender);
    EmailAddress to(ui->recepientLineEdit->text());
    message.addRecipient(&to);
    message.setSubject(ui->themeLlineEdit->text());
    MimeText text;
    text.setText(ui->plainTextEdit->toPlainText());
    message.addPart(&text);

    if (!emailCore->sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        QMessageBox::information(0, "Warning!", "You are not fill all fields!");
    } else {
        QMessageBox::information(0, "Information", "Message send succesfully!");
    }

}

void SimpleTextForm::back() {
    this->hide();
    TypePickForm *tpf = new TypePickForm(emailCore);
    tpf->show();
}
