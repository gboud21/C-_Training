#ifndef SUBSTRINGWOREPEAT_H
#define SUBSTRINGWOREPEAT_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating
characters.

-0 <= s.length <= 5 * 10^4
-s consists of English letters, digits, symbols and spaces.
*/

/* Scratch Pad:
Analysis:
Output: An integer that is the length of the longest substring

Input: A string of all ascii characters that can be very long

Constraints:
-String length: Between 0 and 5*10^4, so probably want to avoid n^2 complexity

Questions:
Q:
A:
*/

#include "AlgorithmTypes.h"
#include <string>

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class SubstringWoRepeat
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    SubstringWoRepeat(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - A string of characters to find the substring in
    // \return int - the lenght of the substring, will be between 0 and 5*10^4
    ///////////////////////////////////////////////////////////////////////////
    int substringWoRepeat(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // SubstringWoRepeat algorithm. It
    // \param [in] s - A string of characters to find the substring in
    // \return int - the lenght of the substring, will be between 0 and 5*10^4
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that uses hash map and only loops over the applicable window
    // \param [in] s - A string of characters to find the substring in
    // \return int - the lenght of the substring, will be between 0 and 5*10^4
    ///////////////////////////////////////////////////////////////////////////
    int optimizedOne(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that uses the Sliding Window template and an unordered hash map
    // to improve performance
    // \param [in] s - A string of characters to find the substring in
    // \return int - the lenght of the substring, will be between 0 and 5*10^4
    ///////////////////////////////////////////////////////////////////////////
    int optimizedTwo(std::string s);

    // Determines which private implementation of the SubstringWoRepeat
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif