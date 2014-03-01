#pragma once

#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"
#include "zug.h"
#include "../SpielBeendet.h"
#include "../FigurenWechsel.h"

/**
	�ber diese Klasse wird die Oberfl�che �ber �nderungen in der Logik informiert.

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
	�ffnet ein Fenster, indem ausgew�hlt wird, gegen welche Figur der Bauer, der das andere
	Ende des Schachfeldes erreicht hat getauscht wird.

	@param moeglicheFiguren FigurTypen gegen die der Bauer getauscht werden kann.

	@return FigurTyp gegen den der Bauer eingetauscht werden soll (DAME, LAEUFER, SPRINGER, TURM).
*/
	FigurTyp tauscheBauern(std::vector<FigurTyp> moeglicheFiguren);

/**
	Der Zug wartet aber jetzt auf Bewegungen der Figuren und f�hrt eine Bewegung aus.
*/
	void duBistDran();

/**
	Erzeugt ein SpielerMensch Objekt.

	@param logik Schachlogik die f�r den Spielablauf verantwortlich ist.
	@param Farbe Farbe des Spielers, der durch das Objekt in der Logik repr�sentiert wird.
*/
	SpielerMensch(Zug* schachZug, Farbe spielFarbe);

/**
	�ffnet das SpielBeendet Fenster.
*/
	void spielBeendet();

/**
	Gibt die Farbe des Spielers, der durch das Objekt in der Logik repr�sentiert wird zur�ck.

	@return Farbe Farbe des Spielers, der durch das Objekt in der Logik repr�sentiert wird.
*/
	Farbe getSpielFarbe();

/**
	�bergibt die Schachlogik an die Klasse und speichert diese.

	@param logik Schachlogik die f�r den Spielablauf verantwortlich ist.
*/
	void setLogik(Schachlogik* logik);
	~SpielerMensch();
};

