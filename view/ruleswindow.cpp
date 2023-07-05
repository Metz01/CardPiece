#include "ruleswindow.h"

RulesWindow::RulesWindow(QWidget* parent)
    : QDialog(parent)
{
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);

    textBrowser = new QTextBrowser(this);
    textBrowser->setOpenLinks(false);
    textBrowser->setOpenExternalLinks(false);
    textBrowser->setStyleSheet("QTextBrowser { background-color: transparent; }");
    textBrowser->setFrameStyle(QFrame::NoFrame);
    textBrowser->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    layout->addWidget(textBrowser);

    setLayout(layout);
}

void RulesWindow::setText(const QString &text)
{
    QString htmlText = text;
    textBrowser->setHtml(htmlText);
}
