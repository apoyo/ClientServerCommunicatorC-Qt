#ifndef FORM_H
#define FORM_H
#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include <QDialog>
#include <QFileInfo>
#include <QWidget>
#include <QTcpServer>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_dbC_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
