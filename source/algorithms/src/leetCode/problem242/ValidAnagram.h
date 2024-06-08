#ifndef VALIDANAGRAM_H
#define VALIDANAGRAM_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false
otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.

Example 1:
Input: ABC, BCA
Output: TRUE

Example 2:
Input: ABC, BBA
Output: TRUE

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

/* Scratch Pad:
Analysis:

Output:

Input:

Constraints:

Questions:
Q: The description says "typically exactly once", is it an anagram if the
   letters are used more than once?
A: No

Q: Can the two strings be different lengths
A: Yes
*/

#include <iostream>
#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{
class ValidAnagram
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    ValidAnagram(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool isAnagram(std::string s, std::string t);

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
    bool bruteForce(std::string s, std::string t);

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
    // bool optimizedOne(std::string s, std::string t);

    // Determines which private implementation of the ValidAnagram
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif