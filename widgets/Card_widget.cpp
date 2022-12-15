#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Card_widget.h"

template <typename T>
CardWidget<T>::CardWidget(T *card, QWidget* parent): QWidget(parent), _card(card){
    QHBoxLayout* layout =  new QHBoxLayout( this );
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop );
    QPixmap *image = new QPixmap( ":assets/" + QString::fromStdString((*_card).getArtPath()) + ".png" ) ;
    artWork = new QLabel();
    artWork->setPixmap(*image);
    layout->addWidget(artWork);
}

template <typename T>
std::string CardWidget<T>::getInfo(){
    return *(*_card).info();
}

template <typename T>
Card* CardWidget<T>::getCard(){
    return _card;
}