#ifndef CARD_W_H
#define CARD_W_H

#include <QLabel>
#include <QWidget>
#include "../models/Card.h"

template <typename T>
class CardWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *artWork;
    T *_card;
public:
    CardWidget(T *card, QWidget* parent = 0);
    void refresh();
    std::string getInfo();
    Card* getCard();
};

#endif