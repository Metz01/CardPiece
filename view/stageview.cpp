#include "stageview.h"
#include "playerarea.h"
#include "./view/gamewindow.h"

StageView::StageView(Card* card, const QSize& size, QPushButton* button)
    : CardView(card, button)
{
    QString text;
    std::string txtSize;

    Player* p = ApiLogic::whoseCard(card);
    if(FSM::getCurrentState() == Enums::CounterPhase && p->hasOnHand(card) && FSM::getCurrentPlayer() != p){
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

bool StageView::pressedCard(Player *player, PlayerArea *area, Don *don)
{
    FSM::selectCardRequest(_card);
    if(player->hasOnHand(_card) && don == NULL) area->updateGui();
    return false;
}
