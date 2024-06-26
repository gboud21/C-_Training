#include "LongestPalindrome.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// LongestPalindrome::LongestPalindrome
///////////////////////////////////////////////////////////////////////////
LongestPalindrome::LongestPalindrome(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindrome::isValid()
///////////////////////////////////////////////////////////////////////////
int LongestPalindrome::longestPalindrome(std::string s)
{
    // Initialize local variables
    int status;

    // Execute the desired implementation of the LongestPalindrome algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(n);
        //     break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed std::vector
    return status;
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindrome::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int LongestPalindrome::bruteForce(std::string s)
{
    int palindromeLength = 0;

    return palindromeLength;
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindrome::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// int LongestPalindrome::optimizedOne(std::string longestpalindrome,
// std::string magazine)
// {}
} // namespace alg
