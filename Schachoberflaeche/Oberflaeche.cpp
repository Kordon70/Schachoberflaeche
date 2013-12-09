#include "Oberflaeche.h"


Oberflaeche::Oberflaeche(SchachLogik* logik, Zug* schachzug)
{
	this->logik = logik;
	this->schachZug = schachzug;
	this->schachZug->setzteOberflaeche(this);
}

void Oberflaeche::oberflaecheErstellen() {
	chess = new SchachbrettAnzeige(logik, schachZug);
	QVBoxLayout* verticalLayout = chess->initializeChessField();
	//buttons erstellen und zu layout hinzufügen
	QPushButton* button = new QPushButton;
    button->setText("Neues Spiel");
	QPushButton* buttonAnzeigen = new QPushButton;
    buttonAnzeigen->setText("Anzeigen");

	QHBoxLayout* horizonatalButtonLayout = new QHBoxLayout;
	horizonatalButtonLayout->addWidget(button);
	horizonatalButtonLayout->addWidget(buttonAnzeigen);
	
	verticalLayout->addLayout(horizonatalButtonLayout);
	mainWidget.setLayout(verticalLayout);

	//events verlinken
	newGameButton* ngb = new newGameButton;
    QWidget::connect(button,SIGNAL(clicked()),ngb, SLOT(openNewGameWindow()));
	QWidget::connect(buttonAnzeigen,SIGNAL(clicked()),chess, SLOT(startNewGame()));

	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();
}

void Oberflaeche::oberflaecheAktualisieren() {
	chess->aktualisiereSchachfeld();
}

Oberflaeche::~Oberflaeche(void)
{
}
