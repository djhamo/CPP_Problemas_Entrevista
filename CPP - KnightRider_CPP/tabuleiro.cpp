#include "tabuleiro.h"
#include <QDebug>
#include <QObject>

//const int Tabuleiro::kDefWidth;
//const int Tabuleiro::kDefHeight;
//const int Tabuleiro::kASCII;



Tabuleiro::Tabuleiro(int inWidth, int inHeight) :
    mWidth(inWidth), mHeight(inHeight)
{
    makeCells();
}

Tabuleiro::Tabuleiro(const Tabuleiro& src)
{
    copyFrom(src);
}

Tabuleiro::~Tabuleiro()
{
    delCells();
}

Tabuleiro& Tabuleiro::operator=(const Tabuleiro& rhs)
{
    if (this == &rhs) {
        return (* this);
    }

    delCells();

    copyFrom(rhs);

    return (*this);
}
/*
bool& Tabuleiro::operator[](int x, int y) {
    if (!isPosicaoValid(x,y)) {
        throw out_of_range("");
    }
    return (mCells[x][y]);
}

const bool& Tabuleiro::operator[](int x, int y) const {
    if (!isPosicaoValid(x,y)) {
        throw out_of_range("");
    }
    return (mCells[x][y]);
}
*/

void Tabuleiro::makeCells()
{
    mCells = new bool* [mWidth];
    for (int lin = 0; lin < mWidth; lin++) {
        mCells[lin] = new bool [mHeight];
        for (int col = 0; col < mHeight; col++) {
            mCells[lin][col] = false;
        }
    }

}

void Tabuleiro::delCells()
{
    for (int lin = 0; lin < mWidth; lin++) {
        delete[] mCells[lin];
    }
    delete[] mCells;

}


void Tabuleiro::copyFrom(const Tabuleiro& src)
{
    mWidth = src.mWidth;
    mHeight = src.mHeight;

    makeCells();
    for (int lin = 0; lin < mWidth; lin++) {
        for (int col = 0; col < mHeight; col++) {
            mCells[lin][col] = src.mCells[lin][col];
        }
    }
}


QStringList Tabuleiro::getAllPosition()
{
    QStringList mPositions;
    for (int lin = 0; lin < mWidth; lin++) {
        for (int col = 0; col < mHeight; col++) {
            mPositions << convertNumtoPos(lin, col);
        }
    }

    return mPositions;
}


void Tabuleiro::setPassou(int x, int y)
{
    mCells[x][y] = true;
}

void Tabuleiro::setNaoPassou(int x, int y)
{
    mCells[x][y] = false;
}


void Tabuleiro::setPassou(QString& posicao)
{
    int x, y;
    convertPosToNum(posicao, x, y);
    setPassou(x, y);

}

void Tabuleiro::setNaoPassou(QString &posicao)
{
    int x, y;
    convertPosToNum(posicao, x, y);
    setNaoPassou(x, y);
}


bool Tabuleiro::isCompleto()
{
    for (int lin = 0; lin < mWidth; lin++) {
        for (int col = 0; col < mHeight; col++) {
            if (mCells[lin][col] == false) {
                return false;
            }
        }
    }
    return true;
}

void Tabuleiro::limpaTabuleiro() {
    for (int lin = 0; lin < mWidth; lin++) {
        for (int col = 0; col < mHeight; col++) {
            mCells[lin][col] = false;
        }
    }
}


bool Tabuleiro::isPosicaoValid(int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if ( x >= mWidth || y >= mHeight) {
        return false;
    }
    return true;
}

bool Tabuleiro::isPosicaoValid(QString& pos)
{
    int x, y;
    convertPosToNum(pos, x, y);
    return isPosicaoValid(x, y);
}

bool Tabuleiro::jaPassei(int x, int y) {
    return mCells[x][y];
}

bool Tabuleiro::jaPassei(QString& pos)
{
    int x, y;
    convertPosToNum(pos, x, y);
    return jaPassei(x, y);
}

QString Tabuleiro::convertNumtoPos(int& lin, int& col)
{
    QString saida;


    int tcol = col + kASCII;
    //qDebug() << "tLin " << tlin;

    QChar tCharlin(tcol);
    //tCharlin.fromAscii(tlin);
    //qDebug() << "QChar " << tCharlin;
    saida = tCharlin;

    QString tt;
    tt.setNum(lin + 1);
    saida += tt;

    //qDebug() << "Saida " << saida;

    return saida;

}


void Tabuleiro::convertPosToNum(QString& pos, int& num1, int& num2)
{

    QChar ch = pos.at(0).toAscii();
    int chValue =  ch.toAscii();
    //QChar ch = pos.at(0).toLatin1();
    //int chValue =  ch.toLatin1();
    //qDebug() << "Ascci bruto " << chValue;

    num2 = chValue - kASCII;
    //no máximo soltar um alerta ,aqui está fazendo duas funções dentro de uma
    /*
    if (num2 < 0) {
        num2 = 0;
    }
    */
    num1 = pos.at(1).digitValue() - 1;

    //qDebug() << "int1 " << num1 << "int2 " << num2;
}
