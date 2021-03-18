#include "src/primitive.h"
#include "src/array.h"
#include <iostream>

using namespace _Primitive;
using namespace _Array;

int main(int argc, char** argv) {
    std::cout << CountBits((unsigned int) 1) << std::endl;
    std::cout << CountBits(std::numeric_limits<unsigned long long>::max()) << std::endl;
    std::cout << CountBits(std::numeric_limits<unsigned int>::max()) << std::endl;
    std::cout << CountBitsTOP(std::numeric_limits<int>::max()) << std::endl;
    std::cout << CountBitsTOP2(std::numeric_limits<int>::max()) << std::endl;
    
    std::cout << Parity(std::numeric_limits<unsigned long>::max()) << std::endl;
    std::cout << Parity2(std::numeric_limits<unsigned long>::max()) << std::endl;
    std::cout << Parity3(std::numeric_limits<unsigned long long>::max()) << std::endl;
    std::cout << Parity3(23797) << std::endl;
    std::cout << Parity3(23796) << std::endl;

    std::cout << SwapBits(32,5,1) << std::endl;

    std::cout << ReverseBits(57345) << std::endl;
    std::cout << ReverseBits(2) << std::endl;

    std::cout << ClosesIntSameBitCount(6) << std::endl;

    std::cout << isPalindromeNumber(-1) << std::endl;
    std::cout << isPalindromeNumber(-15) << std::endl;
    std::cout << isPalindromeNumber(1231) << std::endl;

    int test = 0;
    double result[6];
    unsigned int tot_test = 100000;
    for (int i = 0; i < 6; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < tot_test; i++) {
        test = UniformRandom(1, 6);
        result[(test -1)]++;
    }
    for (int i = 0; i < 6; i++) {
        result[i] /= tot_test;
        std::cout << (i + 1) << " = " << result[i]  << std::endl;
    }

    std::vector<int> tt = { 4, 643, 25, 149, 526, 45, 22 ,46};
    EvenOdd(&tt);
    for (auto const& i: tt) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<Color> tt2 = { BLUE, WHITE, BLUE, RED, RED, WHITE, BLUE};
    DutchFlagPartition(3, &tt2);
    for (auto const& i: tt2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> tt3 = { 21, 77, 324, 2, 3, 5 , 5, 7, 11, 11, 11, 13};
    
    std::vector<int> result2 = DeleteDuplicates2(tt3);
    for (auto const& i: result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}