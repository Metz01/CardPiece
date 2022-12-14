// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include "./widgets/Main_window.h"
#include "./models/card_types/Leader.h"
#include "./utils/Enums.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Main_window *mw = new Main_window();
    mw->resize(1920, 1080);
    mw->show();

    return app.exec();
}