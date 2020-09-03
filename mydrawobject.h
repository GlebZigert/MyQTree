#ifndef MYDRAWOBJECT_H
#define MYDRAWOBJECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class MyDrawObject : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyDrawObject(QObject *parent = 0);
    ~MyDrawObject();

signals:
    /* Сигнал, который будет посылаться в том случае,
     * если произошел клик мышью по объекту
     * */
    void signal1();

protected:
    /* Перегружаем метод нажатия мышью, для его перехвата
     * */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    /* Данные методы виртуальные, поэтому их необходимо реализовать
     * в случае наследования от QGraphicsItem
     * */
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // MYDRAWOBJECT_H
