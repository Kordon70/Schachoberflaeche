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
	Schachlogik* logik;
	Zug* schachZug;

	Schachfeld* erzeugeFeld(Position* position);

public:

/**
	Erzeugt ein SchachbrettAnzeige Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param schachZug Zug der die Bewegungen der Figuren auf dem Feld registriert.
*/
	SchachbrettAnzeige(Schachlogik* logik, Zug* schachZug);

/**
	Erzeugt ein horizontales Layout mit den 64 Schachfeldern.
*/
    QVBoxLayout* initializeChessField();

/**
	Aktualisiert die Schachfelder, sodass die aktuellen Figuren angezeigt werden.
*/
	void aktualisiereSchachfeld();
	~SchachbrettAnzeige();

public slots:

/**
	Macht den letzten Zug rückgängig.
*/
	void zugZurueck();

signals:
};

#endif // SCHACHBRETT_H
