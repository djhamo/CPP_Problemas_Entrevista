#pragma once

namespace _Primitive {

    short CountBits(unsigned int x);
    short CountBitsTOP(int x);
    short CountBitsTOP2(int x);
    short CountBits(unsigned long long x);

    short Parity(unsigned long x);
    short Parity2(unsigned long x);
    short Parity3(unsigned long long x);

    long SwapBits(long x, int i, int j);

    long ReverseBits(long x);

    unsigned long ClosesIntSameBitCount(unsigned long x);

    unsigned Add(unsigned a, unsigned b);
    unsigned Multiply(unsigned x, unsigned y);
    unsigned Divide(unsigned x, unsigned y);

    double Power(double x, int y);

    long Reverse(int x);
    bool isPalindromeNumber(int x);

    int ZeroOneRandom();
    int UniformRandom(int lower_bound, int upper_bound);

    struct Rectangle {
        int x, y, width, height;
    };

    bool isIntersect(const Rectangle &R1, const Rectangle &R2);
    Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2);
}