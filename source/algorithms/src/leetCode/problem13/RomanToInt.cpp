#include "RomanToInt.h"

#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// RomanToInt::RomanToInt
///////////////////////////////////////////////////////////////////////////
RomanToInt::RomanToInt(FunctionVersion version) : m_functionVersion(version) {}

///////////////////////////////////////////////////////////////////////////
// RomanToInt::romanToInt()
///////////////////////////////////////////////////////////////////////////
int RomanToInt::romanToInt(std::string s)
{
    // Initialize local variables
    int failedStatus = -1;

    // Execute the desired implementation of the RomanToInt algorithm
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

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// RomanToInt::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
int RomanToInt::bruteForce(std::string s)
{
    // Initialize local variable
    int value = 0;

    // Loop over each of the characters
    for (size_t index = 0; index < s.length(); index++)
    {
        // Switch statement where a value is added depending on what the next
        // character is with all logic explicitly defined (ie if current
        // position is 'I' then subtract 1 if the next character is 'V',
        // otherwise add 1)
        switch (s[index])
        {
            case 'I':
                if ((index + 1 < s.length()) &&
                    ((s[index + 1] == 'V') || (s[index + 1] == 'X')))
                {
                    value -= 1;
                }
                else
                {
                    value += 1;
                }
                break;
            case 'V':
                value += 5;
                break;
            case 'X':
                if ((index + 1 < s.length()) &&
                    ((s[index + 1] == 'L') || (s[index + 1] == 'C')))
                {
                    value -= 10;
                }
                else
                {
                    value += 10;
                }
                break;
            case 'L':
                value += 50;
                break;
            case 'C':
                if ((index + 1 < s.length()) &&
                    ((s[index + 1] == 'D') || (s[index + 1] == 'M')))
                {
                    value -= 100;
                }
                else
                {
                    value += 100;
                }
                break;
            case 'D':
                value += 500;
                break;
            case 'M':
                value += 1000;
                break;
            default:
                break;
        }
    }

    return value;
}

///////////////////////////////////////////////////////////////////////////
// RomanToInt::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
int RomanToInt::optimizedOne(std::string s)
{
    // Initialize local variable
    int value = 0;
    size_t index = 0;
    std::unordered_map<char, int> romanNumerals;

    // Assign all Roman Numerals to the map
    romanNumerals['I'] = 1;
    romanNumerals['V'] = 5;
    romanNumerals['X'] = 10;
    romanNumerals['L'] = 50;
    romanNumerals['C'] = 100;
    romanNumerals['D'] = 500;
    romanNumerals['M'] = 1000;

    // Loop over the string
    for (index; index < s.length() - 1; index++)
    {
        // If the value for numeral at the current position is less than the
        // value for the numeral at the next position then subtract the value of
        // the current index
        if (romanNumerals[s[index]] < romanNumerals[s[index + 1]])
        {
            value -= romanNumerals[s[index]];
        }
        else
        {
            // Otherwise add the value for the numeral
            value += romanNumerals[s[index]];
        }
    }

    // Add the last character
    value += romanNumerals[s[index]];

    return value;
}
} // namespace alg
