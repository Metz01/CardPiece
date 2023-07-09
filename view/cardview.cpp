#include "cardview.h"

CardView::CardView(Card* card, QPushButton* button)
    : QPushButton(button), _card(card) {}

CardView::~CardView()
{
    delete imageLabel;
    delete pixmap;
}

void CardView::setup(Card* card, const QSize& size, QLabel* textLabel)
{
    imageLabel = new QLabel();
    pixmap = new QPixmap(QString::fromStdString(card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath));
    Debug::LogInfo(std::string(CARDIMAGE_PATH) + card->getCardInfo(Enums::InfoAttribute::ArtPath)->value.artPath);
    imageLabel->setPixmap(*pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);

    _size = size;

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    layout->addSpacing(5);
    layout->addWidget(textLabel);
    layout->setAlignment(Qt::AlignCenter);

    this->setFixedSize(80,80);
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
