#include <QPushButton>
#include "chessfield.h"
#include <QApplication>
#include <QHBoxLayout>
#include "newgamebutton.h"
#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "../logicChessField.h"
#include "humanplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWidget;


	//Schachlogik erstellen und Figuren anzeigen
	SchachLogik* logik = new SchachLogik();
	
	SchachBrettAusgabe* schachBrettLogik = logik->getSpielfeld();


    chessField* chess = new chessField;
	QVBoxLayout* verticalLayout = chess->initializeChessField(schachBrettLogik);
	
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
    return app.exec();
}
