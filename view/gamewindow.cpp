#include "gamewindow.h"

#include <QFrame>
#include <QVBoxLayout>

QLabel* GameWindow::gameStatusLabel = NULL;

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

    QMenu* rules = menuBar()->addMenu("Rules");

    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);

    player1Area = new PlayerArea(player1, ApiLogic::getCardsOnHand(player1), ApiLogic::getCardsOnGround(player1), ApiLogic::getLeader(player1));
    player2Area = new PlayerArea(player2, ApiLogic::getCardsOnHand(player2), ApiLogic::getCardsOnGround(player2), ApiLogic::getLeader(player2));

    QVBoxLayout* layout = new QVBoxLayout(frame);
    gameStatusLabel = new QLabel();
    gameStatusLabel->setText(QString::fromStdString("Current State is: Draw"));
    gameStatusLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(gameStatusLabel);

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
    layout->setContentsMargins(0,0,0,0);

    connect(endTurnButton, &QPushButton::clicked, this, &GameWindow::endTurnButtonPressed);
}

void GameWindow::updateGameStatus()
{
    gameStatusLabel->setText(QString::fromStdString("Current State is: " + EnumsHelper::ToString(FSM::getCurrentState())));
}

void GameWindow::endTurnButtonPressed()
{
    FSM::endTurnRequest();
    player1Area->updateGui();
    player2Area->updateGui();
    updateGameStatus();
}
