#pragma once

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

/**
	Das Fenster, dass angezeigt wird, wenn ein Spiel gegen den Computer gestartet werden soll,
	das bedauert, das dies nicht möglich ist.

    @author Arne Maier
*/

class KuenstlicheIntelligenz : public QObject
{
	Q_OBJECT
public:

/**
	Erzeugt das Fenster mit dem Ok Knopf zum schließen und dem Text.
*/
	KuenstlicheIntelligenz();
	~KuenstlicheIntelligenz();

private:
	QDialog* kiFehler;

private slots:
	void close();
};

