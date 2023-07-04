#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QPushButton>
#include "./models/card/Card.h"

class CardView : public QPushButton
{
    Q_OBJECT
public:
    CardView(Card* card = nullptr, const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());
    Card* getCard();
    void rotateCard();

signals:

private:
    Card* _card;

};

#endif // CARDVIEW_H
