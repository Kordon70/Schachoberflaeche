#pragma once
//l�schen 2
#include <iostream>
#include <fstream>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

class Zug
{

private:
	Position* startPosition;
	SchachLogik* logik;
	bool spielerAmZug;
	ofstream myfile; //l�schen
public:
	Zug(SchachLogik* logik);
	void beginneZug(Position* startPosition);
	void beendeZug(Position* zielPosition);
	~Zug(void);
};

