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
#include "./view/creator.h"

class PlayerArea : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerArea(Player* player, QWidget *parent = nullptr);

    const QSize CARD_SIZE = QSize(40,56);

    void displayHand(std::vector<Card*> hand);
    void displayGround(std::vector<Card*>, Card* rotateCard = nullptr);
    void displayLeader(Card*, bool rotate = false);
    void displayStage(Card*);
    void displayGraveyard();
    void clearLayouts(QHBoxLayout* layout);
    void updateGui(bool = false);
    void changePlayerTextColor();
    void showCounterButton();

    ~PlayerArea();
signals:

private:
    Creator creator;
    CardView* leaderView;
    CardView* stageView;
    Don* bufferDon;
    Player* player;
    QHBoxLayout* handLayout = new QHBoxLayout();
    QHBoxLayout* groundLayout = new QHBoxLayout();
    QHBoxLayout* fieldLayout = new QHBoxLayout();
    QHBoxLayout* leaderLayout = new QHBoxLayout();
    QLabel* donText = new QLabel();
    QLabel* playerIndicator = new QLabel();
    QLabel* lifesText = new QLabel();
    QHBoxLayout* stageLayout = new QHBoxLayout();
    QPushButton* counterButton;
    QPushButton* graveyard;


public slots:
    void deckButtonPressed();
    void donButtonPressed();
    void cardButtonPressed(CardView*);
    void counterButtonPressed();

};

#endif // PLAYERAREA_H
