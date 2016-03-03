#include "smtpclient.h"

#include <QFileInfo>
#include <QByteArray>

SmtpClient::SmtpClient(const QString &host, int port){
    this->host = host;
    this->port = port;
    this->socket = new QTcpSocket(this);
}
SmtpClient::~SmtpClient(){
    if(socket){
        delete socket;
    }
}

bool SmtpClient::connectToHost(){
    socket->connectToHost(host,port);
    waitForResponse();
    sendMessage("EHLO localhost");
    waitForResponse();

    return true;
}
void SmtpClient::sendMessage(const QString &text){
    socket->write(text.toUtf8() + "\r\n");
}
void SmtpClient::waitForResponse(){
    do {

        while (socket->canReadLine()) {

            responseText = socket->readLine();


            responseCode = responseText.left(3).toInt();

            if (responseText[3] == ' ') { return; }
        }
    } while (true);
}

