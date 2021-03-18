#ifndef OBSERVER_H
#define OBSERVER_H

#include "aobserver.h"

class Observer : public AObserver
{
public:
    Observer();
    ~Observer();
    void update(QString &);
    void updateProx(QString &);
    void updateAnt(QString &);
    void updateWin();
    void updateLoose();
    void updateNewRide(QString &);
    void updateEndRide();
    void updateEnd();

};

#endif // OBSERVER_H
