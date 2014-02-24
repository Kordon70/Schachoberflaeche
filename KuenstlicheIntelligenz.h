#pragma once

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class KuenstlicheIntelligenz : public QObject
{
	Q_OBJECT
public:
	KuenstlicheIntelligenz();
	~KuenstlicheIntelligenz();

private:
	QDialog* kiFehler;

private slots:
	void close();
};

