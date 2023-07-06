// Includes Qt header files
#include <QLabel>
#include <QHBoxLayout>
#include <QApplication>
#include "./utils/Utils.h"
#include "./widgets/Main_window.h"
#include "./models/card/card_types/Leader.h"
#include "./utils/Enums.h"
#include "./utils/database_helper.h"
#include "./models/Player.h"
#include "./utils/Debug.h"
#include "./fsm/fsm.h"
#include "./fsm/api/api_logic.h"
#include "./utils/Constants.h"
#include "./utils/Save.h"
#include "./view/gamewindow.h"
#include "./view/lobbywindow.h"


void _setup(Player* p1, Player* p2)
{


  ApiLogic(p1, p2);
  FSM fms(p1);
//  Card* card = FSM::drawCardRequest();
//  FSM::drawDonRequest();
//  FSM::selectCardRequest(card);
//  FSM::endTurnRequest();
  Debug::LogDebug("********* End Turn **********");
//  Card* card2 = FSM::drawCardRequest();
//  std::vector<Don*> don = FSM::drawDonRequest();
//  FSM::selectCardRequest(card2);
//  int info = card2->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
//  Debug::LogError("Card attack befor don: " + std::to_string(info));
//  FSM::selectCardRequest(don[0]);
//  FSM::attachDonRequest(card2, don[0]);
//  info = card2->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
//  Debug::LogError("Card attack after don: " + std::to_string(info));
//  FSM::selectCardRequest(card2);
//  FSM::selectEnemyCardRequest(card2, card);
//  //p1->print();
//  //p2->print();
//  FSM::endTurnRequest();
//  Debug::LogDebug("********* End Turn **********");
//  Card* card3 = FSM::drawCardRequest();
//  Debug::LogError(card3->getCardInfo(Enums::InfoAttribute::Name)->value.name);
//  FSM::drawDonRequest();
//  //p1->print();
//  //p2->print();
//  FSM::endTurnRequest();
//  Debug::LogDebug("********* End Turn **********");
//  Card* card4 = FSM::drawCardRequest();
//  FSM::drawDonRequest();
//  p2->print();
//  Leader* lead = p2->getLeader();
//  ApiLogic::saveGame(p1,p2,"./assets/saves/test1");
//  FSM::selectCardRequest(card4);
//  FSM::selectCardRequest(lead);
//  p2->print();
//  int att = lead->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
//  Debug::LogDebug("Card attack befor reset with buff: " + std::to_string(att));
//  FSM::endTurnRequest();
//  Debug::LogDebug("********* End Turn **********");
//  att = lead->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
//  Debug::LogDebug("Card attack after reset: " + std::to_string(att));
}

void _testFunctions()
{
  Debug::LogDebug("Test function");
  return;
}

//int main(int argc, char *argv[])
//{
//  QApplication app(argc, argv);
//  _setup();
//  _testFunctions();
//  Main_window *mw = new Main_window();
//  mw->resize(1920, 1080);
//  mw->show();

//  return app.exec();
//}

int main(int argc, char *argv[])
{
//  DatabaseHelper();
//  Player *p1 = new Player(DECK1_PATH, "Alex");
//  Player *p2 = new Player(DECK1_PATH, "Mark");
//  _setup(p1, p2);
  QApplication a(argc, argv);
  LobbyWindow w;
  w.setFixedSize(900,680);
  w.setWindowTitle("CARD PIECE SIMULATOR");
  QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
  w.setWindowIcon(*icon);
  w.show();
  return a.exec();
  
}
