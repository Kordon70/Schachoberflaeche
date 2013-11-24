#ifndef SCHACHBRETTANZEIGE_H
#define SCHACHBRETTANZEIGE_H

#include "Schachfeld.h"
#include <../../SchachLogik/SchachLogik/src/Farbe.h>
#include <vector>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

class SchachbrettAnzeige : public QObject
{
	Q_OBJECT
private:
    vector<Schachfeld*>* schachFelder;
    QVBoxLayout* verticalLayout;
	Schachfeld* feld;

	Schachfeld* erzeugeFeld(Position* position, SchachBrettAusgabe* logikSchach);

public:
	SchachbrettAnzeige();
    QVBoxLayout* initializeChessField(SchachBrettAusgabe* logikSchach);
	void setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett);

public slots:
	void startNewGame();

signals:
};

#endif // SCHACHBRETT_H
