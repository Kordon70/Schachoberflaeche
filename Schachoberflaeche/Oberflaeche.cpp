#include "Oberflaeche.h"
#include <QTextCodec>

Oberflaeche::Oberflaeche(Schachlogik* logik, Zug* schachzug)
{
	this->logik = logik;
	this->schachZug = schachzug;
	this->schachZug->setzteOberflaeche(this);
}

void Oberflaeche::oberflaecheErstellen() {
	chess = new SchachbrettAnzeige(logik, schachZug);	
	QPushButton* buttonNeuePartie = new QPushButton("Neue Partie");
	QPushButton* buttonZugZurueck = new QPushButton(QString::fromStdWString(L"Zug zurück"));
	QHBoxLayout* horizonatalButtonLayout = new QHBoxLayout;
	horizonatalButtonLayout->addWidget(buttonNeuePartie);
	horizonatalButtonLayout->addWidget(buttonZugZurueck);
	amZug = new QLabel();
	horizonatalButtonLayout->addWidget(amZug);

	
	QVBoxLayout* verticalLayout = chess->initializeChessField();
	verticalLayout->addLayout(horizonatalButtonLayout);
	mainWidget.setLayout(verticalLayout);

	neuePartieFenster = new newGameButton(logik, schachZug, this);
    QWidget::connect(buttonNeuePartie,SIGNAL(clicked()),neuePartieFenster, SLOT(openNewGameWindow()));
	QWidget::connect(buttonZugZurueck,SIGNAL(clicked()),chess, SLOT(zugZurueck()));

	mainWidget.setWindowIcon(QIcon("icon\\icon.ico"));
	mainWidget.setFixedSize(640, 660);
	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();
}

void Oberflaeche::oberflaecheAktualisieren() {
	farbeAmZug();
	qApp->processEvents();
	chess->aktualisiereSchachfeld();
}

void Oberflaeche::farbeAmZug() {
	switch (logik->welcheFarbeIstDran()) {
	case SCHWARZ:
		amZug->setText("Schwarz ist am Zug.");
		break;
	case WEISS:
		amZug->setText(QString::fromStdWString(L"Weiß ist am Zug."));
		break;
	default:
		amZug->clear();
	}
	if (logik->istSpielBeendet()) {
		amZug->clear();
	}
}

Oberflaeche::~Oberflaeche() {
	delete chess;
	delete amZug;
	delete neuePartieFenster;
}
