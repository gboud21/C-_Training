#ifndef LONGESTPALINDROMICSUBSTRING_H
#define LONGESTPALINDROMICSUBSTRING_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Longest Palindromic Substring
Given a string s, return the longest
palindromic

substring
 in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

/* Scratch Pad:
Analysis: A string is palidnromic if it is the same forward as it is backwards
Output: A string containing the longest palindrome

Input: A string between 1 and 1000 characters. It is made up of only numbers and
letters

Constraints:

Questions:
Q: If there is no palindrome (ie every character is unique) should nothing be
returned? A single character? The first single character? The last single
character?
A: Return the first single character.
*/

#include "AlgorithmTypes.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class LongestPalindromicSubstring
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    LongestPalindromicSubstring(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - The string to find a palindrome in
    // \return std::string - the longest palindrome found in the input string
    ///////////////////////////////////////////////////////////////////////////
    std::string longestPalindrome(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // LongestPalindromicSubstring algorithm.
    // \param [in] nums1 - Sorted array
    // \return std::string - the longest palindrome found in the input string
    ///////////////////////////////////////////////////////////////////////////
    std::string bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // LongestPalindromicSubstring algorithm. The original algorithm can be
    // improved in the following ways:
    // 1) Update the values used to determine the
    // \param [in] nums1 - Sorted array
    // \return std::string - the longest palindrome found in the input string
    ///////////////////////////////////////////////////////////////////////////
    std::string optimizedOne(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // LongestPalindromicSubstring algorithm. The original algorithm can be
    // improved in the following ways:
    // 1) Update the values used to determine the
    // \param [in] nums1 - Sorted array
    // \return std::string - the longest palindrome found in the input string
    ///////////////////////////////////////////////////////////////////////////
    // std::string optimizedOneRecursive(std::string& s, uint32_t position);

    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif