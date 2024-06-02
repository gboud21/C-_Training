#include "ValidParentheses.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ValidParentheses::ValidParentheses
///////////////////////////////////////////////////////////////////////////
ValidParentheses::ValidParentheses(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::isValid()
///////////////////////////////////////////////////////////////////////////
bool ValidParentheses::isValid(std::string s)
{
    // Initialize local variables
    bool failedStatus = false;

    // Execute the desired implementation of the ValidParentheses algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(s);
        //     break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

bool checkSquareBracket(const char left, const char right)
{
    return left == '[' && right == ']';
}

bool checkCurlyBracket(const char left, const char right)
{
    return left == '{' && right == '}';
}

bool checkParentheses(const char left, const char right)
{
    return left == '(' && right == ')';
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
bool ValidParentheses::bruteForce(std::string s)
{
    // Initialize local variable
    bool isValid = ((s.length() % 2) == 0);
    uint32_t left = 0;
    uint32_t right = s.length() - 1;

    // Need to swap to stack approach
    while (isValid && left <= right)
    {
        const char leftChar = s[left];
        const char rightChar = s[right];
        isValid = checkSquareBracket(leftChar, rightChar) ||
                  checkCurlyBracket(leftChar, rightChar) ||
                  checkParentheses(leftChar, rightChar);

        left++;
        right--;
    }

    return isValid;
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// bool ValidParentheses::optimizedOne(std::string s)
// {
//     // Initialize local variable
//     bool isValid = false;

//     return isValid;
// }
} // namespace alg
