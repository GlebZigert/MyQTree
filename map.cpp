#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

    cnt=0;
    MyDrawObject *my=new MyDrawObject();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addItem(my);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

   // rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

    // addEllipse(x,y,w,h,pen,brush)
    //ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

  //  text = scene->addText("bogotobogo.com", QFont("Arial", 20) );
    // movable text
   // text->setFlag(QGraphicsItem::ItemIsMovable);


}

void Map::Add()
{

}

Map::~Map()
{
    delete ui;
}
