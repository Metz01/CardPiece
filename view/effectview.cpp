#include "effectview.h"
#include "playerarea.h"
#include "./view/gamewindow.h"

EffectView::EffectView(Card* card, const QSize& size, QPushButton* button)
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

    QLabel* textLabel = new QLabel(text);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(QString::fromStdString(txtSize));

    setup(card, size, textLabel);
}

bool EffectView::pressedCard(Player *player, PlayerArea *area, Don *don)
{
    if(FSM::getCurrentState()== Enums::SelectCard && player->hasOnHand(_card)) FSM::selectCardRequest(_card);
    area->updateGui();
}
