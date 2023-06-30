#ifndef MAIN_W_H
#define MAIN_W_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
//#include "Card_widget.h"

class Main_window: public QMainWindow
{
Q_OBJECT
private:
    QWidget *window;
    QHBoxLayout *hand;
    //CardWidget *card;
    //CardWidget *card2;
public:
    Main_window();
    ~Main_window();
    void refresh();
};

#endif