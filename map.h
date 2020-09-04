#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMap>
#include <QGraphicsItem>
#include <mydrawobject.h>
#include "mydrawobject.h"

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
        explicit Map(QWidget *parent = 0);

    void Add(int id);
    ~Map();

   void mousePressEvent(QMouseEvent *event) override;
   void mouseMoveEvent(QMouseEvent *event) override;
   void mouseReleaseEvent(QMouseEvent *event) override;


private:
    Ui::Map *ui;

    int cnt;
    QMap< int,QGraphicsItem*> map;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;


};

#endif // MAP_H
