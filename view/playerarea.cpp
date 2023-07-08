#include "playerarea.h"

#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include "cardview.h"
#include "./fsm/api/api_logic.h"
#include "./view/gamewindow.h"

PlayerArea::PlayerArea(Player* player, QWidget *parent)
    : QWidget(parent), player(player)
{
    QVBoxLayout* playerAreaLayout = new QVBoxLayout(this);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    playerAreaLayout->addLayout(mainLayout);

    QVBoxLayout* leftLayout = new QVBoxLayout();

    displayLeader(player->getLeader());
    displayGround(player->getGround());
    displayHand(player->getHand());
    displayStage(player->getStage());

    QWidget* stageContainer = new QWidget();
    stageLayout->setParent(stageContainer);
    stageContainer->setFixedSize(90,90);
    stageContainer->setLayout(stageLayout);

    // Setting FixedSize for groundLayout
    QWidget* groundContainer = new QWidget();
    groundLayout->setParent(groundContainer);
    groundContainer->setFixedSize(500, 90);
    groundContainer->setLayout(groundLayout);

    // Setting the alignments for ground and hand
    handLayout->setAlignment(Qt::AlignLeft);
    groundLayout->setAlignment(Qt::AlignLeft);

    // Setting a fixed size for handLayout
    QWidget* handContainer = new QWidget();
    handLayout->setParent(handContainer);
    handContainer->setFixedSize(640, 90);
    handContainer->setLayout(handLayout);

    // Counter Button
    QHBoxLayout* counterLayout = new QHBoxLayout();
    counterButton = new QPushButton("END COUNTER");
    QFont font = counterButton->font();
    font.setPointSize(6);
    counterButton->setFont(font);
    counterButton->setFixedSize(90,30);
    counterButton->setHidden(true);
    counterLayout->addWidget(counterButton);

    QHBoxLayout *HCLayout = new QHBoxLayout();
    HCLayout->addWidget(handContainer);
    HCLayout->addLayout(counterLayout);
    HCLayout->setAlignment(Qt::AlignLeft);

    // Adding the various layouts to the fieldLayout
    fieldLayout->addLayout(leaderLayout);
    fieldLayout->addWidget(groundContainer);
    fieldLayout->addWidget(stageContainer);
    fieldLayout->setAlignment(Qt::AlignLeft);

    leftLayout->addLayout(fieldLayout);
    leftLayout->addLayout(HCLayout);

    QPushButton* deck = new QPushButton();
    QPixmap imageDeck("./assets/Cards/CardBackRegular.png");
    QIcon deckIcon(imageDeck);
    deck->setIcon(deckIcon);
    deck->setIconSize(CARD_SIZE);
    graveyard = new QPushButton();
    QPixmap imageGraveyard("./assets/Cards/EmptyCard.png");
    QIcon graveyardIcon(imageGraveyard);
    graveyard->setIcon(graveyardIcon);
    graveyard->setIconSize(CARD_SIZE);
    QPushButton* donDeck = new QPushButton();
    QPixmap imageDonDeck("./assets/Cards/Don.png");
    QIcon donDeckIcon(imageDonDeck);
    donDeck->setIcon(donDeckIcon);
    donDeck->setIconSize(CARD_SIZE);
    donText->setText("ACTIVE DON : 0");
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(deck);
    rightLayout->addWidget(graveyard);
    rightLayout->addWidget(donDeck);
    rightLayout->addWidget(donText);
    rightLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(leftLayout);
    QSpacerItem* horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addSpacerItem(horizontalSpacer);
    mainLayout->addLayout(rightLayout);

    QHBoxLayout* playerInfoLayout = new QHBoxLayout();

    playerIndicator->setText(QString::fromStdString(player->getName()));
    std::string lifeString = std::to_string(player->getLife());
    lifesText->setText(QString::fromStdString("-  LIFES: " + lifeString));
    playerInfoLayout->addWidget(playerIndicator);
    playerInfoLayout->addWidget(lifesText);
    playerInfoLayout->setAlignment(Qt::AlignLeft);

    playerAreaLayout->addLayout(playerInfoLayout);

    changePlayerTextColor();

    // Connections
    connect(deck, &QPushButton::clicked, this, &PlayerArea::deckButtonPressed);
    connect(donDeck, &QPushButton::clicked, this, &PlayerArea::donButtonPressed);
    connect(counterButton, &QPushButton::clicked, this, &PlayerArea::counterButtonPressed);
}

PlayerArea::~PlayerArea()
{
    delete PlayerArea::handLayout;
    delete PlayerArea::groundLayout;
    delete PlayerArea::stageLayout;
    delete PlayerArea::donText;
    delete PlayerArea::playerIndicator;
    delete PlayerArea::lifesText;
    delete PlayerArea::counterButton;
    delete PlayerArea::graveyard;
}

void PlayerArea::displayLeader(Leader *leader, bool rotate)
{
    clearLayouts(leaderLayout);
    CardView* cardView = new CardView(leader, CARD_SIZE*1.7);
    leaderView = cardView;
    cardView->setFixedSize(130,130);
    leaderLayout->addWidget(cardView);
    if (!leader->isActive() || rotate){
        cardView->rotateCard();
    }
    connect(cardView, &QPushButton::clicked, this, [cardView, this](){PlayerArea::cardButtonPressed(cardView);});
}

void PlayerArea::displayGraveyard(){
    Card* toDisplay = ApiLogic::getLastGrave(player);
    if(!toDisplay) return;
    QPixmap imageGraveyard(QString::fromStdString(toDisplay->getArtPath()));
    QIcon graveyardIcon(imageGraveyard);
    graveyard->setIcon(graveyardIcon);
}


void PlayerArea::displayStage(Card *stage)
{
    Debug::LogEnv("PlayerArea::displayStage");
    if(!stage){
        return;
    }
    clearLayouts(stageLayout);
    CardView* cardView = new CardView(stage, CARD_SIZE);
    stageView = cardView;
    cardView->setFixedSize(80,80);
    stageLayout->addWidget(stageView);

    // CONNECT
    //connect();
}

void PlayerArea::clearLayouts(QHBoxLayout *layout)
{
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            layout->removeWidget(widget);
            widget->deleteLater();
        }
        delete item;
    }
}

void PlayerArea::updateGui(bool changeTurn)
{
    displayLeader(player->getLeader());
    displayGround(player->getGround());
    displayHand(player->getHand());
    displayStage(player->getStage());
    displayGraveyard();
    int dons = ApiLogic::getAvailableDon(player);
    donText->setText("ACTIVE DON : " + QString::number(dons));
    std::string lifeString = std::to_string(player->getLife());
    lifesText->setText(QString::fromStdString("-  LIFES: " + lifeString));
    if(changeTurn) changePlayerTextColor();

}

void PlayerArea::changePlayerTextColor()
{
    if(player == FSM::getCurrentPlayer())
    {
        playerIndicator->setStyleSheet("color: red;");
    }
    else{
        playerIndicator->setStyleSheet("color: black;");
    }
}

void PlayerArea::showCounterButton()
{
    if(player != FSM::getCurrentPlayer())
        counterButton->setHidden(false);
}

void PlayerArea::deckButtonPressed()
{
    Card* newCard = FSM::drawCardRequest(player);
    if(!newCard){
        GameWindow::showEndGame(ApiLogic::getOpponent(player)->getName());
        return;
    }
    CardView* newCardView = new CardView(newCard, CARD_SIZE);
    handLayout->addWidget(newCardView);
    connect(newCardView, &QPushButton::clicked, this, [newCardView, this](){PlayerArea::cardButtonPressed(newCardView);});
    GameWindow::updateGameStatus();
}

// USARE FSM PER SAPERE QUANTI DON ATTIVI HA IL CURRENTPLAYER
void PlayerArea::donButtonPressed()
{
    int dons = ApiLogic::getAvailableDon(player);
    if(FSM::getCurrentState() == Enums::DrawDon){
        FSM::drawDonRequest(player);
        dons = ApiLogic::getAvailableDon(player);
    }else if(dons > 0){
        FSM::selectCardRequest(player->getDonList().at(dons-1));
        bufferDon = player->getDonList().at(dons-1);
    }
    donText->setText("ACTIVE DON : " + QString::number(dons));
    GameWindow::updateGameStatus();
    PlayerArea::displayGround(player->getGround());

}

void PlayerArea::displayHand(std::vector<Card*> hand)
{
    clearLayouts(handLayout);

    for(int i = 0; i < (int)hand.size(); i++)
    {
        CardView* cardView = new CardView(hand.at(i), CARD_SIZE);
        handLayout->addWidget(cardView);
        connect(cardView, &QPushButton::clicked, this, [cardView, this](){PlayerArea::cardButtonPressed(cardView);});

    }
}

void PlayerArea::displayGround(std::vector<Card *> ground, Card* rotateCard)
{
    clearLayouts(groundLayout);

    std::cout << "DISPLAYING GROUND" << std::endl;

    for(int i = 0; i < (int)ground.size(); i++)
    {
        CardView* cardView = new CardView(ground.at(i), CARD_SIZE);
        groundLayout->addWidget(cardView);
        if (!ground.at(i)->isActive() || ground.at(i) == rotateCard){
            cardView->rotateCard();
        }
        connect(cardView, &QPushButton::clicked, this, [cardView, this](){PlayerArea::cardButtonPressed(cardView);});
    }
}

void PlayerArea::cardButtonPressed(CardView* cardview)
{
    std::cout << "Button pressed"<< std::endl;
    if(FSM::getCurrentState() == Enums::AttachDon){
        FSM::attachDonRequest(cardview->getCard(), bufferDon);
    }else{
        FSM::selectCardRequest(cardview->getCard());
    }
    if(FSM::getCurrentState() != Enums::State::CounterPhase)
    this->updateGui();
    else if (FSM::getCurrentState() == Enums::State::CounterPhase && FSM::getCurrentPlayer() != player)
    this->updateGui();
    GameWindow::updateGameStatus();
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && FSM::getCurrentPlayer() == player){
        displayGround(player->getGround(), cardview->getCard());
    }
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && cardview->getCard() == player->getLeader()){
        PlayerArea::displayLeader(player->getLeader(), true);
    }
    if(FSM::getCurrentState() == Enums::State::CounterPhase)
    {
        showCounterButton();
        return;
    }
    if(FSM::getCurrentState() == Enums::State::EndGame)
    {
        GameWindow::showEndGame();
        return;
    }
    GameWindow::updateOpponent(this);

}

void PlayerArea::counterButtonPressed()
{
    FSM::battleRequest();
    counterButton->setHidden(true);
    updateGui();
    if(FSM::getCurrentState() == Enums::State::EndGame)
    {
        GameWindow::showEndGame();
        return;
    }
    GameWindow::updateGameStatus();
    GameWindow::updateOpponent(this);
}
