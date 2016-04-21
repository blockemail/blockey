#ifndef SENDFORM
#define SENDFORM
#include <QWidget>
#include <QMessageBox>
#include "./src/SmtpMime"
namespace Ui{
class SendForm;
}
class SendForm : public QWidget
{
    Q_OBJECT

public:
    explicit SendForm(SmtpClient *email,QString part,QWidget *parentForm, QWidget *parent=0);
    ~SendForm();
public slots:
    void send();
    void back();
private:
    SmtpClient *emailCore;
    Ui::SendForm *ui;
    QString part;
    QWidget *parentForm;
};
#endif // SENDFORM

