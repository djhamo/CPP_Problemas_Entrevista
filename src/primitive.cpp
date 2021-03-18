#include <stdexcept> 
#include <random>
#include "primitive.h"

namespace _Primitive {

    short CountBits(unsigned int x) {
        short num_bits = 0;
        while(x) {
            num_bits += x & 1;
            x >>= 1;
        }
        return num_bits;
    }

    short CountBits(unsigned long long x) {
        short num_bits = 0;
        while(x) {
            x &= (x - 1);
            num_bits++;
        
            //num_bits += x & 1;
            //x >>= 1;
        }
        return num_bits;
    }

    short CountBitsTOP(int x) {
        int result = 0;

        // B[0] = 0x55555555 = 01010101 01010101 01010101 01010101
        // B[1] = 0x33333333 = 00110011 00110011 00110011 00110011
        // B[2] = 0x0F0F0F0F = 00001111 00001111 00001111 00001111
        // B[3] = 0x00FF00FF = 00000000 11111111 00000000 11111111
        // B[4] = 0x0000FFFF = 00000000 00000000 11111111 11111111
        
        
        static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};
            
        result = (x & B[0]) + ( (x >> 1) & B[0] );
        result = (result & B[1]) + ( ( result >> 2 ) & B[1] );
        result = (result + ( result >> 4 )) & B[2] ;
        result = (result + ( result >> 8 )) & B[3] ;
        result = (result + ( result >> 16 )) & B[4] ;
    
        return (short)result;
    }

    short CountBitsTOP2(int x) {
        int result = 0;
        x = x - ((x >> 1) & 0x55555555);                    
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);     
        result = ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
       
        return (short)result;
    }

    short Parity(unsigned long x) {
        short result = 0;
        while (x) {
            result ^= 1;
            x &= (x - 1);
        }
        return result;
    }

    short Parity2(unsigned long x) {
        short result = 0;
        // macros to generate the lookup table (at compile-time)
        static const bool ParityTable256[256] = 
        {
        #   define P2(n) n, n^1, n^1, n
        #   define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
        #   define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
            P6(0), P6(1), P6(1), P6(0)
        };
        
        x ^= x >> 16;
        x ^= x >> 8;
        result = ParityTable256[x & 0xff];

        return result;    
    }

    short Parity3(unsigned long long x) {
        // 64 bits
        x ^= x >> 32;
        x ^= x >> 16;
        x ^= x >> 8;
        x ^= x >> 4;
        x ^= x >> 2;
        x ^= x >> 1;
        return x & 0x1;
    }

    long SwapBits(long x, int i, int j) {
        if (((x >> i) & 1) != ((x >> j) & 1)) {
            unsigned long bitmask = (1L << i) | (1L << j);
            x ^= bitmask;
        }
        return x;
    }

    long ReverseBits(long x) {
        static const unsigned char precomputed_reverse[] = 
        {
        #   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
        #   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
        #   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
            R6(0), R6(2), R6(1), R6(3)
        };

        long result = 0;
        const int kBitMask = 0xff;

        result = precomputed_reverse[x & kBitMask] << 24 |
            precomputed_reverse[(x >> 8) & kBitMask] << 16 |
            precomputed_reverse[(x >> 16) & kBitMask] << 8 |
            precomputed_reverse[(x >> 24) & kBitMask];

        return result;
    }

    //Return a number witch is not equal to x but has the same weight x and the difference is small as possible
    //if x = 6 return 5
    unsigned long ClosesIntSameBitCount(unsigned long x) {
        const int kNumUnsignBits = 64;
        for (int i = 0; i < kNumUnsignBits - 1; ++i) {
            if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
                x ^= (1UL << i) | (1UL << (i + 1));
                return x;
            }

        }
        throw std::invalid_argument("Todos os bits são 0 ou 1");
    }

    unsigned Add(unsigned a, unsigned b) {
        unsigned sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
        while (temp_a || temp_b) {
            unsigned ak = a & k, bk = b & k;
            unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
            sum |= (ak ^bk ^ carryin);
            carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
        }
        return sum | carryin;
    }

    unsigned Multiply(unsigned x, unsigned y) {
        unsigned sum = 0;
        while (x) {
            if (x & 1) {
                sum = Add(sum, y);
            }
            x >>= 1, y <<= 1;
        }
        return sum;
    }

    unsigned Divide(unsigned x, unsigned y) {
        unsigned result = 0;
        int power = 32;
        unsigned long long y_power = static_cast<unsigned long long>(y) << power;
        while ( x >= y) {
            while (y_power > x) {
                y_power >>= 1;
                --power;
            }

            result += 1U << power;
            x -= y_power;
        }
        return result;
    }

    double Power(double x, int y) {
        double result = 1.0;
        long long power = y;
        if (y < 0) {
            power = -power, x = 1.0/x;            
        }
        while (power) {
            if (power & 1) {
                result *= x;
            }
            x *= x, power >>=1;
        }
        return result;
    }

    long Reverse(int x) {
        long result = 0, x_remaining = abs(x);
        while (x_remaining) {
            result = result * 10 + x_remaining % 10;
            x_remaining /= 10;
        }
        return x < 0 ? -result : result;
    }

    //5775
    bool isPalindromeNumber(int x) {
        if (x < 0) {
            return false;
        }

        const int num_digits = static_cast<int>(floor(log10(x))) + 1;
        //if ((num_digits / 2) != 0)
        //    return false;

        int msd_mask = static_cast<int>(pow(10, num_digits - 1));
        for (int i = 0; i < (num_digits / 2); ++i) {
            if (x / msd_mask != x % 10) {
                return false;
            }
            x %= msd_mask;
            x /= 10;
            msd_mask /= 100;
        }
        return true;
    }

    using std::default_random_engine;
    using std::random_device;
    using std::uniform_int_distribution;
    
    int ZeroOneRandom() {
        default_random_engine gen((random_device())());
        uniform_int_distribution<int> dis(0, 1);
        return dis(gen);
    }

    int UniformRandom(int lower_bound, int upper_bound) {
        int number_of_outcomes = upper_bound - lower_bound + 1, result;
        do {
            result = 0;
            for (int i = 0; (1 << i) < number_of_outcomes; i++){ 
                result = (result << 1) | ZeroOneRandom();
            }
        } while (result >= number_of_outcomes);
        return result + lower_bound;
    }

    bool isIntersect(const Rectangle &R1, const Rectangle &R2) {
        return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
            R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
    }   

    Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2) {
        if (!isIntersect(R1, R2)) {
            return {0, 0, -1, -1};
        }

        return {std::max(R1.x, R2.x), 
            std::max(R1.y, R2.y),
            std::min(R1.x + R1.width, R2.x + R2.width) - std::max(R1.x, R2.x),
            std::min(R1.y + R1.height, R2.y + R2.height) - std::max(R1.y, R2.y)};
    }

}
