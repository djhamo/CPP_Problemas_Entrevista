#ifndef MEGASENA_H
#define MEGASENA_H
#include "observer.h"
#include <QStringList>
#include <QList>
#include <iostream>
#include <qglobal.h>
#include <QTime>

class MegaSena : public Observer
{
public:
    MegaSena();
    ~MegaSena() {}
    void updateWin();
    void updateEnd();

private:
    int randInt(int low, int high);
    QString numUnico(QStringList numAnt);
    QString _Parcial;
    QStringList _Jogos;

};

#endif // MEGASENA_H
