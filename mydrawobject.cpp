#include "mydrawobject.h"

MyDrawObject::MyDrawObject(QObject *parent) : QObject(parent), QGraphicsItem()
{

}

MyDrawObject::~MyDrawObject()
{

}

void MyDrawObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signal1();
    // Вызываем родительскую функцию события нажатия кнопки мыши
    QGraphicsItem::mousePressEvent(event);
}

QRectF MyDrawObject::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(0,0,100,100);
}

void MyDrawObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Устанавливаем кисть в QPainter и отрисовываем круг, то есть ТОЧКУ
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(0, 0, 100, 100));
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

