#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QMenu>

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

signals:

private:
};

#endif // GAMEWINDOW_H
