// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include "./widgets/Main_window.h"
#include "./models/card_types/Leader.h"
#include "./utils/Enums.h"
#include "utils/database_helper.h"

void _testFunctions(){
    DatabaseHelper *db = new DatabaseHelper();
    Leader *leader = dynamic_cast<Leader*> (db->selectJSonCard("OP020040"));
    std::cout << *(leader->info()) << std::endl;
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