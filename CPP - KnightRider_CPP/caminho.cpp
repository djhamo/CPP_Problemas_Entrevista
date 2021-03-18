#include "caminho.h"
#include <QDebug>

Caminho::Caminho()
{
    totCaminhosRide = 0;
}

void Caminho::updateProx(QString &pos)
{
    _Caminho << pos;

}

void Caminho::updateAnt(QString &pos)
{
    int ind = _Caminho.indexOf(pos);
    _Caminho.removeAt(ind);
}

void Caminho::updateWin()
{
    _TotCaminho << _Caminho;
    totCaminhosRide++;
    //qDebug() << "Caminho Até Aqui " << _Caminho.join(",");
}

void Caminho::updateNewRide(QString &pos) {
    _Caminho << pos;
    _pCaminho = pos;
}

void Caminho::updateEndRide()
{
    qDebug() << "Todos os Caminhos achados " << totCaminhosRide << " de " << _pCaminho;
    totCaminhosRide = 0;
}

void Caminho::updateEnd()
{
    qDebug() << "Todos os Caminhos de " << _pCaminho;
    for (int lin = 0; lin < _TotCaminho.size(); lin++ ) {
        qDebug() << "Caminho  " << lin << " - " << _TotCaminho[lin].join(",");
    }
}
