#ifndef MAIN_W_H
#define MAIN_W_H

#include <QMainWindow>
#include "Card_widget.h"

class Main_window: public QMainWindow
{
Q_OBJECT
public:
    Main_window(Card card);
    ~Main_window();
};

#endif