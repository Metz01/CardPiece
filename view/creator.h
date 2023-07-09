#ifndef CREATOR_H
#define CREATOR_H

#include <QSize>
#include <QPushButton>

#include "./view/cardview.h"
#include "./view/cardviewfactory.h"
#include "./view/leaderview.h"
#include "./view/characterview.h"
#include "./view/effectview.h"
#include "./view/stageview.h"

class Creator
{
public:
    Creator();
    CardView* getCardView(Card*, const QSize&, QPushButton*);
};

#endif // CREATOR_H
