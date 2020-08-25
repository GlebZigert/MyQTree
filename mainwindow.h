#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "treemodel.h"
#include "treeitem.h"
#include"mytreeview.h"
#include "mymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    TreeModel *treemodel;
    MyModel *model;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
