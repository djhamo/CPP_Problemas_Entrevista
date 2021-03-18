#include <gmock/gmock.h>
#include "../src/array.h"

using namespace _Array;
using namespace testing;

TEST(ArrayEvenOdd, Test1) {
    std::vector<int> tt = { 4, 643, 25, 149, 526, 45, 22 ,46};
    EvenOdd(&tt);

    ASSERT_EQ(tt[0], 4);
    ASSERT_EQ(tt[1], 46);
    ASSERT_EQ(tt[2], 22);
    ASSERT_EQ(tt[3], 526);
    ASSERT_EQ(tt[4], 45);
    ASSERT_EQ(tt[5], 149);
    ASSERT_EQ(tt[6], 25);
    ASSERT_EQ(tt[7], 643);
}

TEST(ArrayDutchFlagPartition, Test1) {
    std::vector<Color> tt = { BLUE, WHITE, BLUE, RED, RED, WHITE, BLUE};
    DutchFlagPartition(3, &tt);

    ASSERT_EQ(tt[0], RED);
    ASSERT_EQ(tt[1], RED);
    ASSERT_EQ(tt[2], BLUE);
    ASSERT_EQ(tt[3], WHITE);
    ASSERT_EQ(tt[4], BLUE);
    ASSERT_EQ(tt[5], BLUE);
    ASSERT_EQ(tt[6], WHITE);
}

TEST(ArrayDutchFlagPartition, Test2) {
    std::vector<Color> tt = { BLUE, WHITE, BLUE, RED, RED, WHITE, BLUE};
    DutchFlagPartition2(3, &tt);

    ASSERT_EQ(tt[0], RED);
    ASSERT_EQ(tt[1], RED);
    ASSERT_EQ(tt[2], BLUE);
    ASSERT_EQ(tt[3], WHITE);
    ASSERT_EQ(tt[4], WHITE);
    ASSERT_EQ(tt[5], BLUE);
    ASSERT_EQ(tt[6], BLUE);
}

TEST(ArrayPlusOne, Test129) {
    std::vector<int> tt = { 1, 2, 9};
    std::vector<int> result = PlusOne(tt);

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 0);
}

TEST(ArrayPlusOne, Test99) {
    std::vector<int> tt = { 9, 9};
    std::vector<int> result = PlusOne(tt);

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}

TEST(ArrayMultiply, Test123_987) {
    std::vector<int> t1 = { 1, 2, 3};
    std::vector<int> t2 = { 9, 8, 7};
    std::vector<int> result = Multiply(t1, t2);

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 2);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 4);
    ASSERT_EQ(result[4], 0);
    ASSERT_EQ(result[5], 1);
}

TEST(ArrayCanReachEnd, TestFalse) {
    std::vector<int> tt = { 3, 2, 0, 0, 2, 0, 1};
    bool result = CanReachEnd(tt);

    ASSERT_EQ(result, false);
    
}

TEST(ArrayCanReachEnd, TestTrue) {
    std::vector<int> tt = { 3, 2, 0, 1, 2, 5, 3};
    bool result = CanReachEnd(tt);

    ASSERT_EQ(result, true);
    
}

TEST(ArrayDeleteDuplicates, Test1) {
    std::vector<int> tt = { 2, 3, 5 , 5, 7, 11, 11, 11, 13};
    int result = DeleteDuplicates(&tt);

    ASSERT_EQ(result, 6);

}

TEST(ArrayBuyAndSellStockOnce, Test1) {
    std::vector<double> tt = { 310, 315, 275 , 295, 260, 270, 290, 230, 255, 250};
    int result = BuyAndSellStockOnce(tt);

    ASSERT_EQ(result, 30);

}

TEST(GeneratePrimes, Test10) {
    std::vector<int> result = GeneratePrimes(10);

    ASSERT_EQ(result[0], 2);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 5);
    ASSERT_EQ(result[3], 7);

}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}