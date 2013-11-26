#pragma once

#include <QApplication>
#include <QPushButton>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "Zug.h"
#include "SchachbrettAnzeige.h"
#include "newgamebutton.h"

class Oberflaeche
{
private:
    QWidget mainWidget;
	SchachLogik* logik;
	Zug* zugDurchfuehren;
	SchachbrettAnzeige* chess;

public:
	Oberflaeche(SchachLogik* logik, Zug* schachzug);
	void oberflaecheErstellen();
	~Oberflaeche(void);
};

