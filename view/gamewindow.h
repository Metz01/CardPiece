#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QDialog>

#include "./models/Player.h"
#include "./view/playerarea.h"

class LobbyWindow;

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(Player* player1 = nullptr, Player* player2 =  nullptr, QWidget *parent = nullptr);

    ~GameWindow();

    static QLabel* gameStatusLabel;
    static void updateGameStatus();
    static void updateOpponent(PlayerArea* myPlayerArea);
    static PlayerArea* player1Area;
    static PlayerArea* player2Area;
    static void showEndGame();
    static GameWindow* game;
    void saveGame(std::string path = "/assets/saves");
    static void showRules();
signals:

private:
    void endTurnButtonPressed();
    static void closeEndGame();
    static QDialog* dialog;

};

#endif // GAMEWINDOW_H
