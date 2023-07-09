#ifndef LEADERVIEW_H
#define LEADERVIEW_H

#include "cardview.h"

class LeaderView : public CardView
{
    Q_OBJECT
public:
    LeaderView(Card* card = nullptr, const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());
    bool pressedCard(Player* player, PlayerArea* area, Don* don = NULL) override;
};

#endif // LEADERVIEW_H
