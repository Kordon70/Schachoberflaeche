#pragma once

#include <QApplication>
#include <QPushButton>
#include <qapplication.h>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "OberflaecheInterface.h"
#include "Zug.h"
#include "SchachbrettAnzeige.h"
#include "newgamebutton.h"
#include "SpielerMensch.h"
#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"

/**
	Erzeugt das Hauptfenster mit dem Schachfeld, den Knöpfen Spiel starten und Zug zurück.

    @author Arne Maier
*/

class Oberflaeche : OberflaecheInterface
{
public:

/**
	Erzeugt ein Oberflaechen Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param schachZug Zug der die Bewegungen der Figuren auf dem Feld registriert.
*/
	Oberflaeche(SchachLogik* logik, Zug* schachzug);

/**
	Erzeugt das Fenster mit dem Schachfeld, den Knöpfen Spiel starten und Zug
	zurück, sowie dem Label des Spielers der an der Reihen ist.
*/
	void oberflaecheErstellen();

/**
	Aktualisiert das Schachfeld, sowie die Anzeige des Spielers der an der Reihe ist.
*/
	void oberflaecheAktualisieren();
	~Oberflaeche();

private:
    QWidget mainWidget;
	SchachLogik* logik;
	Zug* schachZug;
	SchachbrettAnzeige* chess;
	newGameButton* neuePartieFenster;
	QLabel* amZug;

	void farbeAmZug();
};

