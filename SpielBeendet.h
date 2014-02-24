#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

class SpielBeendet : public QObject
{
	Q_OBJECT
public:
	SpielBeendet(SchachLogik* logik);
	~SpielBeendet();

private:
	QWidget* partieBeendet;
	SchachLogik* logik;

	QLabel* ausgabe();

signals:
	
public slots:
	void schlieseBeendetFenster();
};

