#ifndef CAMINHO_H
#define CAMINHO_H
#include "observer.h"
#include <QStringList>
#include <QList>

class Caminho : public Observer
{
public:
    Caminho();
    ~Caminho() {}
    void updateProx(QString &);
    void updateAnt(QString &);
    void updateWin();
    void updateNewRide(QString &);
    void updateEndRide();
    void updateEnd();

private:
    QStringList _Caminho;
    QList<QStringList> _TotCaminho;
    int totCaminhosRide;
    QString _pCaminho;
};

#endif // CAMINHO_H
