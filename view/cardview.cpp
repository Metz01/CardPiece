#include "cardview.h"

#include <QVBoxLayout>
#include <QLabel>

CardView::CardView(Card* card, const QSize& size, QPushButton* button)
    : QPushButton(button)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);

    QString text;
    switch(card->getCardType())
    {
    case 1:
    case 2:
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        break;
    case 3:
        text = "BUFF: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        break;
    case 4:
    case 5:
        text = "DON: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        break;
    }
    QLabel* textLabel = new QLabel(text);
    textLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(imageLabel);
    layout->addSpacing(5);
    layout->addWidget(textLabel);
    layout->setAlignment(Qt::AlignCenter);

    this->setFixedSize(200,200);
}
