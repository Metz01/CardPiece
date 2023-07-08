#include "cardview.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QTransform>
#include <iostream>

CardView::CardView(Card* card, const QSize& size, QPushButton* button)
    : QPushButton(button), _card(card)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    imageLabel = new QLabel();
    pixmap = new QPixmap(QString::fromStdString(std::string(CARDIMAGE_PATH) + card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
    imageLabel->setPixmap(*pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);
    std::string txtSize;

    _size = size;

    QString text;
    switch(card->getCardType())
    {
    case 1:
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 10px;";
        break;
    case 2:
        text = "ATTACK: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Attack)->value.attack);
        txtSize = "font-size: 8px;";
        break;
    case 3:
        text = "BUFF: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        txtSize = "font-size: 8px;";
        break;
    case 4:
        text = "BUFF: +" + QString::number(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff);
        txtSize = "font-size: 8px;";
        break;
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

    this->setFixedSize(80,80);
}

CardView::~CardView()
{
    delete imageLabel;
    delete pixmap;
}


Card* CardView::getCard(){
    return _card;
}

void CardView::rotateCard()
{
    QTransform transform;
    transform.rotate(90);
    imageLabel->setPixmap((*pixmap).transformed(transform));
    _size.transpose();
    imageLabel->setFixedSize(_size);
    std::cout << "ROTATING"<< std::endl;
}
