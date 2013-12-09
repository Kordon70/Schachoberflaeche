#pragma once

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "OberflaecheInterface.h"

class Zug
{

private:
	Position* startPosition;
	SchachLogik* logik;
	OberflaecheInterface* oberflaeche;
	bool spielerAmZug;

public:
	void zugBeginnen();
	Zug(SchachLogik* logik);
	void beginneZug(Position* startPosition);
	void beendeZug(Position* zielPosition);
	void setzteOberflaeche(OberflaecheInterface* oberflaeche);
	~Zug(void);
};

