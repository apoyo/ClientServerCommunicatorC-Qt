#ifndef MESSAGE_H
#define MESSAGE_H
#include <QTcpServer>

#include <QWidget>

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();

private slots:
    void on_pushButton_clicked();

private:
    Ui::message *ui;
};

#endif // MESSAGE_H
