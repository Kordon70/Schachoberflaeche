#pragma once

#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"
#include "zug.h"
#include "../SpielBeendet.h"
#include "../FigurenWechsel.h"

/**
	Über diese Klasse wird die Oberfläche über Änderungen in der Logik informiert.

    @author Arne Maier
*/

class SpielerMensch : public SpielerBenachrichtigung
{

private:
	Zug* schachZug;
	Farbe spielFarbe;
	Schachlogik* logik;

public:

/**
	Öffnet ein Fenster, indem ausgewählt wird, gegen welche Figur der Bauer, der das andere
	Ende des Schachfeldes erreicht hat getauscht wird.

	@param moeglicheFiguren FigurTypen gegen die der Bauer getauscht werden kann.

	@return FigurTyp gegen den der Bauer eingetauscht werden soll (DAME, LAEUFER, SPRINGER, TURM).
*/
	FigurTyp tauscheBauern(std::vector<FigurTyp> moeglicheFiguren);

/**
	Der Zug wartet aber jetzt auf Bewegungen der Figuren und führt eine Bewegung aus.
*/
	void duBistDran();

/**
	Erzeugt ein SpielerMensch Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param Farbe Farbe des Spielers, der durch das Objekt in der Logik repräsentiert wird.
*/
	SpielerMensch(Zug* schachZug, Farbe spielFarbe);

/**
	Öffnet das SpielBeendet Fenster.
*/
	void spielBeendet();

/**
	Gibt die Farbe des Spielers, der durch das Objekt in der Logik repräsentiert wird zurück.

	@return Farbe Farbe des Spielers, der durch das Objekt in der Logik repräsentiert wird.
*/
	Farbe getSpielFarbe();

/**
	Übergibt die Schachlogik an die Klasse und speichert diese.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
*/
	void setLogik(Schachlogik* logik);
	~SpielerMensch();
};

