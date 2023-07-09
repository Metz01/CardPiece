#ifndef CARDVIEWFACTORY_H
#define CARDVIEWFACTORY_H

#include "./view/cardview.h"
#include "./view/leaderview.h"
#include "./view/characterview.h"
#include "./view/effectview.h"
#include "./view/stageview.h"

class FactoryLeader{
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) {
        return new LeaderView(card, size, button);
    }
};

class FactoryCharacter {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) {
        return new CharacterView(card, size, button);
    }
};

class FactoryEffect {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) {
        return new EffectView(card, size, button);
    }
};

class FactoryStage {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) {
        return new StageView(card, size, button);
    }
};

#endif // CARDVIEWFACTORY_H
