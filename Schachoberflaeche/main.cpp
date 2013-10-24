//#include "field.h"
#include "chessfield.h"
#include <QApplication>
#include <QHBoxLayout>
//#include "../../SchachLogik/src/Logik.h"
//#include "humanplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWidget;

    chessField* chess = new chessField();
    QVBoxLayout* verticalLayout = chess->initializeChessField();

    mainWidget.setLayout(verticalLayout);

    mainWidget.setWindowTitle(QObject::tr("Schach"));

    mainWidget.show();
    return app.exec();
}

QVBoxLayout initializeChessfield() {

}
