#ifndef ROMANTOINT_H
#define ROMANTOINT_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

/* Scratch Pad:
Analysis:
Output: An integer representation of a roman numeral between 1 and 3999

Input: Single string of characters representing a number in roman numerals.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

Questions:
Q:
A:
*/

#include <iostream>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class RomanToInt
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    RomanToInt(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - String containing a number represented in Roman Numerals.
    // \return int - the integer represented by the input string
    ///////////////////////////////////////////////////////////////////////////
    int romanToInt(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // RomanToInt algorithm that executes the problem using a switch statement.
    // \param [in] s - String containing a number represented in Roman Numerals.
    // \return int - the integer represented by the input string
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that uses an unordered_map to reduce code complexity.
    // Realistically, this approach will run slightly slower and use more memory
    // than the brute force approach; however, the benifit is that the function
    // requires less lines of code and therefore is easier to maintain than the
    // brute force approach
    // \param [in] s - String containing a number represented in Roman Numerals.
    // \return int - the integer represented by the input string
    ///////////////////////////////////////////////////////////////////////////
    int optimizedOne(std::string s);

    // Determines which private implementation of the RomanToInt
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif