#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QDialog>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/FigurTyp.h"

/**
	Das Fenster, dass angezeigt wird, wenn ein Bauer am gegen�berliegenden Rand ankommt mit Kn�pfen f�r alle
	Figuren gegen die man den Bauer tauschen kann.

    @author Arne Maier
*/

class FigurenWechsel : public QObject
{
	Q_OBJECT
public:

/**
	Erzeugt das Fenster mit den Kn�pfen zur Auswahl der Figur die gegen den Bauer
	getauscht werden soll.

	@param figur in dieser Figur steht nachdem ein Knopf gedr�ckt wurde der Typ der Figur.
*/
	FigurenWechsel(FigurTyp& figur);
	~FigurenWechsel();
private:
	FigurTyp& wechselFigur;
	QDialog* bauernTausch;

private slots:
	void setTurm();
	void setLauefer();
	void setSpringer();
	void setDame();
};

