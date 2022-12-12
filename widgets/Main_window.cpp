#include <QVBoxLayout>
#include "Main_window.h"

Main_window::Main_window(Card card)
{
    CardWidget *c = new CardWidget(card);
    setCentralWidget(c);
}

Main_window::~Main_window()
{
}