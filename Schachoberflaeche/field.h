#ifndef SCHACHOBERFLAECHE_H
#define SCHACHOBERFLAECHE_H

#include "../../SchachLogik/SchachLogik/src/Farbe.h"
#include <QFrame>
#include <QLabel>
#include "../../SchachLogik/SchachLogik/src/Figur.h"

class QDragEnterEvent;
 class QDropEvent;

class Field: public QFrame
{
    Q_OBJECT
private:
    QLabel* figure;
	QPixmap* figureToPicture(pair<Figuren, Farbe>* figur);

public:

    Field(const Farbe backgroundColor, const QPixmap* image = 0, QWidget *parent = 0);
    ~Field();
	void changePicture(pair<Figuren, Farbe>* figur);

protected:
	void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);
};

#endif // SCHACHOBERFLAECHE_H
