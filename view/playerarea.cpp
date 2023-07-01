#include "playerarea.h"

#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include "cardview.h"

PlayerArea::PlayerArea(std::vector<Card*> hand, std::vector<Card*> ground, Leader* leader, QWidget *parent)
    : QWidget(parent)
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
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(deck);
    rightLayout->addWidget(graveyard);
    rightLayout->addWidget(donDeck);

    mainLayout->addLayout(leftLayout);
    QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addSpacerItem(horizontalSpacer);
    mainLayout->addLayout(rightLayout);
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

void PlayerArea::displayHand(std::vector<Card*> hand)
{
    clearLayouts(handLayout);

    for(int i = 0; i < (int)hand.size(); i++)
    {
        CardView* cardView = new CardView(hand.at(i), CARD_SIZE);
        handLayout->addWidget(cardView);
    }
}
