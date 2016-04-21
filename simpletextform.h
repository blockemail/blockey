#ifndef SIMPLETEXTFORM_H
#define SIMPLETEXTFORM_H
#include <QWidget>
#include <QMessageBox>
#include "typepickform.h"
#include "sendform.h"
#include "./src/SmtpMime"
namespace Ui{
class SimpleTextForm;
}
class SimpleTextForm : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTextForm(SmtpClient *email,QWidget *parent = 0);
    ~SimpleTextForm();
public slots:
    void send();
    void back();
private:
    SmtpClient *emailCore;
    Ui::SimpleTextForm *ui;
};
#endif // SIMPLETEXTFORM_H

