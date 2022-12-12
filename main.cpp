// Includes Qt header files
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include "./widgets/Main_window.h"
#include "./models/Card.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Main_window mw(Card("Otama", "OP01-006", "+2000"));
    mw.resize(1920, 1080);
    mw.show();
    
    return app.exec();
}