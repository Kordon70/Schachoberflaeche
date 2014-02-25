#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

/**
	Das Fenster, dass angezeigt wird, wenn das Spiel beendet ist. Es zeigt den Gewinner an.

    @author Arne Maier
*/

class SpielBeendet : public QObject
{
	Q_OBJECT
public:

/**
	Erzeugt ein Fenster das den Gewinner angibt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
*/
	SpielBeendet(SchachLogik* logik);
	~SpielBeendet();

private:
	QWidget* partieBeendet;
	SchachLogik* logik;

	QLabel* ausgabe();

public slots:

/**
	Schließt das SpielBeendet Fenster.
*/
	void schlieseBeendetFenster();
};

