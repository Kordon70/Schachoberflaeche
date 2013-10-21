#ifndef SCHACHOBERFLAECHE_H
#define SCHACHOBERFLAECHE_H

#include <QFrame>
#include <QLabel>

class Field: public QFrame
{
    Q_OBJECT
private:
    QLabel* figure;

public:

    Field(const QString color, const QPixmap* image = 0, QWidget *parent = 0);
    ~Field();
    void changePicture(QPixmap picture);


};

#endif // SCHACHOBERFLAECHE_H
