#ifndef HTMLFORM_H
#define HTMLFORM_H
#include <QWidget>
#include <QMessageBox>
#include "./src/SmtpMime"
namespace Ui{
class HtmlForm;
}
class HtmlForm : public QWidget
{
    Q_OBJECT

public:
    explicit HtmlForm(SmtpClient *email,QWidget *parent = 0);
    ~HtmlForm();
public slots:
    void change();
private:
    SmtpClient *emailCore;
    Ui::HtmlForm *ui;
};


#endif // HTMLFORM_H

