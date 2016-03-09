#ifndef SMTPCLIENT
#define SMTPCLIENT

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QSslSocket>
#include "mimemessage.h"

class SmtpClient : public QObject
{
    Q_OBJECT
public:

    SmtpClient(const QString & host = "localhost", int port = 25);

    ~SmtpClient();
    enum SmtpError
       {
           ConnectionTimeoutError,
           ResponseTimeoutError,
           SendDataTimeoutError,
           AuthenticationFailedError,
           ServerError,    // 4xx smtp error
           ClientError     // 5xx smtp error
       };

    bool connectToHost();
    bool login(const QString &user,const QString &password);
    bool sendMail(MimeMessage& email);
    void quit();
protected:

    QTcpSocket *socket;
    QString host;
    QString responseText;
    int responseCode;
    int port;

    int connectionTimeout;
    int responseTimeout;
    int sendMessageTimeout;

    class ResponseTimeoutException {};
    class SendMessageTimeoutException {};

    void sendMessage(const QString &text);

    void waitForResponse();

protected slots:

    /* [6] Protected slots */

    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketError(QAbstractSocket::SocketError error);
    void socketReadyRead();

    /* [6] --- */


signals:

    /* [7] Signals */

    void smtpError(SmtpClient::SmtpError e);


};

#endif // SMTPCLIENT_H
