#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLineEdit>



class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

QLineEdit length;

QLineEdit width;



signals:

public slots:
};

#endif // MYWIDGET_H
