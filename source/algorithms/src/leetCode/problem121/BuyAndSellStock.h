#ifndef BUYANDSELLSTOCK_H
#define BUYANDSELLSTOCK_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on
the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

Example 1:
0 1 2 3 4 5
return 5

Example 2:
10 5 20 3 12
return 15

Example 3:
 10 9 8 7 6 5
 return 0

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

/* Scratch Pad:
Analysis: Should be able to just iterate through and keep track of the min and
max index for the greatest difference

Output: integer --> the maximum difference, 0 if all values decrease or are the
same

Input: Array of integers

Constraints:

Questions:
Q:
A:
*/

#include <iostream>
#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class BuyAndSellStock
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    BuyAndSellStock(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return int - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    int maxProfit(std::vector<int>& prices);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function is a brute force approach that tests every
    // combination of values.
    // \param[in] prices - array of integers representing stock prices
    // \return int - maximum difference between two stock prices where first
    // price is the "buy" price and the second price is the "sell" price
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::vector<int>& prices);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function is a brute force approach that tests every
    // combination of values.
    // \param[in] prices - array of integers representing stock prices
    // \return int - maximum difference between two stock prices where first
    // price is the "buy" price and the second price is the "sell" price
    ///////////////////////////////////////////////////////////////////////////
    int optimizedOne(std::vector<int>& prices);

    // Determines which private implementation of the BuyAndSellStock
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif