#pragma once

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "../../SchachLogik/SchachLogik/src/ZugProblem.h"

class ZugProblemAusgabe : public QObject
{
	Q_OBJECT
public:
	ZugProblemAusgabe(ZugProblem zugProblem);
	~ZugProblemAusgabe();

private:
	QDialog* fehlerAusgabe;

	QLabel* getFehlertext(ZugProblem zugProblem);

signals:

private slots:
	void ok();
};

