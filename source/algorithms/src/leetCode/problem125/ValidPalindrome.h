#ifndef VALIDPALINDROME_H
#define VALIDPALINDROME_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Example 2:

Example 3:

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

/* Scratch Pad:
Analysis:

Output: bool - TRUE if it is a palindrome, FALSE otherwise

Input: string of characters

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

class ValidPalindrome
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    ValidPalindrome(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return int - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool isPalindrome(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function is a brute force approach that tests every
    // combination of values.
    // \param[in] prices - array of integers representing stock prices
    // \return int - maximum difference between two stock prices where first
    // price is the "buy" price and the second price is the "sell" price
    ///////////////////////////////////////////////////////////////////////////
    bool bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function is a brute force approach that tests every
    // combination of values.
    // \param[in] prices - array of integers representing stock prices
    // \return int - maximum difference between two stock prices where first
    // price is the "buy" price and the second price is the "sell" price
    ///////////////////////////////////////////////////////////////////////////
    bool optimizedOne(std::string s);

    // Determines which private implementation of the ValidPalindrome
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif