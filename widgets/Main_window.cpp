#include "Main_window.h"
#include "../models/card/card_types/Leader.h"
#include "Card_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Main_window::Main_window()
{
    window = new QWidget();
    Leader *l = new Leader("Otama", "OP01-006", "OP01-006", Enums::red, 0, 1);
    Card* card = l;
    Leader *t = new Leader("Otama", "OP01-006", "OP01-006", Enums::red, 0, 1);
    Card* card2 = t;
    hand =  new QHBoxLayout( window );
    hand->setAlignment(Qt::AlignLeft | Qt::AlignTop );
    CardWidget *c = new CardWidget(card);
    CardWidget *c2 = new CardWidget(card2);
    hand->addWidget(c);
    hand->addWidget(c2);
    window->setLayout(hand);
    setCentralWidget(window);
    window->show();
    /* setCentralWidget(c);
    setCentralWidget(c2); */
    // QLabel *info = new QLabel();
    // info->setText(QString::fromStdString (c->getInfo()));
    // setCentralWidget(info);
}

Main_window::~Main_window()
{
}

void Main_window::refresh()
{
    Leader *t = new Leader("Otama", "OP01-006", "OP01-006", Enums::red, 0, 1);
    Card* card2 = t;
    CardWidget *c2 = new CardWidget(card2);
    hand->addWidget(c2);
    window->show();
}