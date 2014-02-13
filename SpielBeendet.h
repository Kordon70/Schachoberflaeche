#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>

class SpielBeendet : public QObject
{
	Q_OBJECT
public:
	explicit SpielBeendet();
	~SpielBeendet();

private:
	QWidget* partieBeendet;

signals:
	
public slots:
	void schlieseBeendetFenster();
};

