#include "smtpclient.h"

#include <QFileInfo>
#include <QByteArray>

SmtpClient::SmtpClient(const QString &host, int port){
    this->host = host;
    this->port = port;
    //this->socket = new QTcpSocket(this);
    this->socket = new QSslSocket(this);
    this->connectionTimeout = 5000;
    this->responseTimeout = 5000;
    this->sendMessageTimeout = 5000;
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(readyRead()),
                this, SLOT(socketReadyRead()));
}
SmtpClient::~SmtpClient(){
    if(socket){
        delete socket;
    }
}

bool SmtpClient::connectToHost()
{

    ((QSslSocket*)socket)->connectToHostEncrypted(host, port);
    //socket->connectToHost(host,port);

    // Tries to connect to server
    if (!socket->waitForConnected(connectionTimeout))
    {
        emit smtpError(ConnectionTimeoutError);
        return false;
    }

    try
    {
        // Wait for the server's response
        waitForResponse();

        // If the response code is not 220 (Service ready)
        // means that is something wrong with the server
        if (responseCode != 220)
        {
            emit smtpError(ServerError);
            return false;
        }

        // Send a EHLO/HELO message to the server
        // The client's first command must be EHLO/HELO
        sendMessage("EHLO name");

        // Wait for the server's response
        waitForResponse();

        // The response code needs to be 250.
        if (responseCode != 250) {
            emit smtpError(ServerError);
            return false;
        }
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    // If no errors occured the function returns true.
    return true;
}
void SmtpClient::sendMessage(const QString &text)
{
    socket->write(text.toUtf8() + "\r\n");
    if (! socket->waitForBytesWritten(sendMessageTimeout))
    {
      emit smtpError(SendDataTimeoutError);
      throw SendMessageTimeoutException();
    }
}
void SmtpClient::waitForResponse()
{
    do {
        if (!socket->waitForReadyRead(responseTimeout))
        {
            emit smtpError(ResponseTimeoutError);
            throw ResponseTimeoutException();
        }

        while (socket->canReadLine()) {
            // Save the server's response
            responseText = socket->readLine();

            // Extract the respose code from the server's responce (first 3 digits)
            responseCode = responseText.left(3).toInt();

            if (responseCode / 100 == 4)
                emit smtpError(ServerError);

            if (responseCode / 100 == 5)
                emit smtpError(ClientError);

            if (responseText[3] == ' ') { return; }
        }
    } while (true);
}

bool SmtpClient::login(const QString &user, const QString &password){


    try {

                // Sending command: AUTH PLAIN base64('\0' + username + '\0' + password)
                sendMessage("AUTH PLAIN " + QByteArray().append((char) 0).append(user).append((char) 0).append(password).toBase64());

                // Wait for the server's response
                waitForResponse();

                // If the response is not 235 then the authentication was faild
                if (responseCode != 235)
                {
                    emit smtpError(AuthenticationFailedError);
                    return false;
                }

        }
        catch (ResponseTimeoutException)
        {
            // Responce Timeout exceeded
            emit smtpError(AuthenticationFailedError);
            return false;
        }
        catch (SendMessageTimeoutException)
        {
        // Send Timeout exceeded
            emit smtpError(AuthenticationFailedError);
            return false;
        }

        return true;
}
bool SmtpClient::sendMail(MimeMessage& email)
{
    try
    {
        // Send the MAIL command with the sender
        sendMessage("MAIL FROM: <" + email.getSender().getAddress() + ">");

        waitForResponse();

        if (responseCode != 250) return false;

        // Send RCPT command for each recipient
        QList<EmailAddress*>::const_iterator it, itEnd;
        // To (primary recipients)
        for (it = email.getRecipients().begin(), itEnd = email.getRecipients().end();
             it != itEnd; ++it)
        {
            sendMessage("RCPT TO: <" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Cc (carbon copy)
        for (it = email.getRecipients(MimeMessage::Cc).begin(), itEnd = email.getRecipients(MimeMessage::Cc).end();
             it != itEnd; ++it)
        {
            sendMessage("RCPT TO: <" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Bcc (blind carbon copy)
        for (it = email.getRecipients(MimeMessage::Bcc).begin(), itEnd = email.getRecipients(MimeMessage::Bcc).end();
             it != itEnd; ++it)
        {
            sendMessage("RCPT TO: <" + (*it)->getAddress() + ">");
            waitForResponse();

            if (responseCode != 250) return false;
        }

        // Send DATA command
        sendMessage("DATA");
        waitForResponse();

        if (responseCode != 354) return false;

        sendMessage(email.toString());

        // Send \r\n.\r\n to end the mail data
        sendMessage(".");

        waitForResponse();

        if (responseCode != 250) return false;
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    return true;
}
void SmtpClient::quit()
{
    sendMessage("QUIT");
}
void SmtpClient::socketStateChanged(QAbstractSocket::SocketState /*state*/)
{
}

void SmtpClient::socketError(QAbstractSocket::SocketError /*socketError*/)
{
}

void SmtpClient::socketReadyRead()
{
}
