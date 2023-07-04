#ifndef PLAYERAREA_H
#define PLAYERAREA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

#include <vector>
#include "./models/card/Card.h"
#include "./models/card/card_types/Leader.h"
#include "./view/cardview.h"
#include "./fsm/fsm.h"

class PlayerArea : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerArea(Player* player,
                        std::vector<Card*> hand = std::vector<Card*>(),
                        std::vector<Card*> field = std::vector<Card*>(),
                        Leader* leader = new Leader(),
                        QWidget *parent = nullptr);

    const QSize CARD_SIZE = QSize(40,56);

    void displayHand(std::vector<Card*> hand);
    void displayGround(std::vector<Card*>, Card* rotateCard = nullptr);
    void displayLeader(Leader*, bool rotate = false);
    void clearLayouts(QHBoxLayout* layout);
    void updateGui(bool = false);
    void changePlayerTextColor();

signals:

private:
    CardView* leaderView;
    CardView* bufferCardView;
    Don* bufferDon;
    Player* player;
    QHBoxLayout* handLayout = new QHBoxLayout();
    QHBoxLayout* groundLayout = new QHBoxLayout();
    QHBoxLayout* fieldLayout = new QHBoxLayout();
    QHBoxLayout* leaderLayout = new QHBoxLayout();
    QLabel* donText = new QLabel();
    QLabel* playerIndicator = new QLabel();


public slots:
    void deckButtonPressed();
    void donButtonPressed();
    void cardButtonPressed(CardView*);

};

#endif // PLAYERAREA_H
