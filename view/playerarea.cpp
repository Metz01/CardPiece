#include "playerarea.h"

#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include "cardview.h"

PlayerArea::PlayerArea(QWidget *parent)
    : QWidget{parent}
{
    const QSize CARD_SIZE = QSize(120,168);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10,10,10,10);

    QVBoxLayout* leftLayout = new QVBoxLayout(this);

    QHBoxLayout* topLeftLayout = new QHBoxLayout(this);

    CardView* leader = new CardView("./assets/OP01-002.png", CARD_SIZE*2.0);
    leader->setFixedSize(400,400);
//    QPixmap leaderImage("./assets/OP01-002.png");
//    QIcon leaderIcon(leaderImage);
//    leader->setIcon(leaderIcon);
//    leader->setIconSize(CARD_SIZE*1.5);
    topLeftLayout->addWidget(leader);

    QHBoxLayout* fieldLayout = new QHBoxLayout(this);
    for(int i = 0; i < 5; i++)
    {
        CardView* card = new CardView("./assets/EmptyCard.png", CARD_SIZE);
//        QPixmap imageCard("./assets/EmptyCard.png");
//        QIcon cardIcon(imageCard);
//        card->setIcon(cardIcon);
//        card->setIconSize(CARD_SIZE);
//        card->setText(" ");
        fieldLayout->addWidget(card);
    }
    topLeftLayout->addLayout(fieldLayout);

    QHBoxLayout* bottomLeftLayout = new QHBoxLayout(this);
    for(int i = 0; i < 7; i++)
    {
        CardView* card = new CardView("./assets/OP01-006.png", CARD_SIZE);
//        QPixmap imageCard("./assets/OP01-006.png");
//        QIcon cardIcon(imageCard);
//        card->setIcon(cardIcon);
//        card->setIconSize(CARD_SIZE);
//        card->setText(" ");
        bottomLeftLayout->addWidget(card);
    }

    leftLayout->addLayout(topLeftLayout);
    leftLayout->addLayout(bottomLeftLayout);

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
    QVBoxLayout* rightLayout = new QVBoxLayout(this);
    rightLayout->addWidget(deck);
    rightLayout->addWidget(graveyard);
    rightLayout->addWidget(donDeck);

    mainLayout->addLayout(leftLayout);
    QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addSpacerItem(horizontalSpacer);
    mainLayout->addLayout(rightLayout);

    //    QPushButton* leader = new QPushButton();

    //    QGridLayout* field = new QGridLayout(this);
    //    //field->setFrameStyle(QFrame::Panel);

    //    QHBoxLayout* hand = new QHBoxLayout(this);
    //    //hand->setFrameStyle(QFrame::Panel);
}
