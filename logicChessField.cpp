#include "logicChessField.h"


logicChessField::logicChessField(vector<vector<pair<Farbe, pair<Figuren, Farbe>* > > > figuresFromLogic)
{
	figuresOnChessField = vector<vector<pair<Figuren, Farbe>* > >();
	for (unsigned i = 0; i < figuresFromLogic.size(); i++) {
		figuresOnChessField.push_back(copyInnerVector(figuresFromLogic[i]));
	}
}

vector<pair<Figuren, Farbe>* > logicChessField::copyInnerVector(vector<pair<Farbe, pair<Figuren, Farbe>* > > figuresOfARow) {
	vector<pair<Figuren, Farbe>* >  row = vector<pair<Figuren, Farbe>* > ();
	for (unsigned i = 0; i < figuresOfARow.size(); i++) {
		row.push_back(figuresOfARow[i].second);
	}
	return row;
}

pair<Figuren,Farbe>* logicChessField::getFieldByPosition(unsigned row, unsigned column) {
	return figuresOnChessField[row][column];
}


logicChessField::~logicChessField(void)
{
}
