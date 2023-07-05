#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>

class RulesWindow : public QDialog
{
    Q_OBJECT
public:
    RulesWindow(QWidget* parent = nullptr);
    void setText(const QString& text);

private:
    QLabel* imageLabel;
    QTextBrowser* textBrowser;
};

#endif // RULESWINDOW_H
