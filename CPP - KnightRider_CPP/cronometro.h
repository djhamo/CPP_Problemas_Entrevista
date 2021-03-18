#ifndef CRONOMETRO_H
#define CRONOMETRO_H
#include "observer.h"
#include <QTime>

class Cronometro : public Observer
{
public:
    Cronometro();
    ~Cronometro();
    void updateWin();
    //void updateLoose();
    void updateNewRide(QString &);
    void updateEndRide();
    void updateEnd();
private:
    QTime _start;
    QTime _startRide;
    QTime _victory;
    bool primeiroCaminho;
};

#endif // CRONOMETRO_H
