#include "subject.h"
#include <QListIterator>
#include "aobserver.h"

Subject::Subject()
{
}

void Subject::registerObserver(AObserver *observer)
{
    _observers.append(observer);
}

void Subject::removeObserver(AObserver *observer)
{
    int pos = _observers.indexOf(observer);
    _observers.removeAt(pos);
}

void Subject::notifyObserver(QString &pos)
{
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->update(pos);
    }
}

void Subject::notifyProxObserver(QString &pos)
{
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateProx(pos);
    }
}

void Subject::notifyAntObserver(QString &pos)
{
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateAnt(pos);
    }
}

void Subject::notifyWinObserver()
{
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateWin();
    }
}

void Subject::notifyLooseObserver()
{
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateLoose();
    }
}

void Subject::notifyEndRide() {
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateEndRide();
    }
}

void Subject::notifyEnd() {
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateEnd();
    }
}

void Subject::notifyNewRide(QString &pos) {
    QListIterator<AObserver *> i(_observers);
    while (i.hasNext()) {
        AObserver *observer = i.next();
        observer->updateNewRide(pos);
    }
}
