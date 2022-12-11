#include <QWidget>
#include <QLabel>
#include "../models/Card.h"

class CardWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *artWork;
    Card card;
};