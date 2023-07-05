#include "gamewindow.h"
#include "lobbywindow.h"
#include <QFrame>
#include <QVBoxLayout>

QLabel* GameWindow::gameStatusLabel = NULL;
PlayerArea* GameWindow::player1Area = NULL;
PlayerArea* GameWindow::player2Area = NULL;
GameWindow* GameWindow::game = NULL;
QDialog* GameWindow::dialog = NULL;

GameWindow::GameWindow(Player* player1, Player* player2, QWidget *parent)
    : QMainWindow{parent}
{
    game = this;

    QAction* save = new QAction("Save Game", this);
    QAction* save_as = new QAction("Save Game as...", this);

    std::string path = "./assets/saves";

    connect(save, &QAction::triggered, this, [path, this]{GameWindow::saveGame();});

    QMenu* file = menuBar()->addMenu("File");
    file->addAction(save);
    file->addAction(save_as);



    QMenu* rules = menuBar()->addMenu("Rules");

    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);

    player1Area = new PlayerArea(player1, ApiLogic::getCardsOnHand(player1), ApiLogic::getCardsOnGround(player1), ApiLogic::getLeader(player1));
    player2Area = new PlayerArea(player2, ApiLogic::getCardsOnHand(player2), ApiLogic::getCardsOnGround(player2), ApiLogic::getLeader(player2));

    QVBoxLayout* layout = new QVBoxLayout(frame);
    gameStatusLabel = new QLabel();
    gameStatusLabel->setText(QString::fromStdString("Current State is: " + EnumsHelper::ToString(FSM::getCurrentState())));
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
    player1Area->updateGui();
    player2Area->updateGui();

}

GameWindow::~GameWindow()
{
    delete GameWindow::gameStatusLabel;
    delete GameWindow::player1Area;
    delete GameWindow::player2Area;
}

void GameWindow::updateGameStatus()
{
    gameStatusLabel->setText(QString::fromStdString("Current State is: " + EnumsHelper::ToString(FSM::getCurrentState())));
}

void GameWindow::updateOpponent(PlayerArea* myPlayerArea)
{
    if(myPlayerArea == player1Area){
        player2Area->updateGui(false);
    }else if(myPlayerArea == player2Area){
        player1Area->updateGui(false);
    }
}

void GameWindow::showEndGame(Player *player)
{
    dialog = new QDialog();
    dialog->setWindowTitle("EndGame");

    QLabel* textLabel = new QLabel(QString::fromStdString(player->getName() + " WINS!"));
    textLabel->setAlignment(Qt::AlignCenter);

    QPushButton* newGameButton = new QPushButton("New Game");
    QPushButton* closeButton = new QPushButton("Close Game");

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();

    buttonsLayout->addWidget(newGameButton);
    buttonsLayout->addWidget(closeButton);

    mainLayout->addWidget(textLabel);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->setAlignment(Qt::AlignCenter);

    dialog->setLayout(mainLayout);

    QObject::connect(closeButton, &QPushButton::clicked, game, &GameWindow::closeEndGame);

    dialog->resize(300, 150);

    dialog->exec();
}

void GameWindow::saveGame(std::string path)
{
    QString savesFolder(QDir::currentPath() + QString::fromStdString(path));
    QString filePath = QFileDialog::getSaveFileName(game, "Save Game", savesFolder, "Deck (*.txt)");
    ApiLogic::saveGame(filePath.toStdString());
}

void GameWindow::endTurnButtonPressed()
{
    FSM::endTurnRequest();
    player1Area->updateGui(true);
    player2Area->updateGui(true);
    updateGameStatus();
}

void GameWindow::closeEndGame()
{
    LobbyWindow::lobby->show();

    delete GameWindow::dialog;
    delete GameWindow::game;
}


