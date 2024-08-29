#include "messagewindows.h"
#include "qsqlquerymodel.h"
#include "ui_messagewindows.h"

messagewindows::messagewindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messagewindows)
{
    ui->setupUi(this);


    QSqlQueryModel *model = new QSqlQueryModel;

    QString actifed="TAK";
        model->setQuery("SELECT nazwa  FROM users where active='"+actifed+"' " );
    ui->comboBox->setModel(model);

}

messagewindows::~messagewindows()
{
    delete ui;
}
