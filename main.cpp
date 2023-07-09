// Includes Qt header files
#include <QLabel>
#include <QHBoxLayout>
#include <QApplication>
#include "./view/lobbywindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LobbyWindow w;
  w.setFixedSize(900,680);
  w.setWindowTitle("CardPiece");
  QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
  w.setWindowIcon(*icon);
  w.show();
  return a.exec();
  
}
