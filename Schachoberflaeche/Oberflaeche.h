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

class Oberflaeche : OberflaecheInterface
{
private:
    QWidget mainWidget;
	SchachLogik* logik;
	Zug* schachZug;
	SchachbrettAnzeige* chess;
	newGameButton* neuePartieFenster;
	QLabel* amZug;

	void farbeAmZug();

public:
	Oberflaeche(SchachLogik* logik, Zug* schachzug);
	void oberflaecheErstellen();
	void oberflaecheAktualisieren();
	~Oberflaeche(void);
};

