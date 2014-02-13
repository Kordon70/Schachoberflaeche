#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

#include "../../SchachLogik/SchachLogik/src/Figuren.h"

class FigurenWechsel : public QObject {
	Q_OBJECT
private:
	QWidget* bauernTausch;
public:
	FigurenWechsel(Figuren& figur);
	~FigurenWechsel();
signals:
public slots:
	void setDame(Figuren& figur);
};

