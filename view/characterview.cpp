#include "characterview.h"
#include "playerarea.h"
#include "./view/gamewindow.h"

CharacterView::CharacterView(Card* card, const QSize& size, QPushButton* button)
    : CardView(card, size, button)
{
    QString text;
    std::string txtSize;

    if(FSM::getCurrentState() == Enums::CounterPhase && ApiLogic::whoseCard(card)->hasOnHand(card)){
        text = "COUNTER: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Counter)->value.counter);
        txtSize = "font-size: 8px;";
    }
    else{
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 8px;";
    }

    QLabel* textLabel = new QLabel(text);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(QString::fromStdString(txtSize));

    setup(card, size, textLabel);
}

bool CharacterView::pressedCard(Player *player, PlayerArea* area, Don *don)
{
    if(FSM::getCurrentState() == Enums::AttachDon){
        FSM::attachDonRequest(_card, don);
    }else{
        FSM::selectCardRequest(_card);
    }
    if (FSM::getCurrentState() == Enums::State::CounterPhase && FSM::getCurrentPlayer() != player)
        return false;
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && FSM::getCurrentPlayer() == player){
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
