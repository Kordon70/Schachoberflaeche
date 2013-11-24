#ifndef SCHACHFELD_H
#define SCHACHFELD_H

#include "../../SchachLogik/SchachLogik/src/Farbe.h"
#include "../../SchachLogik/SchachLogik/src/Figur.h"
#include <QFrame>
#include <QLabel>

class QDragEnterEvent;
 class QDropEvent;

 class Schachfeld: public QFrame
{
    Q_OBJECT
private:
    QLabel* bild;
	Position* positionDesFeldes;
	QPixmap* figureToPicture(pair<Figuren, Farbe>* figur);

public:

	Schachfeld(Farbe backgroundColor, Position positionDesFeldes, pair<Figuren, Farbe> figur, QWidget *parent = 0);
    ~Schachfeld();
	void aendereBild(pair<Figuren, Farbe>* figur);

protected:
	void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);
};

#endif // SCHACHFELD_H
