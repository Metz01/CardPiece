#ifndef CARDVIEWFACTORY_H
#define CARDVIEWFACTORY_H

#include "./view/cardview.h"
#include "./view/leaderview.h"
#include "./view/characterview.h"
#include "./view/effectview.h"
#include "./view/stageview.h"

class CardViewFactory
{
public:
    CardViewFactory();
    virtual CardView* createCard(Card*, const QSize&, QPushButton*) = 0;
};

class FactoryLeader : public CardViewFactory {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) override {
        return new LeaderView(card, size, button);
    }
};

class FactoryCharacter : public CardViewFactory {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) override {
        return new CharacterView(card, size, button);
    }
};

class FactoryEffect : public CardViewFactory {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) override {
        return new EffectView(card, size, button);
    }
};

class FactoryStage : public CardViewFactory {
public:
    CardView* createCard(Card* card, const QSize& size, QPushButton* button) override {
        return new StageView(card, size, button);
    }
};

#endif // CARDVIEWFACTORY_H
