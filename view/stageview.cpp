#include "stageview.h"

StageView::StageView(Card* card, const QSize& size, QPushButton* button)
    : CardView(card, size, button)
{
    QString text;
    std::string txtSize;

    if(FSM::getCurrentState() == Enums::CounterPhase && ApiLogic::whoseCard(card)->hasOnHand(card)){
        text = "";
    }
    else{
        text = "BUFF: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        txtSize = "font-size: 8px;";
    }

    setup(card, size, &text);
}
