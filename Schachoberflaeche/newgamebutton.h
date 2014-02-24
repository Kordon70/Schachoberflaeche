#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

#include "../KuenstlicheIntelligenz.h"

#include "SpielerMensch.h"

class newGameButton : public QObject
{
    Q_OBJECT
public:
    newGameButton(SchachLogik* logik, Zug* schachZug, OberflaecheInterface* oberlaeche, QObject *parent = 0);

private:
    QWidget* neuePartie;
	SchachLogik* logik;
	Zug* schachZug;
	OberflaecheInterface* oberlaeche;

signals:

public slots:
    void openNewGameWindow();
	void startePartieMitZweiSpieler();
	void startePartieGegenComputer();
	void schlieseFenster();
};

#endif // NEWGAMEBUTTON_H
