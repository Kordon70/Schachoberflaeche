#ifndef CHESSFIELD_H
#define CHESSFIELD_H

#include "field.h"
#include <../../SchachLogik/SchachLogik/src/Farbe.h>
#include "../logicChessField.h"
#include <vector>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

class chessField : public QObject
{
	Q_OBJECT
private:
    vector<vector<Field*>* > chessFiedVector;
    QVBoxLayout* verticalLayout;

    vector<Field* >* initializeHorizontalRow(int row);
    vector<Field* >* emptyHorizontalRowStartsWithBlack();
    vector<Field* >* emptyHorizontalRowStartsWithWhite();
    Field* createFieldAndAddToLayout(QHBoxLayout* layout, Farbe fieldColor);
public:
    chessField();
    QVBoxLayout* initializeChessField();
	void setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett);

public slots:
	void startNewGame();

signals:
};

#endif // CHESSFIELD_H
