#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QDialog>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/Figuren.h"

class FigurenWechsel : public QObject
{
	Q_OBJECT
public:
	FigurenWechsel(Figuren& figur);
	~FigurenWechsel();
private:
	Figuren& wechselFigur;
	QDialog* bauernTausch;
signals:

private slots:
	void setBauer();
	void setTurm();
	void setLauefer();
	void setSpringer();
	void setDame();
};

