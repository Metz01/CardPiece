#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>

#include "./fsm/api/api_logic.h"
#include "./models/Player.h"
#include "playerarea.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(Player* player1 = nullptr, Player* player2 =  nullptr, QWidget *parent = nullptr);

    static QLabel* gameStatusLabel;
    static void updateGameStatus();

signals:

private:
    void endTurnButtonPressed();
    PlayerArea* player1Area;
    PlayerArea* player2Area;
};

#endif // GAMEWINDOW_H
