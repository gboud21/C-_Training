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

Example 2:

Example 3:

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

/* Scratch Pad:
Analysis: Follows normal bracket rules, must have same number of open and close
brackets AND open sequence has to be in the same order as close sequence

Output: TRUE if it is valid, false otherwise

Input: A string of characters

Constraints: String length must be even due to bracket pairing.

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
    // \details This function iterates over each of the characters in the
    // string. When an open bracket is detected it adds it to the queue. When a
    // close bracket is detected it checks the top of the queue for a match. If
    // all open brackets do not have a matching closing bracket then the string
    // is invalid.
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return int - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::vector<int>& prices);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function iterates over each of the linked list comparing
    // each current node and re-linking the existing nodes to build the output
    // list to reduce memory consumption
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return int - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    // int optimizedOne(std::vector<int>& prices);

    // Determines which private implementation of the BuyAndSellStock
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif