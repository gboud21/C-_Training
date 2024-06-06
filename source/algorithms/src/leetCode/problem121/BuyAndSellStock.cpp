#include "BuyAndSellStock.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// BuyAndSellStock::BuyAndSellStock
///////////////////////////////////////////////////////////////////////////
BuyAndSellStock::BuyAndSellStock(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// BuyAndSellStock::isValid()
///////////////////////////////////////////////////////////////////////////
int BuyAndSellStock::maxProfit(std::vector<int>& prices)
{
    // Initialize local variables
    int failedStatus = false;

    // Execute the desired implementation of the BuyAndSellStock algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(prices);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(prices);
            break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed std::vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// BuyAndSellStock::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int BuyAndSellStock::bruteForce(std::vector<int>& prices)
{
    // Initialize local variable
    int profit = 0;

    for (size_t index = 0; index < prices.size() - 1; index++)
    {
        for (size_t index2 = index; index2 < prices.size(); index2++)
        {
            const int tempProfit = prices[index2] - prices[index];
            if (profit < tempProfit)
            {
                profit = tempProfit;
            }
        }
    }

    return profit;
}

///////////////////////////////////////////////////////////////////////////
// BuyAndSellStock::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int BuyAndSellStock::optimizedOne(std::vector<int>& prices)
{
    // Initialize local variable
    int profit = 0;
    size_t buyIndex = 0;

    for (size_t index = 1; index < prices.size(); index++)
    {
        const int tempProfit = prices[index] - prices[buyIndex];

        // If this is the new most profitable trade then set the profit
        if (tempProfit > profit)
        {
            profit = tempProfit;
        }
        // Otherwise if this index has a lower value than the buy index then
        // update the buy index
        else if (prices[index] < prices[buyIndex])
        {
            buyIndex = index;
        }
    }

    return profit;
}
} // namespace alg
