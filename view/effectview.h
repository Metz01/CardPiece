#ifndef EFFECTVIEW_H
#define EFFECTVIEW_H

#include "cardview.h"

class EffectView : public CardView
{
    Q_OBJECT
public:
    EffectView(Card* card = nullptr, const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());
    void pressedCard(Player* player, PlayerArea* area, Don* don = NULL) override;
};

#endif // EFFECTVIEW_H
