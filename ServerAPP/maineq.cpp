
#include "maineq.h"
#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include <QDialog>
#include <QFileInfo>
#include <QWidget>
#include <QTcpServer>
#include<iostream>
#include<QtSql>
#include<QSqlDatabase>

using namespace std;
QString strq;
//QJsonObject wiadomosc;
QString OdKogo;
QString DoKogo;
   QString strd;
    QString nazwa;

maineq::maineq(QObject *parent)
        : QObject{parent}
{


    m_server = new QTcpServer();

connect(this, &maineq::newMessage, this, &maineq::displayMessage);
    if(m_server->listen(QHostAddress::Any, 8080))
    {

        connect(m_server, &QTcpServer::newConnection, this, &maineq::newConnection);

    }
    else
    {

        exit(EXIT_FAILURE);
    }

    foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }




    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");


    if(DB.open()){




        //  QMessageBox::information(this,"Connection","Database Connected Successfully");





    }
    else{


        //QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


    }
 //   m_server->close();
  //  m_server->deleteLater();


}

maineq::~maineq(){

   foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }

   m_server->close();
   m_server->deleteLater();

}
void maineq::newConnection(){

    while (m_server->hasPendingConnections())
        appendToSocketList(m_server->nextPendingConnection());
}


void maineq::appendToSocketList(QTcpSocket* socket){

    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &maineq::readSocket);
  connect(socket, &QTcpSocket::disconnected, this, &maineq::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &maineq::displayError);




}



void maineq::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());



    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

   socketStream.startTransaction();

    socketStream >>strd>>DoKogo>>OdKogo;


    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
       // emit newMessage(message," ");
        return;
    }

    cout<<"\n Wiadomosc od : "<<OdKogo.toStdString()<<" Wiadomosc do : "<<DoKogo.toStdString()<<"  Tresc Wiadomosci: "<<strd.toStdString()<<"\n";
    int opis = socket->socketDescriptor();
    QString opiseq= QString::number(opis);
    QSqlQuery wpisz;


    wpisz.prepare("update users  set socket='"+opiseq+"'   where nazwa='"+OdKogo+"' ");
    wpisz.exec();

    emit newMessage(strd,OdKogo);




}


void maineq::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = connection_set.find(socket);
    if (it != connection_set.end()){
        //  displayMessage(QString("INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        connection_set.remove(*it);
    }


    socket->deleteLater();
}

void maineq::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        //QMessageBox::information(this, "QTCPServer", "The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        //QMessageBox::information(this, "QTCPServer", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
    default:
        QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
            //QMessageBox::information(this, "QTCPServer", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }

}


void maineq::displayMessage(const QString& str,const QString& who)

{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    QString numersocketu;
    QSqlQuery query(DB);


    query.exec("SELECT socket from users where  nazwa = '"+DoKogo+"'") ;
    query.first();
             numersocketu = query.value(0).toString(); // Pobiera wartość pola jako QString

             long long nrsocketu = numersocketu.toLongLong();
             int numersocketuint = numersocketu.toInt();


    foreach (QTcpSocket* socket,connection_set)
    {

        if(socket->socketDescriptor()==nrsocketu){

        sendMessage(socket);
        }
    }
}
void maineq::sendMessage(QTcpSocket* socket){

    //cout<<"\nSTRD to"<<strd.toStdString();
    if(socket){

        if(socket->isOpen()){



            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);
            socketStream.startTransaction();
            socketStream.setVersion(QDataStream::Qt_5_15);
 socketStream << strd <<DoKogo<<OdKogo;



        }

        else
            cout<<"Socket doesn't seem to be opened";



    }

else
        cout<<"Nie połączono";

}

