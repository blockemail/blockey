#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    emailCore = email;
    ui->setupUi(this);
    ui->emailLineEdit->setValidator(new QRegExpValidator( QRegExp( "[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"),this ) );
    connect(ui->loginButton,SIGNAL(clicked(bool)),this,SLOT(login()));
    ui->emailLineEdit->setText("htmlblockeditor@gmail.com");
    ui->passwordLineEdit->setText("blockemail1234");

}

LoginForm::~LoginForm()
{
    delete ui;
}
void LoginForm::login(){
    if(ui->emailLineEdit->hasAcceptableInput()) {
       emailCore->setUser(ui->emailLineEdit->text());
    }else {
        QMessageBox::information(0, "Warning!", "Email isn't correct");
    }

    emailCore->setPassword(ui->passwordLineEdit->text());
    if (!emailCore->connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
        QMessageBox::information(0, "Warning!", "Failed to connect to host!");
        return;
    }

    if (!emailCore->login()) {
        qDebug() << "Failed to login!" << endl;
        QMessageBox::information(0, "Warning!", "Failed to login!");
        return;
    }

    TypePickForm *tpf = new TypePickForm(emailCore);
    tpf->show();
    this->hide();
}
