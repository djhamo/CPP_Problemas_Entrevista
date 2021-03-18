#include "cavalo.h"
#include "tabuleiro.h"
#include <QDebug>

Cavalo::Cavalo()
{
}

Cavalo::~Cavalo()
{
}

QStringList Cavalo::getPosPosition(QString pos) {
    QStringList saida;

    int lin = 0, col = 0;
    QString tpos;
    Tabuleiro::convertPosToNum(pos, lin, col);

    int tLin;
    int tCol;

    //soma 3 linha
    //soma 1 coluna
    tLin = lin;
    tCol = col;
    tLin += 2;
    tCol += 1;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    saida << tpos;
    //qDebug() << "Propondo posição " << tpos;

    //soma 3 linha
    //tira 1 coluna
    tLin = lin;
    tCol = col;
    tLin += 2;
    tCol -= 1;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    saida << tpos;
    //qDebug() << "Propondo posição " << tpos;

    //tira 3 linha
    //soma 1 coluna
    tLin = lin;
    tCol = col;
    tLin -= 2;
    tCol += 1;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    //tira 3 linha
    //tira 1 coluna
    tLin = lin;
    tCol = col;
    tLin -= 2;
    tCol -= 1;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    //soma 3 coluna
    //soma 1 linha
    tLin = lin;
    tCol = col;
    tLin += 1;
    tCol += 2;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    //soma 3 coluna
    //tira 1 linha
    tLin = lin;
    tCol = col;
    tLin -= 1;
    tCol += 2;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    //tira 3 coluna
    //soma 1 linha
    tLin = lin;
    tCol = col;
    tLin += 1;
    tCol -= 2;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    //tira 3 coluna
    //tira 1 linha
    tLin = lin;
    tCol = col;
    tLin -= 1;
    tCol -= 2;
    tpos = Tabuleiro::convertNumtoPos(tLin, tCol);
    //qDebug() << "Propondo posição " << tpos;
    saida << tpos;

    return saida;
}
