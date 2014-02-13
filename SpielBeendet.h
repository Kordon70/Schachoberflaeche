#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>

class SpielBeendet : public QObject
{
private:
	QWidget* partieBeendet;

public:
	SpielBeendet(void);
	~SpielBeendet(void);
public slots:
	void schlieseFenster();
};

