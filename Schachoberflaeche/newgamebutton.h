#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

#include "../KuenstlicheIntelligenz.h"

#include "SpielerMensch.h"

/**
	Das Fenster, dass angezeigt wird, wenn neues Spiel gestartet werden soll und gefragt
	wird, ob 2 Spieler oder ein Spieler gegen den Computer gespielt werden soll.

    @author Arne Maier
*/

class newGameButton : public QObject
{
    Q_OBJECT
public:

/**
	Erzeugt ein newGameButton Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param schachZug Zug der die Bewegungen der Figuren auf dem Feld registriert.
	@param oberlaeche Hauptfenster der Applikation.
*/
    newGameButton(Schachlogik* logik, Zug* schachZug, OberflaecheInterface* oberlaeche);
	~newGameButton();

private:
    QWidget* neuePartie;
	Schachlogik* logik;
	Zug* schachZug;
	OberflaecheInterface* oberlaeche;

signals:

public slots:

/**
	Erzeugt das Fenster zur Auswahl des Spielmodus. Also Spieler gegen
	Spieler oder Speielr gege Computer.
*/
    void openNewGameWindow();

private slots:
	void startePartieMitZweiSpieler();
	void startePartieGegenComputer();
	void schlieseFenster();
};

#endif // NEWGAMEBUTTON_H
