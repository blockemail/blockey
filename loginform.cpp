#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->loginButton,SIGNAL(clicked(bool)),this,SLOT(login()));
}

LoginForm::~LoginForm()
{
    delete ui;
}
void LoginForm::login(){
    emailCore->setUser(/*ui->emailLineEdit->text()*/"htmlblockeditor@gmail.com");
    emailCore->setPassword(/*ui->passwordLineEdit->text()*/ "blockemail1234");
    if (!emailCore->connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
        return;
    }

    if (!emailCore->login()) {
        qDebug() << "Failed to login!" << endl;
        return;
    }
    SimpleTextForm *stf= new SimpleTextForm(emailCore);
    stf->show();
    this->hide();


}
