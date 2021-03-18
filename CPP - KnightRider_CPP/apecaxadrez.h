#ifndef APECAXADREZ_H
#define APECAXADREZ_H
#include <QStringList>
#include <QString>

class APecaXadrez
{
public:
    APecaXadrez() { }
    virtual ~APecaXadrez() {}
    virtual QStringList getPosPosition(QString) = 0;
};

#endif // APECAXADREZ_H
