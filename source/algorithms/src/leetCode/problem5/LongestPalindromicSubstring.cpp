#include "LongestPalindromicSubstring.h"

#include <stdint.h>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// LongestPalindromicSubstring::LongestPalindromicSubstring
///////////////////////////////////////////////////////////////////////////
LongestPalindromicSubstring::LongestPalindromicSubstring(
    FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindromicSubstring::longestPalindrome()
///////////////////////////////////////////////////////////////////////////
std::string LongestPalindromicSubstring::longestPalindrome(std::string s)
{
    // Initialize local variables
    std::string failedStatus = "";

    // Execute the desired implementation of the LongestPalindromicSubstring
    // algorithm
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
        //     return optimizedTwo(nums1, nums2);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindromicSubstring::bruteForce(): PASSED
// Time Complexity: O(N^2)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
std::string LongestPalindromicSubstring::bruteForce(std::string s)
{
    // Initialize local variable
    std::string palindrome = s.substr(0, 1);

    // Simplest approach is to brute force loop over the string for every
    // possible combination of characters to find the longest substring

    // a b b a c
    // Start at left a, second pointer at right c
    // try to compare, failurem shift right pointer to the left and restart
    // left = a, right = a
    // pass, increment offset and do comparision again, repeat until either a
    // mismatch or left + offset < right - offset

    // Loop over all characters
    for (uint32_t left = 0; left < s.length(); left++)
    {
        // Starting at the right, see if every possible combination is a
        // palindrome
        for (uint32_t right = s.length() - 1; right > left; right--)
        {
            uint32_t offset = 0;
            uint32_t leftPos = left;
            uint32_t rightPos = right;
            bool palindromeFound = true;

            // While there are still characters to check and all characters have
            // matched
            while (leftPos <= rightPos && palindromeFound)
            {
                // If the left character does not match the right character then
                // this is not a valid palindrome, trigger the loop to exit
                if (s[leftPos] != s[rightPos])
                {
                    palindromeFound = false;
                }
                // Otherwise this still may be a palindrome. Update the
                // variables to check the next pair of characters
                else
                {
                    offset++;
                    leftPos = left + offset;
                    rightPos = right - offset;
                }
            }

            // If a palindrome was found then and it is longer than the longest
            // palindrome discovered so far then update the palindrome string
            if (palindromeFound && right - left + 1 > palindrome.length())
            {
                palindrome = s.substr(left, (right - left + 1));
            }
        }
    }

    return palindrome;
}

///////////////////////////////////////////////////////////////////////////
// LongestPalindromicSubstring::optimizedOne():
// Time Complexity: O(log(M+N))
// Space Complexity:
///////////////////////////////////////////////////////////////////////////
std::string LongestPalindromicSubstring::optimizedOne(std::string s)
{
    // Initialize local variable
    std::string palindrome = "";

    // Loop over each position expanding out from the center trying to build a
    // palindrome
    for (int32_t index = 0; index < s.length(); index++)
    {
        // Two scenarios:
        // 1) the palindrome has an odd number of characters
        //      In the odd number case we just need to expand out comparing
        // b a b a d
        // 2) the palindrome has an even number of characters
        //      In the even number case we need to check if either the left or
        //      right character is the same as the starting character
    }

    return palindrome;
}

} // namespace alg
