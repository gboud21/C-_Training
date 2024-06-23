#ifndef CLIMBINGSTAIRS_H
#define CLIMBINGSTAIRS_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 0:
Input: 1
Output: 1

Example 1:
Input: 2
Output: 2

Example 2:
Input: 3
Output: 3

Example 3:
Input: 4
Output: 5

Example 4:
Input: 5
Output: 8

Constraints:
1 <= n <= 45
*/

/* Scratch Pad:
Analysis:

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

class ClimbingStairs
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    ClimbingStairs(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] n - The number of stairs
    // \return int - the number of ways that the stairs can be climbed
    ///////////////////////////////////////////////////////////////////////////
    int climbingStairs(int n);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function
    // \param [in] n - The number of stairs
    // \return int - the number of ways that the stairs can be climbed
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(int n);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function
    // \param [in] n - The number of stairs
    // \return int - the number of ways that the stairs can be climbed
    ///////////////////////////////////////////////////////////////////////////
    // int optimizedOne(int n);

    // Determines which private implementation of the ClimbingStairs
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif