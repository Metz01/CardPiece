// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include "./widgets/Main_window.h"
#include "./models/card/card_types/Leader.h"
#include "./utils/Enums.h"
#include "./utils/database_helper.h"
#include "./models/Player.h"

void _setup(){
  DatabaseHelper();
  std::cout << "Setting up..." << std::endl;
  Player p = Player("./assets/deck/deck1.txt", "Alex");
  std::cout << "print deck" << std::endl;
  p.printDeck();
}

void _testFunctions(){
    //  DatabaseHelper *db = new DatabaseHelper();
    //  Card *leader = (db->selectJSonCard("OP020040"));
    //  std::cout << *(leader->info()) << std::endl;
    _setup();
    DatabaseHelper::testFunctions();
    return;
}

int main(int argc, char *argv[])
{

    _testFunctions();


    QApplication app(argc, argv);

    /* Main_window *mw = new Main_window();
    mw->resize(1920, 1080);
    mw->show(); */


    return app.exec();
}