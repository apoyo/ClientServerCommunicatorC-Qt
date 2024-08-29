#include "form.h"
#include "ui_form.h"
#include <QDialog>
#include<QWidget>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    ui->l_username_2->setPlaceholderText("Wpisz nazwę użytkownika");
   ui->l_passwd_2->setPlaceholderText("Wpisz hasło");
   ui->l_r_passwd_2->setPlaceholderText("Wpisz hasło ponownie");
   ui->l_name_2->setPlaceholderText("Wpisz imie");
   ui->l_last_name_2->setPlaceholderText("Wpisz nazwisko");
   ui->l_nr_tel_2->setPlaceholderText("Wpisz nr telefonu");














}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

}


void Form::on_pushButton_2_clicked()
{
/*

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");




    if(!mydb.isOpen()){

        QMessageBox::information(this,"Not Connected","Nie udało się połaczyć z bazą danych");
    }


    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");


    */






    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");




    if(mydb.open()){




        QMessageBox::information(this,"Connection","Database Connected Successfully");

        ui->dbC->hide();
        ui->label1->setText("Połączono z Bazą Danych");

    }
    else{


        QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


    }



QString nazwa,haslo,imie,email,tel,krajzm,info;

    QString active = "NIE";

nazwa = ui->l_username_2->text();
haslo = ui->l_passwd_2->text();
imie = ui->l_name_2->text();
email = ui->l_email_2->text();
tel = ui->l_nr_tel_2->text();
krajzm = ui->kraj3->text();
info  = ui->about_2->toPlainText();

    QSqlQuery rejestracja;
rejestracja.prepare("insert into users(nazwa,haslo,imie,email,tel,krajzm,info,active) values('"+nazwa+"','"+haslo+"','"+imie+"','"+email+"','"+tel+"','"+krajzm+"','"+info+"','"+active+"')");
    rejestracja.exec();
































}


void Form::on_dbC_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");




    if(mydb.open()){




        QMessageBox::information(this,"Connection","Database Connected Successfully");

        ui->dbC->hide();
        ui->label1->setText("Połączono z Bazą Danych");

    }
    else{


        QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


    }












}

