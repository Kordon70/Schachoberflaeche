#ifndef SCHACHBRETTANZEIGE_H
#define SCHACHBRETTANZEIGE_H

#include <vector>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Schachfeld.h"
#include "Zug.h"

using namespace std;

/**
	Erzeugt das Schachbrett mit seinen 64 Schachfeldern und aktualisiert diese.

    @author Arne Maier
*/

class SchachbrettAnzeige : public QObject
{
	Q_OBJECT
private:
    vector<Schachfeld*> schachFelder;
	Schachfeld* feld;
	SchachLogik* logik;
	Zug* schachZug;

	Schachfeld* erzeugeFeld(Position* position);

public:

/**
	Erzeugt ein SchachbrettAnzeige Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param schachZug Zug der die Bewegungen der Figuren auf dem Feld registriert.
*/
	SchachbrettAnzeige(SchachLogik* logik, Zug* schachZug);

/**
	Erzeugt ein horizontales Layout mit den 64 Schachfeldern.
*/
    QVBoxLayout* initializeChessField();

/**
	Aktualisiert die Schachfelder, sodass die aktuellen Figuren angezeigt werden.
*/
	void aktualisiereSchachfeld();

public slots:

/**
	Macht den letzten Zug rückgängig.
*/
	void zugZurueck();

signals:
};

#endif // SCHACHBRETT_H
