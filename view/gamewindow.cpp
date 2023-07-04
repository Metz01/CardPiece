#include "gamewindow.h"

#include <QFrame>
#include <QVBoxLayout>

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

    QMenu* rules = menuBar()->addMenu("Rules");

    file->addAction(load);

    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);
    frame->setFrameStyle(QFrame::Panel);



    player1Area = new PlayerArea(player1, ApiLogic::getCardsOnHand(player1), ApiLogic::getCardsOnGround(player1), ApiLogic::getLeader(player1));
    player2Area = new PlayerArea(player2, ApiLogic::getCardsOnHand(player2), ApiLogic::getCardsOnGround(player2), ApiLogic::getLeader(player2));

    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->addWidget(player1Area);

    QHBoxLayout* midLayout = new QHBoxLayout();
    QFrame* lineA = new QFrame;
    lineA->setFrameShape(QFrame::HLine);
    lineA->setFrameShadow(QFrame::Sunken);
    midLayout->addWidget(lineA);
    QPushButton* endTurnButton = new QPushButton("END TURN");
    midLayout->addWidget(endTurnButton);
    QFrame* lineB = new QFrame;
    lineB->setFrameShape(QFrame::HLine);
    lineB->setFrameShadow(QFrame::Sunken);
    midLayout->addWidget(lineB);

    layout->addLayout(midLayout);
    layout->addWidget(player2Area);
    layout->setAlignment(Qt::AlignCenter);

    connect(endTurnButton, &QPushButton::clicked, this, &GameWindow::endTurnButtonPressed);
}

void GameWindow::endTurnButtonPressed()
{
    FSM::endTurnRequest();
    player1Area->updateGui();
    player2Area->updateGui();
}
