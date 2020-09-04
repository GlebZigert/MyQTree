#ifndef MYDRAWOBJECT_H
#define MYDRAWOBJECT_H
#include <QGraphicsItem>

#include <QObject>
#include<QGraphicsSceneMouseEvent>
#include<QCursor>

class MyDrawObject : public QGraphicsItem
{
public:
    int ID;
   MyDrawObject(int ID);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float x1,y1,x2,y2;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QImage image;
    QVector<QImage> img_array;
};

#endif // MYDRAWOBJECT_H
