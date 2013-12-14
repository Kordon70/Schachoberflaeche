#ifndef SCHACHFELD_H
#define SCHACHFELD_H


#include <fstream>	//l�schen
using namespace std; //l�schen

#include <QFrame>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/Farbe.h"
#include "../../SchachLogik/SchachLogik/src/Figur.h"
#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

#include "Zug.h"

class QDragEnterEvent;
 class QDropEvent;

 class Schachfeld: public QFrame
{
    Q_OBJECT
private:


	fstream* f; //l�schen


	SchachLogik* logik;
	Zug* schachZug;
    QLabel* bild;
	Position* positionDesFeldes;
	QPixmap* figureToPicture();

public:
	Schachfeld(SchachLogik* logik, Zug* schachZug, Position* positionDesFeldes, QWidget *parent = 0);
    ~Schachfeld();
	void output(fstream* f);
	void aendereBild();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);
};

#endif // SCHACHFELD_H
