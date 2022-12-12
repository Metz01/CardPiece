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

    Main_window mw(Leader("Otama", "OP01-006", "+2000", "OP01-006", Colors::red, 0, 1));
    mw.resize(1920, 1080);
    mw.show();

    return app.exec();
}