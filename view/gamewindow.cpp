#include "gamewindow.h"

#include <QFrame>
#include <QVBoxLayout>
#include "playerarea.h"

GameWindow::GameWindow(Player* player1, Player* player2, QWidget *parent)
    : QMainWindow{parent}
{
    QAction* save = new QAction("Save Game");
    QAction* save_as = new QAction("Save Game as...");
    QAction* load = new QAction("Load Game");

    QMenu* file = menuBar()->addMenu("File");
    file->addAction(save);
    file->addAction(save_as);
    file->addSeparator();
    file->addAction(load);

    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);
    frame->setFrameStyle(QFrame::Panel);



    PlayerArea* player1Area = new PlayerArea(player1, ApiLogic::getCardsOnHand(player1), ApiLogic::getCardsOnGround(player1), ApiLogic::getLeader(player1));
    PlayerArea* player2Area = new PlayerArea(player2, ApiLogic::getCardsOnHand(player2), ApiLogic::getCardsOnGround(player2), ApiLogic::getLeader(player2));

    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->addWidget(player1Area);

    QFrame* line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    layout->addWidget(player2Area);
    layout->setAlignment(Qt::AlignCenter);
}
