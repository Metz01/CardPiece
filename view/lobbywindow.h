#ifndef LOBBYWINDOW_H
#define LOBBYWINDOW_H

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QGridLayout>
#include <QMainWindow>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

#include "./models/Player.h"
#include "./fsm/api/api_logic.h"
#include "./fsm/fsm.h"
#include "./view/gamewindow.h"

class LobbyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LobbyWindow(QWidget *parent = nullptr);
    void selectDeck1File();
    void selectDeck2File();
    void openGameWindow();
    void loadGameWindow();
    static LobbyWindow* lobby;
    static void clearWindow();

signals:

private:
    QLineEdit* player1LineEdit = new QLineEdit();
    QLineEdit* player2LineEdit = new QLineEdit();
    QPushButton* player1Button = new QPushButton();
    QPushButton* player2Button = new QPushButton();
    QPushButton* startButton = new QPushButton();
    QPushButton* loadButton = new QPushButton();

    QString player1Name;
    QString player2Name;
    QString deck1Path;
    QString deck2Path;

    GameWindow* w;
};

#endif // LOBBYWINDOW_H
