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

PlayerArea::PlayerArea(Player* player, std::vector<Card*> hand, std::vector<Card*> ground, Leader* leader, QWidget *parent)
    : QWidget(parent), player(player)
{
    QVBoxLayout* playerAreaLayout = new QVBoxLayout(this);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    playerAreaLayout->addLayout(mainLayout);

    QVBoxLayout* leftLayout = new QVBoxLayout();

    displayLeader(leader);
    displayGround(ground);
    displayHand(hand);
//    displayStage(???);

    // Setting FixedSize for groundLayout
    QWidget* groundContainer = new QWidget();
    groundLayout->setParent(groundContainer);
    groundContainer->setFixedSize(600, 100);
    groundContainer->setLayout(groundLayout);

    // Setting the alignments for ground and hand
    handLayout->setAlignment(Qt::AlignLeft);
    groundLayout->setAlignment(Qt::AlignLeft);

    // Setting a fixed size for handLayout
    QWidget* handContainer = new QWidget();
    handLayout->setParent(handContainer);
    handContainer->setFixedSize(600, 90);
    handContainer->setLayout(handLayout);

    // Adding the various layouts to the fieldLayout
    fieldLayout->addLayout(leaderLayout);
    fieldLayout->addWidget(groundContainer);
    fieldLayout->addLayout(stageLayout);
    fieldLayout->setAlignment(Qt::AlignLeft);

    leftLayout->addLayout(fieldLayout);
    leftLayout->addWidget(handContainer);

    QPushButton* deck = new QPushButton();
    QPixmap imageDeck("./assets/CardBackRegular.png");
    QIcon deckIcon(imageDeck);
    deck->setIcon(deckIcon);
    deck->setIconSize(CARD_SIZE);
    QPushButton* graveyard = new QPushButton();
    QPixmap imageGraveyard("./assets/EmptyCard.png");
    QIcon graveyardIcon(imageGraveyard);
    graveyard->setIcon(graveyardIcon);
    graveyard->setIconSize(CARD_SIZE);
    QPushButton* donDeck = new QPushButton();
    QPixmap imageDonDeck("./assets/Don.png");
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
    QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
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
}

PlayerArea::~PlayerArea()
{
    delete PlayerArea::handLayout;
    delete PlayerArea::groundLayout;
    delete PlayerArea::stageLayout;
    delete PlayerArea::donText;
    delete PlayerArea::playerIndicator;
    delete PlayerArea::lifesText;
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

void PlayerArea::displayStage(Card *stage)
{
//    clearLayouts(stageLayout);
//    CardView* cardView = new CardView(stage, CARD_SIZE);
//    stageView = cardView;
//    stageLayout->addWidget(stageView);

//    // CONNECT
//    connect();
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
//    displayStage(player->getStage());
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

void PlayerArea::deckButtonPressed()
{
    Card* newCard = FSM::drawCardRequest(player);
    if(!newCard) return;
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
    this->updateGui();
    GameWindow::updateGameStatus();
    if(FSM::getCurrentState() == Enums::SelectEnemyCard){
        displayGround(player->getGround(), cardview->getCard());
    }
    if(FSM::getCurrentState() == Enums::SelectEnemyCard && cardview->getCard() == player->getLeader()){
        PlayerArea::displayLeader(player->getLeader(), true);
    }
    if(FSM::getCurrentState() == Enums::State::EndGame)
    {
        GameWindow::showEndGame(player);
        return;
    }
    GameWindow::updateOpponent(this);

}
