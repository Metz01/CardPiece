#include "creator.h"

Creator::Creator()
{

}

CardView *Creator::getCardView(Card *card, const QSize &size, QPushButton *button)
{
    if(card->getCardType() == Enums::CardType::leader)
    {
        FactoryLeader* lf = new FactoryLeader();
        return lf->createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::character)
    {
        FactoryCharacter* cf = new FactoryCharacter();
        return cf->createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::event)
    {
        FactoryEffect* ef = new FactoryEffect();
        return ef->createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::stage)
    {
        FactoryStage* sf = new FactoryStage();
        return sf->createCard(card, size, button);
    }
    else return NULL;
}
