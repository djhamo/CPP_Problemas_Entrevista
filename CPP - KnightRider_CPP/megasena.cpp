#include "megasena.h"

MegaSena::MegaSena()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec());
}

void MegaSena::updateWin()
{
    //Verifico se já tenho 6 dezenas;
    QStringList tt = _Parcial.split(",");
    if (tt.count() > 6) {
        _Jogos << _Parcial;
        _Parcial.clear();
    }

    //Verifico se o número já não saiu nesse jogo
    QString sjogada = numUnico(tt);

    _Parcial += ",";
    _Parcial += sjogada;


}

void MegaSena::updateEnd() {

    QStringListIterator iresult(_Jogos);
    while (iresult.hasNext()) {
        std::cout << qPrintable(iresult.next()) << std::endl;
    }
}

int MegaSena::randInt(int low, int high)
{
// Random number between low and high
    int rand = (qrand() % (high - low) +1) + low;
    //std::cout << "Random 1-60: " << rand << std::endl;
    return rand;
}

QString MegaSena::numUnico(QStringList numAnt)
{
    int ijogada = randInt(1, 60);
    QString qq;
    QString sjogada = qq.setNum(ijogada);
    if (numAnt.contains(sjogada)) {
        return numUnico(numAnt);
    }
    return sjogada;
}
