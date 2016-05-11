
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
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(save()));
    connect(ui->openButton,SIGNAL(clicked(bool)),this,SLOT(open()));
    Highlighter *hl = new Highlighter(ui->textEdit->document());
    QString preset = "";
    preset.append("<html>\n");
    preset.append("  <body style=\"margin:0;padding-top:0;padding-bottom:0;padding-right:0;padding-left:0;min-width:100%;\">\n");
    preset.append("    <div style=\"margin:0;width:100%;\">\n");
    preset.append("       <table width=\"100%\" cellspacing=\"0\" cellpadding=\"0\" style=\"width:100%;\">\n");
    preset.append("        <tbody>\n");
    preset.append("          <tr>\n");
    preset.append("            <td align=\"center\">\n");
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
    cursor.insertText("<table><tbody><tr><td align=\"center\"><img style=\"width:180px;\" src=\"http://cs623225.vk.me/v623225366/1e8b6/b4ggn5BYw1Y.jpg\"></td><td align=\"center\"><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus in fermentum erat, nec sodales massa. Maecenas et vulputate massa, ac sodales enim. Donec lacinia non quam at semper.</p></td></tr></tbody></table>");
}
void HtmlForm::appendBlock2(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("<table><tbody><tr><td align=\"center\"><img style=\"width:180px;\" src=\"http://cs623225.vk.me/v623225366/1e8b6/b4ggn5BYw1Y.jpg\"></td></tr><tr><td align=\"center\"><p>Vestibulum lectus nisl, efficitur in massa non, gravida laoreet velit. In tristique mi elementum libero pulvinar, et fermentum sapien imperdiet. Ut dolor tortor, commodo ac diam a, rhoncus hendrerit nibh. Etiam pretium efficitur elit, sed commodo urna pretium vitae. </p></td></tr></tbody></table>");
}
void HtmlForm::appendBlock3(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("<table><tbody><tr><td align=\"center\"><img style=\"width:180px;\" src=\"http://cs623225.vk.me/v623225366/1e8b6/b4ggn5BYw1Y.jpg\"></td></tr></tbody></table>");
}
void HtmlForm::appendBlock4(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("<table><tbody><tr><td align=\"center\"><p>Vestibulum lectus nisl, efficitur in massa non, gravida laoreet velit. In tristique mi elementum libero pulvinar, et fermentum sapien imperdiet. Ut dolor tortor, commodo ac diam a, rhoncus hendrerit nibh. Etiam pretium efficitur elit, sed commodo</p></td></tr></tbody></table>");
}
void HtmlForm::appendBlock5(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("<table><tbody><tr><td align=\"center\"><img style=\"width:180px;\" src=\"http://cs623225.vk.me/v623225366/1e8b6/b4ggn5BYw1Y.jpg\"></td><td align=\"center\"><img style=\"width:180px;\" src=\"http://cs623225.vk.me/v623225366/1e8b6/b4ggn5BYw1Y.jpg\"></td></tr><tr><td align=\"center\"><p>Vestibulum lectus nisl, efficitur in massa non, gravida laoreet velit.</p></td><td align=\"center\"><p>Vestibulum lectus nisl, efficitur in massa non, gravida laoreet velit.</p></td></tr></tbody></table>");
}
void HtmlForm::save(){

    QFileDialog *fd = new QFileDialog(this);
    QString filename = fd->getSaveFileName(this, "Save file", "", ".html");
    if(filename.length()>0){
        QFile f( filename.append(".html"));
        f.open( QIODevice::WriteOnly );
        if(f.isOpen()){
            QTextStream fstream(&f);
            fstream << ui->textEdit->toPlainText();
        } else {
            QMessageBox::information(0, "Warning!", "Cannot open file!");
        }
        f.close();
    }
}

void HtmlForm::open(){

    QFileDialog *fd = new QFileDialog(this);
    QString filename = fd->getOpenFileName(this);
    if(filename.length()>0){
        QFile f(filename);
        f.open( QIODevice::ReadOnly );
        QString str="";
        if(f.isOpen()){
            QTextStream fstream(&f);

                str.append(fstream.readAll());

            ui->textEdit->setPlainText(str);
        } else {
            QMessageBox::information(0, "Warning!", "Cannot open file!");
        }
        f.close();
    }
}
