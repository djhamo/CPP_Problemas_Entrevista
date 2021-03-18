#ifndef AOBSERVER_H
#define AOBSERVER_H
#include <QString>

class AObserver
{

public:
    AObserver() {}
    virtual ~AObserver() {}
    virtual void update(QString &) = 0;
    virtual void updateProx(QString &) = 0;
    virtual void updateAnt(QString &) = 0;
    virtual void updateWin() = 0;
    virtual void updateLoose() = 0;
    virtual void updateNewRide(QString &) = 0;
    virtual void updateEndRide() = 0;
    virtual void updateEnd() = 0;


};

#endif // AOBSERVER_H
