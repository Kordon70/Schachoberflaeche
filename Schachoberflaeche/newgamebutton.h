#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

class newGameButton : public QObject
{
    Q_OBJECT
public:
    explicit newGameButton(QObject *parent = 0);

private:
    QWidget* playAgainstWho;

signals:

public slots:
    void openNewGameWindow();

};

#endif // NEWGAMEBUTTON_H
