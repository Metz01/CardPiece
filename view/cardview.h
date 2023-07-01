#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QPushButton>

class CardView : public QPushButton
{
    Q_OBJECT
public:
    CardView(const QString& imagePath = "", const QSize& size = QSize(200,200), QPushButton* button = new QPushButton());

signals:

};

#endif // CARDVIEW_H
