#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QPushButton>
#include <QLabel>
#include <QPixmap>
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
    QLabel* imageLabel;
    QPixmap* pixmap;
    bool activeCard = true;
    QSize _size;

};

#endif // CARDVIEW_H
