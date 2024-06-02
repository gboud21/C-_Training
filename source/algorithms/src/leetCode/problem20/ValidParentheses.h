#ifndef VALIDPARENTHESES_H
#define VALIDPARENTHESES_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/* Scratch Pad:
Analysis: Follows normal bracket rules, must have same number of open and close
brackets AND open sequence has to be in the same order as close sequence

Output: TRUE if it is valid, false otherwise

Input: A string of characters

Constraints: String length must be even due to bracket pairing.

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

class ValidParentheses
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    ValidParentheses(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return bool - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool isValid(std::string s);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function iterates over each of the characters in the
    // string. When an open bracket is detected it adds it to the queue. When a
    // close bracket is detected it checks the top of the queue for a match. If
    // all open brackets do not have a matching closing bracket then the string
    // is invalid.
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return bool - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool bruteForce(std::string s);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function iterates over each of the linked list comparing
    // each current node and re-linking the existing nodes to build the output
    // list to reduce memory consumption
    // \param [in] s - string containing only the following character types:
    //                 "()[]{}"
    // \return bool - TRUE if it is a valid combination of brackets, FALSE
    //                otherwise
    ///////////////////////////////////////////////////////////////////////////
    // bool optimizedOne(std::string s);

    // Determines which private implementation of the ValidParentheses
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif