#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QWidget>
#include <QTcpServer>
#include <QAbstractSocket>

#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_DbConnect_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
