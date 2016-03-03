#ifndef SMTPCLIENT
#define SMTPCLIENT

#include <QObject>
#include <QtNetwork/QTcpSocket>

class SmtpClient : public QObject
{
    Q_OBJECT
public:

    SmtpClient(const QString & host = "localhost", int port = 25);

    ~SmtpClient();

    bool connectToHost();
protected:
    QTcpSocket *socket;
    QString host;
    QString responseText;
    int responseCode;
    int port;

    void sendMessage(const QString &text);

    void waitForResponse();

};

#endif // SMTPCLIENT_H
