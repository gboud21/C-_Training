#include "ValidPalindrome.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ValidPalindrome::ValidPalindrome
///////////////////////////////////////////////////////////////////////////
ValidPalindrome::ValidPalindrome(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// ValidPalindrome::isValid()
///////////////////////////////////////////////////////////////////////////
bool ValidPalindrome::isPalindrome(std::string s)
{
    // Initialize local variables
    bool status = false;

    // Execute the desired implementation of the ValidPalindrome algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(s);
            break;
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
// ValidPalindrome::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool ValidPalindrome::bruteForce(std::string s)
{
    // Initialize local variable
    bool isValid = false;

    return isValid;
}

///////////////////////////////////////////////////////////////////////////
// ValidPalindrome::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool ValidPalindrome::optimizedOne(std::string s)
{
    // Initialize local variable
    bool isValid = false;

    return isValid;
}
} // namespace alg
