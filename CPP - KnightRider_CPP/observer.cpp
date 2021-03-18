#include "observer.h"
#include <QDebug>

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::update(QString &)
{
    //qDebug() << "Aconteceu algo com o sujeito";
}

void Observer::updateProx(QString &)
{
    //qDebug() << "Desceu um nivel";

}

void Observer::updateAnt(QString &)
{
    //qDebug() << "Voltou um nivel";

}

void Observer::updateWin()
{
    //qDebug() << "O Sujeito Ganhou";

}

void Observer::updateLoose()
{
    //qDebug() << "O Sujeito Perdeu";
}

void Observer::updateNewRide(QString &pos)
{
    qDebug() << "Um novo Passeio de " << pos;
}

void Observer::updateEndRide()
{
    qDebug() << "O Sujeito testou toda a posicao";
}

void Observer::updateEnd()
{
    qDebug() << "Fim das Observações";
}
