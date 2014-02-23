#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QDialog>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/FigurTyp.h"

class FigurenWechsel : public QObject
{
	Q_OBJECT
public:
	FigurenWechsel(FigurTyp& figur);
	~FigurenWechsel();
private:
	FigurTyp& wechselFigur;
	QDialog* bauernTausch;
signals:

private slots:
	void setBauer();
	void setTurm();
	void setLauefer();
	void setSpringer();
	void setDame();
};

