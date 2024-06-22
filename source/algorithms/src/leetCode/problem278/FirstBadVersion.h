#ifndef FIRSTBADVERSION_H
#define FIRSTBADVERSION_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: First Bad Version
You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check. Since
each version is developed based on the previous version, all the versions after
a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first
bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is
bad. Implement a function to find the first bad version. You should minimize the
number of calls to the API.

Example 1:
Input: 10
Output: 4


Constraints:
1 <= bad <= n <= 231 - 1
*/

/* Scratch Pad:
Analysis:

Questions:
Q: Are we guaranteed to always have a bad version?
A: Yes.
*/

#include <iostream>
#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class FirstBadVersion
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    FirstBadVersion(FunctionVersion version, const int badVersion);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    int firstBadVersion(int n);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function filters the input string to remove all
    // non-alplanumeric characters and then uses the two pointer method to start
    // at each end of the string and compare the left and right pointer to each
    // other to check if the characters are equivalent (case-insensitive).
    // Pointers move towards each other if either they match or are the
    // character is not alphanumeric.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(int n);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function filters the input string to remove all
    // non-alplanumeric characters and then uses the two pointer method to start
    // at each end of the string and compare the left and right pointer to each
    // other to check if the characters are equivalent (case-insensitive).
    // Pointers move towards each other if either they match or are the
    // character is not alphanumeric.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    // int optimizedOne(int n);

    bool isBadVersion(int version);

    // Determines which private implementation of the FirstBadVersion
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;

    const int m_badVersion;
};
} // namespace alg
#endif