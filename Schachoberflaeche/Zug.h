#pragma once
//löschen 2
#include <iostream>
#include <fstream>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

class Zug
{

private:
	Position* startPosition;
	SchachLogik* logik;
	bool spielerAmZug;
	ofstream myfile; //löschen
public:
	Zug(SchachLogik* logik);
	void beginneZug(Position* startPosition);
	void beendeZug(Position* zielPosition);
	~Zug(void);
};

