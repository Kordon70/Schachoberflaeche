#pragma once

#include <QApplication>
#include <QPushButton>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "OberflaecheInterface.h"
#include "Zug.h"
#include "SchachbrettAnzeige.h"
#include "newgamebutton.h"

class Oberflaeche : OberflaecheInterface
{
private:
    QWidget mainWidget;
	SchachLogik* logik;
	Zug* schachZug;
	SchachbrettAnzeige* chess;

public:
	Oberflaeche(SchachLogik* logik, Zug* schachzug);
	void oberflaecheErstellen();
	void oberflaecheAktualisieren();
	~Oberflaeche(void);
};

