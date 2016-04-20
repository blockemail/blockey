
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

    connect(ui->block1Button,SIGNAL(clicked(bool)),this,SLOT(change()));    
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
    //QString html = "<html>\n\t<body><p style=\"color: red;\">This is a paragraph.</p><p>This is a paragraph.</p><p>This is a paragraph.</p></body></html>";
    //QString test = "123";
    //ui->textEdit->setText(html);
    //ui->textEdit->setPlainText(html);

    //ui->webView->setHtml(html);
    //ui->webView->reload();
}

void HtmlForm::back() {
    this->hide();
    TypePickForm *tpf = new TypePickForm(emailCore);
    tpf->show();
}
