#include "playerarea.h"

#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "cardview.h"
#include "./fsm/api/api_logic.h"

PlayerArea::PlayerArea(Player* player, std::vector<Card*> hand, std::vector<Card*> ground, Leader* leader, QWidget *parent)
    : QWidget(parent), player(player)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10,10,10,10);

    QVBoxLayout* leftLayout = new QVBoxLayout();

    displayLeader(leader);
    displayGround(ground);
    displayHand(hand);

    fieldLayout->addLayout(groundLayout);

    leftLayout->addLayout(fieldLayout);
    leftLayout->addLayout(handLayout);

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
    donText->setText("DON: 0");
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(deck);
    rightLayout->addWidget(graveyard);
    rightLayout->addWi_currentPlayerdget(donDeck);
    rightLayout->addWidget(donText);
    rightLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(leftLayout);
    QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addSpacerItem(horizontalSpacer);
    mainLayout->addLayout(rightLayout);

    // Connections
    connect(deck, &QPushButton::clicked, this, &PlayerArea::deckButtonPressed);
}

void PlayerArea::displayGround(std::vector<Card *> ground)
{
    clearLayouts(groundLayout);

    for(int i = 0; i < (int)ground.size(); i++)
    {
        CardView* cardView = new CardView(ground.at(i), CARD_SIZE);
        groundLayout->addWidget(cardView);
    }
}

void PlayerArea::displayLeader(Leader *leader)
{
    CardView* cardView = new CardView(leader, CARD_SIZE*2.0);
    leaderView = cardView;

    cardView->setFixedSize(400,400);
    fieldLayout->addWidget(cardView);
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

void PlayerArea::deckButtonPressed()
{
    Card* newCard = FSM::drawCardRequest(player);
    if(!newCard) return;
    CardView* newCardView = new CardView(newCard, CARD_SIZE);
    handLayout->addWidget(newCardView);
}

// USARE FSM PER SAPERE QUANTI DON ATTIVI HA IL CURRENTPLAYER
void PlayerArea::donButtonPressed()
{
    if(FSM::drawDonRequest(player).size() == 0) return;
    int dons = ApiLogic::getAvailableDon(player);
    donText->setText(std::to_string("DON: " + dons));
}

void PlayerArea::displayHand(std::vector<Card*> hand)
{
    clearLayouts(handLayout);

    for(int i = 0; i < (int)hand.size(); i++)
    {
        CardView* cardView = new CardView(hand.at(i), CARD_SIZE);
        handLayout->addWidget(cardView);
    }
}
