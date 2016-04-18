#ifndef TYPEPICKFORM_H
#define TYPEPICKFORM_H

#include <QWidget>
#include "simpletextform.h"
#include "./src/SmtpMime"

namespace Ui{
class TypePickForm;
}
class TypePickForm : public QWidget
{
    Q_OBJECT

public:
    explicit TypePickForm(SmtpClient *email,QWidget *parent = 0);
    ~TypePickForm();
public slots:
    void pick();
private:
    SmtpClient *emailCore;
    Ui::TypePickForm *ui;
};




#endif // TYPEPICKFORM_H

