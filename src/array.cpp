#include "array.h"
#include <algorithm>
#include <deque>

namespace _Array {

    void EvenOdd(std::vector<int> *A_ptr) {
        std::vector<int> &A = *A_ptr;
        int next_even = 0, next_odd = A.size() -1;
        while (next_even < next_odd) {
            if (A[next_even] % 2 == 0) {
                ++next_even;
            } else {
                std::swap(A[next_even], A[next_odd--]);
            }
        }
    }

    void DutchFlagPartition(int pivot_index, std::vector<Color> *A_ptr) {
        std::vector<Color> &A = *A_ptr;
        Color pivot = A[pivot_index];

        //Menor q o pivot
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) { 
                if (A[j] < pivot) {
                    std::swap(A[i], A[j]);
                    break;
                }
            }
        }
        
        for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
            for (int j = i - 1; j >= 0 && A[j] >= pivot; --j) {
                if(A[j] > pivot) {
                    std::swap(A[i], A[j]);
                    break;
                }
            }
        }
        
    }

    //1loop
    void DutchFlagPartition2(int pivot_index, std::vector<Color> *A_ptr) {
        std::vector<Color> &A = *A_ptr;
        Color pivot = A[pivot_index];
        
        int smaller = 0, equal = 0, larger = A.size();
        while(equal < larger) {
            if (A[equal] < pivot) {
                std::swap(A[smaller++], A[equal++]);
            } else if (A[equal] == pivot) {
                ++equal;
            } else {
                std::swap(A[equal], A[--larger]);
            }
        }
    }  

    std::vector<int> PlusOne(std::vector<int> A) {
        ++A.back();
        for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
            A[i] = 0, ++A[i - 1];                
        }
        if (A[0] == 10) {
            A[0] = 0;
            A.insert(A.begin(), 1);
        }
        return A;
    }  

    std::vector<int> Multiply(std::vector<int> num1, std::vector<int> num2) {
        const int sign = num1.front() < 0 ^ num2.front() < 0 ? -1 : 1;
        num1.front() = abs(num1.front());
        num2.front() = abs(num2.front());

        std::vector<int> result(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                result[i + j + 1] += num1[i] * num2[j];
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }

        result = {
            std::find_if_not(std::begin(result), 
                std::end(result), 
                [](int a){ return a == 0; }), 
                std::end(result)};
 
        if (result.empty()) {
            return {0};
        }
        result.front() *= sign;
        return result;       
    }

    bool CanReachEnd(const std::vector<int> &max_advanced_steps) {
        int furthest_reach_so_far = 0, last_index = max_advanced_steps.size() - 1;
        for (int i = 0;
            i <= furthest_reach_so_far && furthest_reach_so_far < last_index;
            ++i) 
        {
            furthest_reach_so_far = std::max(furthest_reach_so_far, max_advanced_steps[i] + i);        
        }
        return furthest_reach_so_far >= last_index;
    }

    int DeleteDuplicates(std::vector<int> *A_ptr) {
        std::vector<int> &A = *A_ptr;
        if (A.empty()) {
            return 0;
        }

        int write_index = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[write_index - 1] != A[i]) {
                A[write_index++] = A[i];
            }
        }
        return write_index;
        
    }

    std::vector<int> DeleteDuplicates2(std::vector<int> A) {
        if (A.empty()) {
            return A;
        }
        if(!std::is_sorted(A.begin(), A.end())) {
            std::sort(A.begin(), A.end());
        }

        int write_index = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[write_index - 1] != A[i]) {
                A[write_index++] = A[i];                
            }
        }

        auto first = A.begin();
        auto last = A.begin() + write_index;
 
        std::vector<int> result(first, last);
        return result;
    }

    double BuyAndSellStockOnce(const std::vector<double> &prices) {
        double min_price_so_far = std::numeric_limits<double>::max(), max_profit = 0;
        for (const double &price: prices) {
            double max_profit_sell_today = price - min_price_so_far;
            max_profit = std::max(max_profit, max_profit_sell_today);
            min_price_so_far = std::min(min_price_so_far, price);
        }
        return max_profit;
    }

    double BuyAndSellStockTwice(const std::vector<double> &prices) {
        double max_total_profit = 0;
        std::vector<double> first_buy_sell_profits(prices.size(), 0);
        double min_price_so_far = std::numeric_limits<double>::max();

        for (int i = 0; i < prices.size(); ++i) {
            min_price_so_far = std::min(min_price_so_far, prices[i]);
            max_total_profit = std::max(max_total_profit, prices[i] - min_price_so_far);
            first_buy_sell_profits[i] = max_total_profit;
        }

        double max_price_so_far = std::numeric_limits<double>::min();
        for (int i = prices.size() - 1; i > 0; --i) {
            max_price_so_far = std::max(max_price_so_far, prices[i]);
            max_total_profit = std::max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i -1]);
        }
        return max_total_profit;       
    }

    std::vector<int> GeneratePrimes(int n) {
        std::vector<int> primes;

        std::deque<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 0; p < n; ++p) {
            if (is_prime[p]) {
                primes.emplace_back(p);
                for (int j = p; j <= n; j += p) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }

}