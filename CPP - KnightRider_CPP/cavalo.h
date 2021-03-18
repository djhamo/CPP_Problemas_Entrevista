#ifndef CAVALO_H
#define CAVALO_H
#include "apecaxadrez.h"

class Cavalo : public APecaXadrez
{
public:
    Cavalo();
    ~Cavalo();
    QStringList getPosPosition(QString);
};

#endif // CAVALO_H
