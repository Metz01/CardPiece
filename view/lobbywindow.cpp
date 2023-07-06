#include "lobbywindow.h"

LobbyWindow* LobbyWindow::lobby = NULL;

LobbyWindow::LobbyWindow(QWidget *parent)
    : QMainWindow{parent}
{
    lobby = this;

    QFrame* frame = new QFrame(this);
    setCentralWidget(frame);

    // Main Layout creation
    QHBoxLayout* mainLayout = new QHBoxLayout(frame);
    mainLayout->setAlignment(Qt::AlignHCenter);

    // Vertical Layouts creation
    QVBoxLayout *ngLayout = new QVBoxLayout();
    ngLayout->setAlignment(Qt::AlignCenter);
    ngLayout->setContentsMargins(0,0,0,0);
    QVBoxLayout *lgLayout = new QVBoxLayout();
    lgLayout->setAlignment(Qt::AlignCenter);
    lgLayout->setContentsMargins(85,0,85,0);

    QLabel* ngLabel = new QLabel("<b>NEW GAME</b>");
    ngLabel->setAlignment(Qt::AlignCenter);
    ngLabel->setFixedSize(250,50);
    ngLayout->addWidget(ngLabel);

    QHBoxLayout* player1Layout = new QHBoxLayout();
    QHBoxLayout* player2Layout = new QHBoxLayout();

    player1LineEdit->setPlaceholderText("Player1 Name");
    player1LineEdit->setFixedWidth(100);

    player2LineEdit->setPlaceholderText("Player2 Name");
    player2LineEdit->setFixedWidth(100);

    player1Button->setText("Select Deck...");
    player1Button->setFixedSize(100,25);
    connect(player1Button, &QPushButton::clicked, this, &LobbyWindow::selectDeck1File);
    player2Button->setText("Select Deck...");
    player2Button->setFixedSize(100,25);
    connect(player2Button, &QPushButton::clicked, this, &LobbyWindow::selectDeck2File);

    startButton->setText("START NEW GAME");
    connect(startButton, &QPushButton::clicked, this, &LobbyWindow::openGameWindow);

    player1Layout->addWidget(player1LineEdit);
    player1Layout->addWidget(player1Button);
    player2Layout->addWidget(player2LineEdit);
    player2Layout->addWidget(player2Button);

    ngLayout->addLayout(player1Layout);
    ngLayout->addLayout(player2Layout);
    ngLayout->addWidget(startButton);

    QLabel* lgLabel = new QLabel("<b>LOAD GAME</b>");
    lgLabel->setAlignment(Qt::AlignCenter);
    lgLabel->setFixedSize(250,50);
    lgLayout->addWidget(lgLabel);

    loadButton->setText("LOAD GAME");
    connect(loadButton, &QPushButton::clicked, this, &LobbyWindow::loadGameWindow);
    lgLayout->addWidget(lgLabel);
    lgLayout->addWidget(loadButton);

    // Main Layout assignments
    mainLayout->addLayout(ngLayout);
    QFrame* line = new QFrame;
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);
    mainLayout->addLayout(lgLayout);
}

void LobbyWindow::selectDeck1File()
{
    QString decksFolder(QDir::currentPath() + "/assets/deck");
    QString filePath = QFileDialog::getOpenFileName(this, "Select Deck for Player1", decksFolder);
    deck1Path = filePath;
    if(deck1Path == "") return;
    QFileInfo fileInfo(filePath);
    QString baseName = fileInfo.baseName();
    player1Button->setText(baseName);
}

void LobbyWindow::selectDeck2File()
{
    QString decksFolder(QDir::currentPath() + "/assets/deck");
    QString filePath = QFileDialog::getOpenFileName(this, "Select Deck for Player2", decksFolder);
    deck2Path = filePath;
    if(deck2Path == "") return;
    QFileInfo fileInfo(filePath);
    QString baseName = fileInfo.baseName();
    player2Button->setText(baseName);
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

void LobbyWindow::loadGameWindow()
{
    QString savesFolder(QDir::currentPath() + "/assets/saves");
    QString filePath = QFileDialog::getOpenFileName(this, "Select Game to load", savesFolder);
    std::string path = filePath.toStdString();
    if(path == "") return;
    DatabaseHelper();
    Player *p1 = Save::loadPlayer(path, "Player1");;
    Player *p2 = Save::loadPlayer(path, "Player2");;
    ApiLogic(p1, p2);
    if(Save::loadCurrentPlayer(path) == p1->getName())
        FSM fsm(p1, Save::loadState(path));
    else if(Save::loadCurrentPlayer(path) == p2->getName())
        FSM fsm(p2, Save::loadState(path));
    else return;
    w = new GameWindow(p1,p2);
    w->show();

    hide();
}

void LobbyWindow::clearWindow()
{
//    w->close();
}
