#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QList>
#include <QStringList>
#include <QTextCodec>


#include "tabuleiro.h"
#include "cavalo.h"
#include "player.h"
#include "observer.h"
#include "caminho.h"
#include "cronometro.h"
#include "megasena.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTextCodec::setCodecForTr (QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings (QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale (QTextCodec::codecForName("ISO 8859-1"));

    //Vou começar parando no primeiro resultado Válido
    //Mas quero armazenar todos os caminhos possíveis
    //Precisarei de uma estrutura global que armazene todos os resultados
    //E paro de procurar quando testar todas as posições


    //Monto uma Lista com todas as posições do Tabuleiro
    Tabuleiro *tTab = new Tabuleiro(5,5);
    Cavalo *tCav = new Cavalo();
    Observer *tObs = new Observer();
    Caminho *tCam = new Caminho();
    Cronometro *tCron = new Cronometro();
    MegaSena *tSena = new MegaSena();
    //QStringList tposIni = tTab->getAllPosition();
    QStringList tposIni;

    tposIni << "d4";
    //tposIni << "d1";
    //tposIni << "b5";
    //tposIni << "a1";

    Player *tPlay = new Player(tTab, tCav, &tposIni);
    tPlay->registerObserver(tObs);
    tPlay->registerObserver(tCam);
    tPlay->registerObserver(tCron);
    tPlay->registerObserver(tSena);
    tPlay->rideTab();

    delete tTab;
    delete tCav;
    delete tObs;
    delete tCam;
    delete tCron;
    delete tPlay;
    delete tSena;

    std::cout << "Acabou" << std::endl;
    /*
    for (int lin = 0; lin < 6; lin++) {
        for (int col = 0; col < 6; col++) {
            std::cout << qPrintable(Tabuleiro::convertNumtoPos(lin,col)) << ",";
        }
        std::cout << std::endl;
    }
    */
    //Exibo os Caminhos OK
    /*
    QStringListIterator iresult(result);
    while (iresult.hasNext()) {
        std::cout << qPrintable(iresult.next()) << std::endl;
    }
    */
    //return a.exec();
    return 0;
}



