#pragma once

#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

class FigurenWechsel : public QObject
{

private:
	QWidget* bauernTausch;
public:
	FigurenWechsel(void);
	~FigurenWechsel(void);
};

