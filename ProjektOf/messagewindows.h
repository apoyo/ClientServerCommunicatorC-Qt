#ifndef MESSAGEWINDOWS_H
#define MESSAGEWINDOWS_H

#include <QWidget>

namespace Ui {
class messagewindows;
}

class messagewindows : public QWidget
{
    Q_OBJECT

public:
    explicit messagewindows(QWidget *parent = nullptr);
    ~messagewindows();

private:
    Ui::messagewindows *ui;
};

#endif // MESSAGEWINDOWS_H
