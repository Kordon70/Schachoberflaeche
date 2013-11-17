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
    vector<Field*>* schachFelder;
    QVBoxLayout* verticalLayout;
	Field* feld;

	Field* erzeugeFeld(Position* position, SchachBrettAusgabe* logikSchach);

public:
	chessField();
    QVBoxLayout* initializeChessField(SchachBrettAusgabe* logikSchach);
	void setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett);

public slots:
	void startNewGame();

signals:
};

#endif // CHESSFIELD_H
