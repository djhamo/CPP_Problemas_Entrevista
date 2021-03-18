#include <gmock/gmock.h>
#include "../src/primitive.h"
#include <limits>
#include <math.h>

using namespace _Primitive;
using namespace testing;

TEST(Primitive_Count_Bits, TestUnsignedInt1) {
    unsigned int t = 1;
    short result = CountBits(t);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Count_Bits, TestUnsignedInt3) {
    unsigned int t = 3;
    short result = CountBits(t);
    ASSERT_EQ(result, 2);
}

TEST(Primitive_Count_Bits, TestUnsignedInt13) {
    unsigned int t = 13;
    short result = CountBits(t);
    ASSERT_EQ(result, 3);
}

TEST(Primitive_Count_Bits, TestUnsignedIntMax32bits) {
    short result = CountBits(std::numeric_limits<unsigned int>::max());
    ASSERT_EQ(result, 32);
}

TEST(Primitive_Count_Bits, TestUnsignedLongLongMax64bits) {
    short result = CountBits(std::numeric_limits<unsigned long long>::max());
    ASSERT_EQ(result, 64);
}

TEST(Primitive_Count_Bits, TestInt1) {
    int t = 1;
    short result = CountBitsTOP(t);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Count_Bits, TestInt3) {
    int t = 3;
    short result = CountBitsTOP(t);
    ASSERT_EQ(result, 2);
}

TEST(Primitive_Count_Bits, TestInt13) {
    int t = 13;
    short result = CountBitsTOP(t);
    ASSERT_EQ(result, 3);
}

TEST(Primitive_Count_Bits, TestIntMax32bits) {
    short result = CountBitsTOP(std::numeric_limits<int>::max());
    ASSERT_EQ(result, 31);
}

TEST(Primitive_Count_Bits, Test2Int1) {
    int t = 1;
    short result = CountBitsTOP2(t);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Count_Bits, Test2Int3) {
    int t = 3;
    short result = CountBitsTOP2(t);
    ASSERT_EQ(result, 2);
}

TEST(Primitive_Count_Bits, Test2Int13) {
    int t = 13;
    short result = CountBitsTOP2(t);
    ASSERT_EQ(result, 3);
}

TEST(Primitive_Count_Bits, Test2IntMax32bits) {
    short result = CountBitsTOP2(std::numeric_limits<int>::max());
    ASSERT_EQ(result, 31);
}

TEST(Primitive_Parity, TestOddULong1) {
    short result = Parity(11);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Parity, TestOddULong0) {
    short result = Parity(136);
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, TestOddULongMax) {
    short result = Parity(std::numeric_limits<unsigned long>::max());
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test2OddULong1) {
    short result = Parity2(11);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Parity, Test2OddULong0) {
    short result = Parity2(136);
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test2OddULongMax) {
    short result = Parity2(std::numeric_limits<unsigned long>::max());
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test3OddULong1) {
    short result = Parity3(11);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_Parity, Test3OddULong0) {
    short result = Parity3(136);
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test3ULongMax) {
    short result = Parity3(std::numeric_limits<unsigned long>::max());
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test3OddULong23797) {
    short result = Parity3(23797);
    ASSERT_EQ(result, 0);
}

TEST(Primitive_Parity, Test3OddULong23796) {
    short result = Parity3(23796);
    ASSERT_EQ(result, 1);
}

TEST(Primitive_SwapBits, Test6_1) {
    long result = SwapBits(32,5,1);
    ASSERT_EQ(result, 2);
}

TEST(Primitive_ReverseBits, Test_0b1110000000000001) {
    long result = ReverseBits(57345);
    ASSERT_EQ(result, -2147024896);
}

TEST(Primitive_ReverseBits, Test_0b010) {
    long result = ReverseBits(2);
    ASSERT_EQ(result, 1073741824);
}

TEST(Primitive_ClosesIntSameBitCount, Test_6_5) {
    long result = ClosesIntSameBitCount(6);
    ASSERT_EQ(result, 5);
}

TEST(Primitive_Add, Test_6_5) {
    unsigned result = Add(6, 5);
    ASSERT_EQ(result, 11);
}

TEST(Primitive_Multiply, Test_6_5) {
    unsigned result = Multiply(6, 5);
    ASSERT_EQ(result, 30);
}

TEST(Primitive_Divide, Test_30_5) {
    unsigned result = Divide(30, 5);
    ASSERT_EQ(result, 6);
}

TEST(Primitive_Power, Test_3_5) {
    unsigned result = Power(3, 5);
    ASSERT_EQ(result, 243);
}

TEST(Primitive_Reverse, Test_Minus123) {
    unsigned result = Reverse(-123);
    ASSERT_EQ(result, -321);
}

TEST(Primitive_isPalindromeNumber, Test_157751) {
    bool result = isPalindromeNumber(157751);
    ASSERT_EQ(result, true);
}

TEST(Primitive_isPalindromeNumber, Test_15751) {
    bool result = isPalindromeNumber(15751);
    ASSERT_EQ(result, true);
}

TEST(Primitive_isPalindromeNumber, Test_minus15) {
    bool result = isPalindromeNumber(-15);
    ASSERT_EQ(result, false);
}

TEST(Primitive_isPalindromeNumber, Test_minus1) {
    bool result = isPalindromeNumber(-1);
    ASSERT_EQ(result, false);
}

TEST(Primitive_isPalindromeNumber, Test_1) {
    bool result = isPalindromeNumber(1);
    ASSERT_EQ(result, true);
}

TEST(Primitive_IntersectRectangle, Test_1) {
    Rectangle R1 = {1,1,5,6};
    Rectangle R2 = {3,1,2,2};

    Rectangle result = IntersectRectangle(R1, R2);
    ASSERT_EQ(result.x, R2.x);
    ASSERT_EQ(result.y, R2.y);
    ASSERT_EQ(result.width, R2.width);
    ASSERT_EQ(result.height, R2.height);
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}