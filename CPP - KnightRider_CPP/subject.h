#ifndef SUBJECT_H
#define SUBJECT_H

#include "asubject.h"
#include <QList>

class Subject : public ASubject
{
public:
    Subject();
    void registerObserver(AObserver *observer);
    void removeObserver(AObserver *observer);
    void notifyObserver(QString &);
    void notifyProxObserver(QString &);
    void notifyAntObserver(QString &);
    void notifyWinObserver();
    void notifyLooseObserver();
    void notifyNewRide(QString &);
    void notifyEndRide();
    void notifyEnd();

private:
    QList<AObserver *> _observers;
};

#endif // SUBJECT_H
