// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include "./utils/Utils.h"
#include "./widgets/Main_window.h"
#include "./models/card/card_types/Leader.h"
#include "./utils/Enums.h"
#include "./utils/database_helper.h"
#include "./models/Player.h"
#include "./utils/Debug.h"
#include "./fsm/fsm.h"
#include "./fsm/api/api_logic.h"
#include "./utils/Save.h"

void _setup()
{
  DatabaseHelper();
  Player *p1 = new Player("./assets/deck/deck1.txt", "Alex");
  Player *p2 = new Player("./assets/deck/deck1.txt", "Mark");


  ApiLogic(p1, p2);
  FSM fms(p1);
  Card* card = FSM::drawCardRequest();
  FSM::drawDonRequest();
  FSM::selectCardRequest(card);
  p1->print();
  FSM::endTurnRequest();
  Debug::LogDebug("********* End Turn **********");

  Card* card2 = FSM::drawCardRequest();
  std::vector<Don*> don = FSM::drawDonRequest();
  FSM::selectCardRequest(card2);
  int info = card2->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
  Debug::LogError("Card attack befor don: " + std::to_string(info));
  FSM::selectCardRequest(don[0]);
  FSM::attachDonRequest(card2, don[0]);
  info = card2->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
  Debug::LogError("Card attack after don: " + std::to_string(info));
  FSM::selectCardRequest(card2);
  FSM::selectEnemyCardRequest(card2, card);
  p1->print();
  p2->print();
  FSM::endTurnRequest(); 
  Debug::LogDebug("********* End Turn **********");
  Card* card3 = FSM::drawCardRequest();
  FSM::drawDonRequest();
  p1->print();
  p2->print();
  FSM::endTurnRequest(); 
  Debug::LogDebug("********* End Turn **********");
  Card* card4 = FSM::drawCardRequest();
  FSM::drawDonRequest();
  int att = (dynamic_cast<Character*>(card2))->getAttack();
  Debug::LogDebug("Card attack after reset: " + std::to_string(att));
  p2->print();
  ApiLogic::saveGame(p1,p2,"./assets/saves/test1");
  Player* p3 = ApiLogic::loadPlayer("./assets/saves/test1", 2);
  p3->print();
}

void _testFunctions()
{
  Debug::LogDebug("Test function");
  return;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  _setup();
  _testFunctions();
  Main_window *mw = new Main_window();
  mw->resize(1920, 1080);
  mw->show(); 

  return app.exec();
}
