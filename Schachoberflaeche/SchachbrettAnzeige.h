#ifndef SCHACHBRETTANZEIGE_H
#define SCHACHBRETTANZEIGE_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <vector>

#include "Schachfeld.h"
#include "Zug.h"

using namespace std;

class SchachbrettAnzeige : public QObject
{
	Q_OBJECT
private:
    vector<Schachfeld*> schachFelder;
	Schachfeld* feld;
	SchachLogik* logik;
	Zug* schachZug;

	Schachfeld* erzeugeFeld(Position* position);

public:
	SchachbrettAnzeige(SchachLogik* logik, Zug* schachZug);
    QVBoxLayout* initializeChessField();
	void aktualisiereSchachfeld();

public slots:
	void startNewGame();
	void zugZurueck();

signals:
};

#endif // SCHACHBRETT_H
