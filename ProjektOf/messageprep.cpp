#include "messageprep.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "qtcpserver.h"
#include "ui_messageprep.h"
#include <WS2tcpip.h>
#include <iostream>
#include <string>
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
#pragma comment (lib,"ws2_32.lib")
using namespace std;


QString strq="cokolwiek";
QString message1;
QString nazwa;
void messageprep::UpdateField(QString text)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString active="NIE";
  nazwa = text;
    ui->label_3->setText(text);

    QDataStream SocketStream2( socket);
     SocketStream2.startTransaction();
   // SocketStream2>>nazwa;
    ui->user_label->setText("Zalogowano jako " + text);
    int opis = socket->socketDescriptor();
    QString opiseq= QString::number(opis);
    ui->labeleq->setText(opiseq);
   // ui->labeleq->hide();
      QMap<QString ,QTcpSocket* > map;
    messageprep::on_pushButton_3_clicked();
    model->setQuery("SELECT nazwa  FROM users ");

   ui->comboBox->setModel(model);

}

messageprep::messageprep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageprep)
{
    ui->setupUi(this);


    socket =  new QTcpSocket(this);

    connect(this, &messageprep::newMessage, this, &messageprep::displayMessage);
    connect(socket, &QTcpSocket::readyRead, this, &messageprep::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &messageprep::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &messageprep::displayError);



    socket->connectToHost(QHostAddress::LocalHost,8080);

    if(socket->waitForConnected()){
        ui->statusBar->setText("Connected to Server");
      //  messageprep::on_pushButton_3_clicked();
    }
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }



}


messageprep::~messageprep()
{
    if(socket->isOpen())
      socket->close();
    delete ui;
}



void messageprep::readSocket(){

    QString buffer;
    QString who;
    QString from;
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);
    socketStream.startTransaction();
    socketStream >> buffer>>from>>who;

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        emit newMessage(message,"Cos");
        return;
    }


  message1 = QString (buffer);
       emit newMessage(message1,who);




    }



void messageprep::discardSocket(){

    socket->deleteLater();
    socket = nullptr;
    ui->statusBar->setText("Rozlaczono!");



}


void messageprep::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
    default:
        QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}



void messageprep::on_pushButton_clicked()


{

    QString DoKogo,OdKogo;

    OdKogo = ui->label_3->text();

        DoKogo = ui->comboBox->currentText();

    if(socket){
        if(socket->isOpen()){


            QString strd = ui->lineEdit->text();
            QDataStream SocketStream(socket);
            SocketStream.startTransaction();
            SocketStream<<strd<<DoKogo<<OdKogo;



  ui->lineEdit->clear();


        }

        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    } else
        QMessageBox::critical(this,"QTCPClient","Not connected");
    string ipAddress = "127.0.0.1";			// IP Address of the server
    int port = 8080;

   QSqlDatabase mydb2 = QSqlDatabase::addDatabase("QSQLITE");

    mydb2.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");

    if(mydb2.open()){




       // QMessageBox::information(this,"Connection","Database Connected Successfully");





    }
    else{


       // QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


    }


    }












void messageprep::on_pushButton_2_clicked()
{

    QString DoKogo;
    DoKogo = ui->comboBox->currentText();




}

void messageprep::displayMessage(const QString& str,const QString& who){



    ui->textBrowser->append( who + " :: " + str);


}



void messageprep::on_pushButton_3_clicked()
{
    QString strd="Welcome to the server";
    QString DoKogo;
    QString OdKogo;
    QDataStream welcome(socket);

  //  DoKogo=ui->label_3->text();
 //   OdKogo=ui->label_3->text();

    DoKogo=nazwa;
    OdKogo=nazwa;

    welcome<<strd<<DoKogo<<OdKogo;
    ui->label_4->setText("Nazwa to"+ DoKogo);
    ui->pushButton_3->hide();

}

