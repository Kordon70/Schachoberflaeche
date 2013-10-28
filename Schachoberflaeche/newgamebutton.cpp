#include "newgamebutton.h"

newGameButton::newGameButton(QObject *parent) :
    QObject(parent)
{
}

void newGameButton::openNewGameWindow() {
    playAgainstWho = new QWidget;
    playAgainstWho->setWindowTitle(QObject::tr("Neues Spiel"));

    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* playAgainstOtherPlayer = new QPushButton("Gegen anderen Spieler spielen");
    QPushButton* playAgainstComputer = new QPushButton("Gegen den Computer spielen");
    QPushButton* cancel = new QPushButton("cancel");
    layout->addWidget(playAgainstOtherPlayer);
    layout->addWidget(playAgainstComputer);
    layout->addWidget(cancel);

    playAgainstWho->setLayout(layout);
    playAgainstWho->show();
}
