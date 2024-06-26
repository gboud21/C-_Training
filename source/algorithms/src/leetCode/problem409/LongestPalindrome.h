#ifndef LONGESTPALINDROME_H
#define LONGESTPALINDROME_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the
length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input:  aAbbccddddd
Output: 5 "ddddd"

Example 2:
Input:  abcde
Output: 0 ""

Example 3:
Input:  baAAac
Output: 4 "aAAa"

Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
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

class LongestPalindrome
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    LongestPalindrome(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] longestPalindrome - The characters from the ransom note
    // \param [in] magazine - The characters that can be used from the magzine
    // \return int - TRUE if ransomeNote is a subset of the characters in
    // magazine, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    int longestPalindrome(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function will iterate through both the ransome note and the
    // magazine trying to determine if the number of each character within
    // the longestPalindrome can be found within the magazine
    // \param [in] longestPalindrome - The characters from the ransom note
    // \param [in] magazine - The characters that can be used from the magzine
    // \return int - TRUE if ransomeNote is a subset of the characters in
    // magazine, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function
    // \param [in] n - The number of stairs
    // \return int - the number of ways that the stairs can be climbed
    ///////////////////////////////////////////////////////////////////////////
    // int optimizedOne(std::string s);

    // Determines which private implementation of the LongestPalindrome
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif