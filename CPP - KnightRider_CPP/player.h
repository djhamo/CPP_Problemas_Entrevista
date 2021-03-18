#ifndef PLAYER_H
#define PLAYER_H
#include "tabuleiro.h"
#include "apecaxadrez.h"
#include "subject.h"
#include <QStringList>
#include <QString>
#include <QThread>

class Player : public Subject
{

public:
    Player(Tabuleiro* iTabuleiro, APecaXadrez* iPeca, QStringList* posInicio);
    virtual ~Player() { }
    void rideTab();

private:
    void jogada(QString& pos);

    Tabuleiro* mTabuleiro;
    APecaXadrez* mPeca;
    QStringList* mposInicio;
};

#endif // PLAYER_H
