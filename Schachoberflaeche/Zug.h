#pragma once

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "OberflaecheInterface.h"
#include "../ZugProblemAusgabe.h"

/**
	Diese Klasse registriert Bewegungen der Figuren auf dem Schachfeld und gibt sie
	wenn ein menschlicher Spieler am Zug ist, and die Logik weitre.

    @author Arne Maier
*/

class Zug {
private:
	Position* startPosition;
	Position* ungueltigePosition;
	SchachLogik* logik;
	OberflaecheInterface* oberflaeche;
	bool spielerAmZug;

public:

/**
	Lässt den Zug Bewegungen in der Logik registrieren, da jetzt ein menschlicher Spieler
	am Zug ist.
*/
	void zugBeginnen();

/**
	Erzeugt ein Zug Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
*/
	Zug(SchachLogik* logik);

/**
	Speichert sich die Position, von der eine Figur wegbewegt wurde.

	@param startPosition Position von der die Figur wegbewegt wurde.
*/
	void beginneZug(Position* startPosition);

/**
	Ruft zusammen mit der Startposition die Bewegungmethode der Logik auf.

	@param zielPosition Position auf die eine Figur bewegt wurde.
*/
	void beendeZug(Position* zielPosition);

/**
	Speichert die Oberfläche im Zug.

	@param oberflaeche Hauptfenster der Applikation.
*/
	void setzteOberflaeche(OberflaecheInterface* oberflaeche);

/**
	Aktualisiert die Oberfläche.
*/
	void aktuallisiereOberflaeche();
	~Zug();
};

