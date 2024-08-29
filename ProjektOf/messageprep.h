#ifndef MESSAGEPREP_H
#define MESSAGEPREP_H

#include <QWidget>
#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include<QTcpServer>
#include<QTcpSocket>
#include <QMainWindow>
#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <winsock2.h>
namespace Ui {
class messageprep;
}

class messageprep : public QWidget
{
    Q_OBJECT

public:
    explicit messageprep(QWidget *parent = nullptr);
    ~messageprep();
    void welcome();
signals:
    void newMessage(QString,QString);

  //  QDataStream welcome(QTcpSocket *socket);


private slots:

    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void UpdateField(QString text);
    void on_pushButton_clicked();
    void displayMessage(const QString& str,const QString& who);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::messageprep *ui;

    QTcpSocket* socket;
};

#endif // MESSAGEPREP_H
