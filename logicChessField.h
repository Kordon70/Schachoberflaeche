#pragma once

#include <vector>
#include "../../SchachLogik/SchachLogik/src/Figur.h"
#include "../../SchachLogik/SchachLogik/src/Farbe.h"

class logicChessField
{
private:
	vector<vector<pair<Figuren, Farbe>* > > figuresOnChessField;
	vector<pair<Figuren, Farbe>* > copyInnerVector(vector<pair<Farbe, pair<Figuren, Farbe>* > > figuresOfARow);

public:
	logicChessField(vector<vector<pair<Farbe, pair<Figuren, Farbe>* > > > figuresFromLogic);
	pair<Figuren, Farbe>* getFieldByPosition(unsigned row, unsigned column);
	~logicChessField(void);
};

