#ifndef HTMLFORM_H
#define HTMLFORM_H
#include <QWidget>
#include <QMessageBox>
#include "typepickform.h"
#include "./src/SmtpMime"
#include <QFileDialog>

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
    void back();
    void send();
    void appendBlock1();
    void appendBlock2();
    void appendBlock3();
    void appendBlock4();
    void appendBlock5();
    void save();
private:
    SmtpClient *emailCore;
    Ui::HtmlForm *ui;
};


#endif // HTMLFORM_H

