#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "./view/cardview.h"

#include <QString>

class CharacterView : public CardView
{
    Q_OBJECT
public:
    CharacterView(Card* card = nullptr, const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());
    bool pressedCard(Player* player, PlayerArea* area, Don* don = NULL) override;
};

#endif // CHARACTERVIEW_H
