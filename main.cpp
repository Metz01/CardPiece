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
  FSM::selectCardRequest(don[0]);
  FSM::attachDonRequest(card2, don[0]);
  FSM::selectCardRequest(card2);
  FSM::selectEnemyCardRequest(card2, card);
  p1->print();
  p2->print();
  FSM::endTurnRequest(); 
  Debug::LogDebug("********* End Turn **********");
  Card* card3 = FSM::drawCardRequest();
  FSM::drawDonRequest();
  FSM::selectCardRequest(card);
  p1->print();
  p2->print();
  Utils::CardInfo info = card->info(Enums::InfoAttribute::Name, Utils::LoadCard);
  std::string name = info.name;
  
}

void _testFunctions(int i)
{
  Debug::LogDebug("Test function");
  return;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  _setup();
  _testFunctions();
  /* Main_window *mw = new Main_window();
  mw->resize(1920, 1080);
  mw->show(); */

  return app.exec();
}