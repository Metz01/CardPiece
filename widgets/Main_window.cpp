#include "Main_window.h"
#include "../models/card_types/Leader.h"
#include "Card_widget.h"

Main_window::Main_window()
{
    Leader *l = new Leader("Otama", "OP01-006", "+2000", "OP01-006", Enums::red, 0, 1);
    CardWidget *c = new CardWidget(dynamic_cast<Card*>(l));
    setCentralWidget(c);
    //QLabel *info = new QLabel();
    //info->setText(QString::fromStdString (c->getInfo()));
    //setCentralWidget(info);
}

Main_window::~Main_window()
{
}   