#include "typepickform.h"

#include "ui_typepickform.h"

TypePickForm::TypePickForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TypePickForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->plainTextButton,SIGNAL(clicked(bool)),this,SLOT(pick()));
    connect(ui->htmlButton,SIGNAL(clicked(bool)),this,SLOT(pick()));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backToLogin()));
}

TypePickForm::~TypePickForm()
{
    delete ui;
}


void TypePickForm::pick(){
     QString type = sender()->objectName();
     if("plainTextButton"==type){
         SimpleTextForm *stf= new SimpleTextForm(emailCore);
         stf->show();
      } else {
         HtmlForm *hf= new HtmlForm(emailCore);
         hf->show();
     }
     this->~TypePickForm();
}
void TypePickForm::backToLogin() {
    this->hide();
    emailCore->quit();
    LoginForm *log = new LoginForm(emailCore);
    log->show();
}
