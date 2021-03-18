#include "cronometro.h"
#include <QDebug>

Cronometro::Cronometro()
{
    primeiroCaminho = true;
    _start.start();
    _startRide.start();
    _victory.start();


}

Cronometro::~Cronometro()
{
}

void Cronometro::updateWin()
{
    QTime time, tt;
    time = tt.addMSecs(_victory.elapsed());
    qDebug() << "Achou a Vitória em " << time.toString("HH:mm:ss.zzz");
    _victory.restart();
}

void Cronometro::updateNewRide(QString &)
{
    if (primeiroCaminho) {
        primeiroCaminho = false;
        _start.restart();
    }
    _startRide.restart();
    _victory.restart();
}

void Cronometro::updateEndRide()
{
    QTime time, tt;
    time = tt.addMSecs(_startRide.elapsed());
    qDebug() << "Rodou todo o Caminho em " << time.toString("HH:mm:ss.zzz");

}

void Cronometro::updateEnd()
{
    QTime time, tt;
    time = tt.addMSecs(_start.elapsed());
    qDebug() << "Rodou o Programa em " << time.toString("HH:mm:ss.zzz");
}
