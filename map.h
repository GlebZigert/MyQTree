#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
        explicit Map(QWidget *parent = 0);

    void Add();
    ~Map();




private:
    Ui::Map *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;


};

#endif // MAP_H
