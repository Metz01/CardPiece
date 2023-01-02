// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
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
  std::cout << "Setting up..." << std::endl;
  Player *p1 = new Player("./assets/deck/deck1.txt", "Alex");
  Player *p2 = new Player("./assets/deck/deck1.txt", "Mark");
  std::cout << "print deck" << std::endl;


  ApiLogic(p1, p2);
  FSM fms(p1);
  Card* card = FSM::drawCardRequest();
  Utils::CardInfo info = card->info(Enums::InfoAttribute::Name, Utils::LoadCard);
  std::string name = info.name;
  // std::cout << "drawed card: " << name << std::endl;
  Debug::LogDebug("Card Drew");
  
  p1->printDeck();
}

void _testFunctions()
{
  //  DatabaseHelper *db = new DatabaseHelper();
  //  Card *leader = (db->selectJSonCard("OP020040"));
  //  std::cout << *(leader->info()) << std::endl;
  _setup();
  FSM::drawCardRequest();
  DatabaseHelper::testFunctions();
  return;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  _testFunctions();
  /* Main_window *mw = new Main_window();
  mw->resize(1920, 1080);
  mw->show(); */

  return app.exec();
}