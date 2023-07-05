#include "lobbywindow.h"

LobbyWindow::LobbyWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);

    QVBoxLayout* mainLayout = new QVBoxLayout(frame);
    QHBoxLayout* player1Layout = new QHBoxLayout();
    QHBoxLayout* player2Layout = new QHBoxLayout();

    player1LineEdit->setPlaceholderText("Enter Player1 Name");
    player2LineEdit->setPlaceholderText("Enter Player2 Name");

    player1Button->setText("Select a Deck for Player1");
    connect(player1Button, &QPushButton::clicked, this, &LobbyWindow::selectDeck1File);
    player2Button->setText("Select a Deck for Player2");
    connect(player2Button, &QPushButton::clicked, this, &LobbyWindow::selectDeck2File);

    startButton->setText("Start New Game");
    connect(startButton, &QPushButton::clicked, this, &LobbyWindow::openGameWindow);

    player1Layout->addWidget(player1LineEdit);
    player1Layout->addWidget(player1Button);
    player2Layout->addWidget(player2LineEdit);
    player2Layout->addWidget(player2Button);

    mainLayout->addLayout(player1Layout);
    mainLayout->addLayout(player2Layout);
    mainLayout->addWidget(startButton);
}

void LobbyWindow::selectDeck1File()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select Deck for Player1");
    deck1Path = filePath;
}

void LobbyWindow::selectDeck2File()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select Deck for Player2");
    deck2Path = filePath;
}

void LobbyWindow::openGameWindow()
{
    DatabaseHelper();
    Player *p1 = new Player(deck1Path.toStdString(), player1LineEdit->text().toStdString());
    Player *p2 = new Player(deck2Path.toStdString(), player2LineEdit->text().toStdString());
    ApiLogic(p1, p2);
    FSM fsm(p1);
    w = new GameWindow(p1,p2);
    w->show();

    hide();
}
