#ifndef STAGEVIEW_H
#define STAGEVIEW_H

#include "cardview.h"

class StageView : public CardView
{
    Q_OBJECT
public:
    StageView(Card* card = nullptr, const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());
    bool pressedCard(Player* player, PlayerArea* area, Don* don = NULL) override;
};

#endif // STAGEVIEW_H
