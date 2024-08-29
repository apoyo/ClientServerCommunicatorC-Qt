
#ifndef MAINEQ_H
#define MAINEQ_H
#include<QTcpServer>
#include<QTcpSocket>
#include <QObject>
#include<QtSql>
#include<QSqlDatabase>
#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include <QDialog>
#include <QFileInfo>
#include <QWidget>
#include <QTcpServer>

class maineq : public QObject
{
    Q_OBJECT
public:
    explicit maineq(QObject *parent = nullptr);
    QSqlDatabase DB;
    ~maineq();

signals:
       void newMessage(QString,QString);
private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket* socket);

    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void sendMessage(QTcpSocket* socket);
    void displayMessage(const QString& str,const QString& who);
private:
    QTcpServer* m_server;
    QSet<QTcpSocket*> connection_set;
};

#endif // MAINEQ_H
