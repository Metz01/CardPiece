#include "leaderview.h"
#include "playerarea.h"
#include "./view/gamewindow.h"

LeaderView::LeaderView(Card* card, const QSize& size, QPushButton* button)
    : CardView(card, button)
{
    QString text;
    std::string txtSize;

    if(FSM::getCurrentState() == Enums::CounterPhase && ApiLogic::whoseCard(card)->hasOnHand(card)){
        text = "";
    }
    else{
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 10px;";
    }

    QLabel* textLabel = new QLabel(text);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(QString::fromStdString(txtSize));

    setup(card, size, textLabel);
}

bool LeaderView::pressedCard(Player *player, PlayerArea *area, Don *don)
{
    if(FSM::getCurrentState() == Enums::AttachDon){
        FSM::attachDonRequest(_card, don);
    }else{
        FSM::selectCardRequest(_card);
    }
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && player == FSM::getCurrentPlayer()){
        return true;
    }
    if(FSM::getCurrentState() == Enums::State::CounterPhase)
    {
        area->showCounterButton();
        return false;
    }
    if(FSM::getCurrentState() == Enums::State::EndGame)
    {
        GameWindow::showEndGame();
        return false;
    }
    return false;
}
