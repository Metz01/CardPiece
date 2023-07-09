#include "effectview.h"
#include "playerarea.h"

EffectView::EffectView(Card* card, const QSize& size, QPushButton* button)
    : CardView(card, button)
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
    FSM::selectCardRequest(_card);
    if(player->hasOnHand(_card) && don == NULL) area->updateGui();
    return false;
}
