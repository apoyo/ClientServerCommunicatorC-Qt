#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QDialog>
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
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

private slots:
    void on_pushButton_clicked();

signals:
    void transfer(QString);

private:
    Ui::Form2 *ui;
};

#endif // FORM2_H
