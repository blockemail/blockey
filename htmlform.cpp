
#include "htmlform.h"
#include "ui_htmlform.h"
#include "highlighter.h"

HtmlForm::HtmlForm(SmtpClient *email,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HtmlForm)
{
    emailCore = email;
    ui->setupUi(this);
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(back()));
    connect(ui->proceedButton,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(change()));
    connect(ui->block1Button,SIGNAL(clicked(bool)),this,SLOT(appendBlock1()));
    connect(ui->block2Button,SIGNAL(clicked(bool)),this,SLOT(appendBlock2()));
    connect(ui->block3Button,SIGNAL(clicked(bool)),this,SLOT(appendBlock3()));
    connect(ui->block4Button,SIGNAL(clicked(bool)),this,SLOT(appendBlock4()));
    connect(ui->block5Button,SIGNAL(clicked(bool)),this,SLOT(appendBlock5()));

    Highlighter *hl = new Highlighter(ui->textEdit->document());
    QString preset = "";
    preset.append("<html>\n");
    preset.append("  <body style=\"margin:0;padding-top:0;padding-bottom:0;padding-right:0;padding-left:0;min-width:100%;\">\n");
    preset.append("    <div style=\"margin:0;width:100%;\">\n");
    preset.append("       <table width=\"100%\" cellspacing=\"0\" cellpadding=\"0\" style=\"width:100%;\">\n");
    preset.append("        <tbody>\n");
    preset.append("          <tr>\n");
    preset.append("            <td>\n");
    preset.append("            </td>\n");
    preset.append("          </tr>\n");
    preset.append("        </tbody>\n");
    preset.append("      </table>\n");
    preset.append("    </div>\n");
    preset.append("  </body>\n");
    preset.append("</html>");
    ui->textEdit->setPlainText(preset);
    ui->webView->setHtml(ui->textEdit->toPlainText());
}

HtmlForm::~HtmlForm()
{
    delete ui;
}
void HtmlForm::change(){


    ui->webView->setHtml(ui->textEdit->toPlainText());
}

void HtmlForm::back() {
    this->hide();
    TypePickForm *tpf = new TypePickForm(emailCore);
    tpf->show();
}
void HtmlForm::send() {

    MimeHtml html;

    html.setHtml(ui->textEdit->toPlainText());

    this->hide();
    SendForm *sf = new SendForm(emailCore,ui->textEdit->toPlainText(),this);
    sf->show();

}
void HtmlForm::appendBlock1(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("block1");
}
void HtmlForm::appendBlock2(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("block2");
}
void HtmlForm::appendBlock3(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("block3");
}
void HtmlForm::appendBlock4(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("block4");
}
void HtmlForm::appendBlock5(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("block5");
}

