#include "simpletextform.h"
#include "ui_simpletextform.h"

SimpleTextForm::SimpleTextForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleTextForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->proceedButton,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(back()));
}

SimpleTextForm::~SimpleTextForm()
{
    delete ui;
}
void SimpleTextForm::send(){


    MimeText text;
    text.setText(ui->plainTextEdit->toPlainText());
    this->hide();
    SendForm *sf = new SendForm(emailCore,ui->plainTextEdit->toPlainText(),this);
    sf->show();

}

void SimpleTextForm::back() {
    this->hide();
    TypePickForm *tpf = new TypePickForm(emailCore);
    tpf->show();
}
