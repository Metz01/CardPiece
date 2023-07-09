#include "creator.h"

Creator::Creator()
{

}

CardView *Creator::getCardView(Card *card, const QSize &size, QPushButton *button)
{
    if(card->getCardType() == Enums::CardType::leader)
    {
        FactoryLeader lf = FactoryLeader();
        return lf.createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::character)
    {
        FactoryCharacter cf =FactoryCharacter();
        return cf.createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::event)
    {
        FactoryEffect ef = FactoryEffect();
        return ef.createCard(card, size, button);
    }
    else if(card->getCardType() == Enums::CardType::stage)
    {
        FactoryStage sf = FactoryStage();
        CardView* c = sf.createCard(card, size, button);
        return c;
    }
    else return NULL;
}
