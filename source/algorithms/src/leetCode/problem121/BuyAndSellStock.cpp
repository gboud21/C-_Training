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
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(s);
        //     break;
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
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
int BuyAndSellStock::bruteForce(std::vector<int>& prices)
{
    // Initialize local variable
    int profit = 0;

    return profit;
}

///////////////////////////////////////////////////////////////////////////
// BuyAndSellStock::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// int BuyAndSellStock::optimizedOne(std::vector<int>& prices)
// {
//     // Initialize local variable
//     int isValid = false;

//     return isValid;
// }
} // namespace alg
