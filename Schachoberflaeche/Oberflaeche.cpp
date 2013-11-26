#include "Oberflaeche.h"


Oberflaeche::Oberflaeche(SchachLogik* logik, Zug* schachzug)
{
	this->logik = logik;
	this->zugDurchfuehren = schachzug;
}

void Oberflaeche::oberflaecheErstellen() {
	chess = new SchachbrettAnzeige(logik, zugDurchfuehren);
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

Oberflaeche::~Oberflaeche(void)
{
}
