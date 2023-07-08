#include "cardview.h"
#include "./fsm/fsm.h"
#include "./fsm/api/api_logic.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QTransform>
#include <iostream>

CardView::CardView(Card* card, const QSize& size, QPushButton* button)
    : QPushButton(button), _card(card)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    imageLabel = new QLabel();
    pixmap = new QPixmap(QString::fromStdString(card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
    Debug::LogInfo(std::string(CARDIMAGE_PATH) + card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath);
    imageLabel->setPixmap(*pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);
    std::string txtSize;

    _size = size;

    QString text;
    if(FSM::getCurrentState() == Enums::CounterPhase && ApiLogic::whoseCard(card)->hasOnHand(card)){
        switch(card->getCardType())
        {
        case 2:
            text = "COUNTER: " + QString::number(card->getCardInfo(Enums::InfoAttribute::Counter)->value.counter);
            txtSize = "font-size: 8px;";
            break;
        default:
            text = "";
            break;
        }
    } else{
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

void CardView::contextMenuEvent(QContextMenuEvent* event) {
    if (event->reason() == QContextMenuEvent::Mouse) {
        qDebug() << "Right-click detected on the button!";

        QDialog* bigCard = new QDialog();
        bigCard->setWindowTitle(_card->getCardInfo(Enums::InfoAttribute::Name)->value.name);

        QLabel* imageLabel = new QLabel();
        pixmap = new QPixmap(QString::fromStdString(_card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
        imageLabel->setPixmap(*pixmap);
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setFixedSize(358,500);
        imageLabel->setScaledContents(true);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(imageLabel);
        bigCard->setLayout(layout);

        bigCard->setFixedSize(370,510);
        QIcon* icon = new QIcon(QDir::currentPath() + QString::fromStdString("/assets/icon.png"));
        bigCard->setWindowIcon(*icon);

        bigCard->exec();
    }
    QPushButton::contextMenuEvent(event);
}
