#include "mainwindow.h"
#include "form.h"
#include "form2.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include "ui_form2.h"
#include<QMessageBox>
#include <QtSql>
#include <QDialog>
#include<QWidget>
#include <winsock2.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qDebug() << QSqlDatabase::drivers();





}

MainWindow::~MainWindow()
{
    delete ui;



}


void MainWindow::on_DbConnect_clicked()
{




    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");




                if(mydb.open()){




                   QMessageBox::information(this,"Connection","Database Connected Successfully");

                    ui->DbConnect->hide();
                   ui->label->setText("Połączono z Bazą Danych");

               }
               else{


                    QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


               }





}


void MainWindow::on_pushButton_register_clicked()
{



              // this->hide();



               Form formularz;

               formularz.show();

               auto mm = new Form();
               mm->setAttribute(Qt::WA_DeleteOnClose);
               mm->show();



}


void MainWindow::on_pushButton_login_clicked()
{
               Form2 login;

               auto mc = new Form2();
               mc->setAttribute(Qt::WA_DeleteOnClose);
               mc->show();



}

