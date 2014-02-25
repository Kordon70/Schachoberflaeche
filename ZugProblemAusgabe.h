#pragma once

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "../../SchachLogik/SchachLogik/src/ZugProblem.h"

/**
	Das Fenster, dass angezeigt wird, wenn es ein Problem beim Durchführen eines Zuges gab.

    @author Arne Maier
*/

class ZugProblemAusgabe : public QObject
{
	Q_OBJECT
public:

/**
	Erzeugt ein ZugProblemAusgabe Fenster.

	@param zugProblem ZugProblem das angibt, was beim ziehen Probleme gegeben hat.
*/
	ZugProblemAusgabe(ZugProblem zugProblem);
	~ZugProblemAusgabe();

private:
	QDialog* fehlerAusgabe;

	QLabel* getFehlertext(ZugProblem zugProblem);

private slots:
	void ok();
};

