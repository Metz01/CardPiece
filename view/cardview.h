#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QContextMenuEvent>
#include <QDialog>
#include <QDir>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QTransform>
#include <iostream>

#include "./models/card/Card.h"
#include "./fsm/fsm.h"
#include "./fsm/api/api_logic.h"

class GameWindow;
class PlayerArea;
class CardView : public QPushButton
{
    Q_OBJECT
public:
    CardView(Card* card = nullptr, QPushButton* button = new QPushButton());
    Card* getCard();
    void rotateCard();
    void contextMenuEvent(QContextMenuEvent* event) override;
    virtual bool pressedCard(Player* player, PlayerArea* area, Don* don = NULL) = 0;

    ~CardView();

protected:
    void setup(Card*, const QSize&, QLabel*);
    Card* _card;
signals:

private:
    QLabel* imageLabel;
    QPixmap* pixmap;
    bool activeCard = true;
    QSize _size;

};

#endif // CARDVIEW_H
