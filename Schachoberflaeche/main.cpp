
#include <QApplication>
#include "../../SchachLogik/SchachLogik/src/SchachlogikImpl.h"
#include "Zug.h"
#include "Oberflaeche.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	Schachlogik* logik = new SchachlogikImpl();
	Zug* zugDurchfruehren = new Zug(logik);
	Oberflaeche* gui = new Oberflaeche(logik, zugDurchfruehren);
	gui->oberflaecheErstellen();

    return app.exec();
}