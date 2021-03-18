#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <QMap>
#include <QString>
#include <QStringList>
#include <exception>

class Tabuleiro
{
public:
    Tabuleiro(int inWidth = kDefWidth, int inHeight = kDefHeight);
    Tabuleiro(const Tabuleiro& src);
    ~Tabuleiro();
    Tabuleiro& operator=(const Tabuleiro& rhs);

    //bool& operator[](int x, int y);
    //const bool& operator[](int x, int y) const;

    int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }

    static const int kDefWidth = 8;
    static const int kDefHeight = 8;
    static const int kASCII = 97;

    QStringList getAllPosition();
    void setPassou(QString&);
    void setNaoPassou(QString&);

    void setPassou(int, int);
    void setNaoPassou(int, int);

    bool isCompleto();
    void limpaTabuleiro();
    bool jaPassei(QString&);
    bool jaPassei(int, int);

    bool isPosicaoValid(QString&);
    bool isPosicaoValid(int, int);

    static void convertPosToNum(QString&, int&, int&);
    static QString convertNumtoPos(int&, int&);

private:
    void makeCells();
    void delCells();
    void copyFrom(const Tabuleiro& src);
    bool** mCells;
    int mWidth, mHeight;
};

#endif // TABULEIRO_H
