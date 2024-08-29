#include "form2.h"
#include "messageprep.h"
#include "ui_form2.h"
#include <QDialog>
#include<QWidget>
#include<QObject>

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);


    //connect(this, SIGNAL(transfer(QString)), messageprep, SLOT(UpdateField(QString)));
}
Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/vkocz/OneDrive/Dokumenty/DB/logowanie.db");




    if(mydb.open()){




        QMessageBox::information(this,"Connection","Database Connected Successfully");





    }
    else{


        QMessageBox::information(this,"Not Connected","Database Connected UnSuccessfully");


    }



    QString nazwa,haslo;



    nazwa = ui->login->text();
    haslo = ui->passlogin->text();




    //ui->loginlabel->setText(haslo+ " " + nazwa);




      QSqlQuery logineq;

    QString actived="NIE";
 QSqlQuery actifed;
    actifed.prepare("update users set active = '"+actived+"' " );

   actifed.exec();

    logineq.prepare("select * from users where nazwa='"+nazwa+"' and haslo='"+haslo+"' " );






  logineq.exec();
 // ui->loginlabel->setText(logineq.size());


  int count=0;
  while(logineq.next()){

        count++;
  }

        if(count==1){
            ui->loginlabel->setText("Nazwa uzytkownika i haslo poprawne");


            QString active="TAK";


          QSqlQuery actifede;
                       actifede.prepare("update users set active = '"+active+"' where nazwa='"+nazwa+"' and haslo='"+haslo+"' ");

            actifede.exec();





            logineq.exec();


         //connect(this,SIGNAL(sendData(QString)), messageprep ,SLOT(receiveData(QString)));





            auto mmc = new messageprep();
            connect(this, SIGNAL(transfer(QString)), mmc, SLOT(UpdateField(QString)));

            emit(transfer(nazwa));
            mmc->setAttribute(Qt::WA_DeleteOnClose);
             mmc->show();

        }

        if(count>1){
            ui->loginlabel->setText("Duplikat Nazwa uzytkownika i haslo poprawne");

        }

        if(count==0){
            ui->loginlabel->setText("Nazwa uzytkownika i haslo nie jest poprawne");

        }


        //delete ui;



        /* while(logineq.exec()){

            count++;


        }

        if(count==1){

            ui->loginlabel->setText("Nazwa uzytkownika i haslo poprawne");


        }
        if(count>1){

            ui->loginlabel->setText("Duplikat nazwy uzytkownika i hasla");


        }
        if(count<1){

            ui->loginlabel->setText("nazwa uzytkownika lub haslo jest niepoprawne");


        }


*/



    }










