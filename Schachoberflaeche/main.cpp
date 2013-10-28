#include <QPushButton>
#include "chessfield.h"
#include <QApplication>
#include <QHBoxLayout>
#include "newgamebutton.h"
//#include "../../SchachLogik/src/Logik.h"
//#include "humanplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWidget;

    chessField* chess = new chessField();
    QVBoxLayout* verticalLayout = chess->initializeChessField();


    QPushButton* button = new QPushButton;
    button->setText("Neues Spiel");
    verticalLayout->addWidget(button);


    mainWidget.setLayout(verticalLayout);

    newGameButton* ngb = new newGameButton;
    QWidget::connect(button,SIGNAL(clicked()),ngb, SLOT(openNewGameWindow()));
    mainWidget.setWindowTitle(QObject::tr("Schach"));

    mainWidget.show();
    return app.exec();
}
