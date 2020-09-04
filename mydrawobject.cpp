#include "mydrawobject.h"
#include <QDebug>
#include <QPainter>






MyDrawObject::MyDrawObject(int id)
{
this->ID=id;
}

QRectF MyDrawObject::boundingRect() const
{



return QRectF(0,0,10,10);
}

void MyDrawObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);


    painter->drawEllipse(QRectF(0, 0, 10, 10));
}

void MyDrawObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

qDebug()<<" Press";
}

void MyDrawObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

qDebug()<<" Move";

this->setPos(mapToScene(event->pos()));

}

void MyDrawObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
qDebug()<<" Release";
}
