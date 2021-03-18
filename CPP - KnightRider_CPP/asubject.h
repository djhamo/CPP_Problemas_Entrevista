#ifndef ASUBJECT_H
#define ASUBJECT_H

#include <QString>

class AObserver;

class ASubject
{

public:
    ASubject() {}
    virtual void registerObserver(AObserver *observer) = 0;
    virtual void removeObserver(AObserver *observer) = 0;
    virtual void notifyObserver(QString &) = 0;
    virtual void notifyProxObserver(QString &) = 0;
    virtual void notifyAntObserver(QString &) = 0;
    virtual void notifyWinObserver() = 0;
    virtual void notifyLooseObserver() = 0;
    virtual void notifyNewRide(QString &) = 0;
    virtual void notifyEndRide() = 0;
    virtual void notifyEnd() = 0;
};

#endif // ASUBJECT_H
