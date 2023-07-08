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
    if(deck2Path == "" || deck2Path == "")
    {
        openErrorPopUp("Select Decks.");
        return;
    }
    Player *p1 = new Player(deck1Path.toStdString(), player1LineEdit->text().toStdString());
    Player *p2 = new Player(deck2Path.toStdString(), player2LineEdit->text().toStdString());
    if(!ApiLogic::checkPlayerIntegrity(p1) || !ApiLogic::checkPlayerIntegrity(p2))
    {
        openErrorPopUp("<p>Error in load Players' info.</p> <p>Check you inserted Players' names</p> <p> Check that files of Decks are correctly formatted.</p>");
        return;
    }
    ApiLogic(p1, p2);
    FSM fsm(p1);
    w = new GameWindow(p1,p2);
    w->setFixedSize(900,680);
    w->setWindowTitle("CARD PIECE SIMULATOR");
    QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
    w->setWindowIcon(*icon);
    w->show();

    hide();
}

void LobbyWindow::loadGameWindow()
{
    QString savesFolder(QDir::currentPath() + "/assets/saves");
    QString filePath = QFileDialog::getOpenFileName(this, "Select Game to load", savesFolder);
    std::string path = filePath.toStdString();
    if(path == "")
    {
        openErrorPopUp("Select a file to load.");
        return;
    }
    DatabaseHelper();
    Player *p1 = Save::loadPlayer(path, "Player1");
    Player *p2 = Save::loadPlayer(path, "Player2");
    if(!ApiLogic::checkPlayerIntegrity(p1, true) || !ApiLogic::checkPlayerIntegrity(p2, true))
    {
        openErrorPopUp("JSON file not correctly formatted.");
        return;
    }
    ApiLogic(p1, p2);
    if(Save::loadCurrentPlayer(path) == p1->getName())
        FSM fsm(p1, Save::loadCurrentTurn(path), Save::loadState(path));
    else if(Save::loadCurrentPlayer(path) == p2->getName())
        FSM fsm(p2, Save::loadCurrentTurn(path), Save::loadState(path));
    else
    {
        openErrorPopUp("The current Player in JSON file is not one of the Players.");
        return;
    }
    w = new GameWindow(p1,p2);
    w->setFixedSize(900,680);
    w->setWindowTitle("CARD PIECE SIMULATOR");
    QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
    w->setWindowIcon(*icon);
    w->show();

    hide();
}

void LobbyWindow::openErrorPopUp(std::string errorText)
{
    QDialog* popUp = new QDialog();
    popUp->setWindowTitle("ERROR");

    QLabel* textLabel = new QLabel(QString::fromStdString(errorText));
    textLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(textLabel);
    popUp->setLayout(layout);

    popUp->setFixedSize(300,150);
    QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
    popUp->setWindowIcon(*icon);

    popUp->exec();
}

void LobbyWindow::clearWindow()
{
//    w->close();
}
