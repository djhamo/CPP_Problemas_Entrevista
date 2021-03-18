#include "player.h"
#include <QDebug>

Player::Player(Tabuleiro* iTabuleiro, APecaXadrez* iPeca, QStringList* posInicio) :
    mTabuleiro(iTabuleiro), mPeca(iPeca), mposInicio(posInicio)
{

}

void Player::rideTab()
{
    QStringList todasPos = (* mposInicio);

    qDebug() << "Todas as pos " << todasPos.join(",");

    //Informo Posição a Posição pro Player
    QStringListIterator itodasPos(todasPos);
    while (itodasPos.hasNext()) {
        QString tpos = itodasPos.next();
        notifyNewRide(tpos);
        jogada(tpos);
        notifyEndRide();
        mTabuleiro->limpaTabuleiro();
    }
    notifyEnd();
}

void Player::jogada(QString& pos)
{
    //qDebug() << "Jogada " << pos;

    notifyObserver(pos);
    mTabuleiro->setPassou(pos);
    if (mTabuleiro->isCompleto()) {
        notifyWinObserver();
        notifyAntObserver(pos);
        mTabuleiro->setNaoPassou(pos);
        //return true;
        return;
    }

    //Obtenho a lista de caminhos Possíveis
    QStringList possivelPos = mPeca->getPosPosition(pos);

    for (int cont = 0; cont < possivelPos.size(); cont++) {
        //qDebug() << possivelPos[cont];
        if (!mTabuleiro->isPosicaoValid(possivelPos[cont])) {
            //qDebug() << "Tirando " << possivelPos[cont] ;
            possivelPos.removeAt(cont);
            cont--;
        } else {
            if (mTabuleiro->jaPassei(possivelPos[cont])) {
                //qDebug() << "Tirando " << possivelPos[cont] ;
                possivelPos.removeAt(cont);
                cont--;
            }
        }
    }
    //qDebug() << "Jogadas Possiveis " << possivelPos.join(",");

    //Se a lista vier vazia return false
    if (possivelPos.isEmpty()) {
        mTabuleiro->setNaoPassou(pos);
        notifyAntObserver(pos);
        notifyLooseObserver();
        //return false;
        return;
    }

    for (int cont = 0; cont < possivelPos.size(); cont++) {
        notifyProxObserver(possivelPos[cont]);
        /*
        if (jogada(possivelPos[cont])) {
            return true;
        }
        */
        jogada(possivelPos[cont]);
    }

    notifyAntObserver(pos);
    mTabuleiro->setNaoPassou(pos);
    return;

}

