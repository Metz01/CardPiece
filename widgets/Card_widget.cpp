#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Card_widget.h"


CardWidget::CardWidget(Card *card, QWidget* parent): QWidget(parent), _card(card){
    QHBoxLayout* layout =  new QHBoxLayout( this );
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop );
    QPixmap *image = new QPixmap( ":assets/" + QString::fromStdString((*_card).getArtPath()) + ".png" ) ;
    artWork = new QLabel();
    artWork->setPixmap(*image);
    layout->addWidget(artWork);
}

std::string CardWidget::getInfo(){
    return *(*_card).info();
}