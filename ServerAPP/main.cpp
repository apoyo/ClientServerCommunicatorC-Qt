#include "qcoreapplication.h"
#include <QApplication>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>
#include "maineq.h"
#include <QApplication>
#include <QtCore/QCoreApplication>
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
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{



    //cout<<"Proba";
    QCoreApplication a(argc, argv);
    maineq w;


    return a.exec();

}

