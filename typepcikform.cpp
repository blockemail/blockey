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
          qDebug() << "html!" << endl;
     }
     this->hide();
}
