#pragma once

//#include "../../SchachLogik/SchachLogik/src/Position.h"
//#include "../../SchachLogik/SchachLogik/src/Figur.h"
#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

class Zug
{

private:
	Position* startPosition;
	SchachLogik* logik;
public:
	Zug(SchachLogik* logik);
	void beginneZug(Position* startPosition);
	void beendeZug(Position* zielPosition);
	~Zug(void);
};

