#include "ValidPalindrome.h"

#include <cctype>

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

bool isAlphaNumericSpace(char c) { return (isalnum(c) != 0); }

///////////////////////////////////////////////////////////////////////////
// ValidPalindrome::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool ValidPalindrome::bruteForce(std::string s)
{
    // Initialize local variable
    bool isValid = true;
    std::string filteredString = "";

    for (size_t index = 0; index < s.length(); index++)
    {
        if (isalnum(s[index]) != 0)
        {
            filteredString += s[index];
        }
    }

    int left = 0;
    int right = filteredString.length() - 1;

    while (isValid && left < right)
    {
        isValid =
            tolower(filteredString[left]) == tolower(filteredString[right]);
        left++;
        right--;
    }

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
    bool isValid = true;
    int left = 0;
    int right = s.length() - 1;

    while (isValid && left < right)
    {
        while (left < right && isalnum(s[left]) == 0)
        {
            left++;
        }

        while (left < right && isalnum(s[right]) == 0)
        {
            right--;
        }

        isValid = tolower(s[left]) == tolower(s[right]);
        left++;
        right--;
    }

    return isValid;
}
} // namespace alg
