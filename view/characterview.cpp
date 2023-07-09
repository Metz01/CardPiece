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

    setup(card, size, &text);
}

void CharacterView::pressedCard(Player *player, PlayerArea* area, Don *don)
{
    if(FSM::getCurrentState() == Enums::AttachDon){
        FSM::attachDonRequest(this->getCard(), don);
    }else{
        FSM::selectCardRequest(this->getCard());
    }
    if(FSM::getCurrentState() != Enums::State::CounterPhase)
        area->updateGui();
    else if (FSM::getCurrentState() == Enums::State::CounterPhase && FSM::getCurrentPlayer() != player)
        area->updateGui();
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && FSM::getCurrentPlayer() == player){
        area->displayGround(player->getGround(), _card);
    }
    if(FSM::getCurrentState() == Enums::State::CounterPhase)
    {
        area->showCounterButton();
        return;
    }
    if(FSM::getCurrentState() == Enums::State::EndGame)
    {
        GameWindow::showEndGame();
        return;
    }
    GameWindow::updateOpponent(area);
}
