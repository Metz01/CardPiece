#include "cardview.h"

#include <QVBoxLayout>
#include <QLabel>

CardView::CardView(Card* card, const QSize& size, QPushButton* button)
    : QPushButton(button), _card(card)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);
    std::string txtSize;

    QString text;
    switch(card->getCardType())
    {
    case 1:
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 14px;";
        break;
    case 2:
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 10px;";
        break;
    case 3:
        text = "BUFF: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        txtSize = "font-size: 10px;";
        break;
    case 4:
    case 5:
        text = "DON: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        break;
    }
    QLabel* textLabel = new QLabel(text);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(QString::fromStdString(txtSize));

    layout->addWidget(imageLabel);
    layout->addSpacing(5);
    layout->addWidget(textLabel);
    layout->setAlignment(Qt::AlignCenter);

    this->setFixedSize(80,100);
}

Card* CardView::getCard(){
    return _card;
}
