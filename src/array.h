#pragma once
#include <vector>

namespace _Array {

    void EvenOdd(std::vector<int> *A_ptr);

    typedef enum { RED, WHITE, BLUE } Color;
    void DutchFlagPartition(int pivot_index, std::vector<Color> *A_ptr);
    void DutchFlagPartition2(int pivot_index, std::vector<Color> *A_ptr);

    std::vector<int> PlusOne(std::vector<int> A);
    std::vector<int> Multiply(std::vector<int> num1, std::vector<int> num2);
    
    bool CanReachEnd(const std::vector<int> &max_advanced_steps);
    int DeleteDuplicates(std::vector<int> *A_ptr);
    std::vector<int> DeleteDuplicates2(std::vector<int> A);

    double BuyAndSellStockOnce(const std::vector<double> &prices);
    double BuyAndSellStockTwice(const std::vector<double> &prices);

    std::vector<int> GeneratePrimes(int n);
}