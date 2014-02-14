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
	explicit FigurenWechsel(Figuren& figur);
	~FigurenWechsel();
private:
	//QWidget* bauernTausch;
	Figuren& wechselFigur;
	QDialog* bauernTausch;
signals:

public slots:
	void setBauer();
	void setTurm();
	void setLauefer();
	void setSpringer();
	void setDame();
};

