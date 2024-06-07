#ifndef VALIDPALINDROME_H
#define VALIDPALINDROME_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
input: AbcddcbA
output: TRUE

Example 2:
input: Abcddcba
output: TRUE

Example 3:
input: A11A
output: TRUE

Example 4:
input: aba
output: TRUE

Example 5:
input: abcb
output: FALSe

Example 6:
input: a b c c b a
output: TRUE

Example 6:
input: abc.ba
output: FALSe

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

/* Scratch Pad:
Analysis:
-Need to ignore all Alphanumeric characters [A-z,0-9].
-Need to ignore case

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
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool isPalindrome(std::string s);

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
    bool bruteForce(std::string s);

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
    bool optimizedOne(std::string s);

    // Determines which private implementation of the ValidPalindrome
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif