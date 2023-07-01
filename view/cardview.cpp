#include "cardview.h"

#include <QVBoxLayout>
#include <QLabel>

CardView::CardView(const QString& imagePath, const QSize& size, QPushButton* button)
    : QPushButton(button)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(imagePath));
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(size);
    imageLabel->setScaledContents(true);

    QLabel* textLabel = new QLabel("ATTACK: 1000");
    textLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(imageLabel);
    layout->addSpacing(5);
    layout->addWidget(textLabel);
    layout->setAlignment(Qt::AlignCenter);

    this->setFixedSize(200,200);
}
