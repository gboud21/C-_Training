#ifndef LEET_OBJ_ALL_CAPS_H
#define LEET_OBJ_ALL_CAPS_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: LEET_TITLE
LEET_DESCRIPTION

Example 1:
Input: 10
Output: 4


Constraints:
LEET_CONSTRAINTS
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

class LEET_OBJ
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    LEET_OBJ(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    LEET_RETURN LEET_FUNC(LEET_PARAMS);

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
    LEET_RETURN bruteForce(LEET_PARAMS);

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
    // LEET_RETURN optimizedOne(LEET_PARAMS);

    bool isBadVersion(int version);

    // Determines which private implementation of the LEET_OBJ
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif