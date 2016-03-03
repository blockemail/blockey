#include "mainwindow.h"
#include "smtpclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    SmtpClient smtp("smtp.gmail.com",465);
    smtp.connectToHost();
    return a.exec();
}
