#include "RansomNote.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// RansomNote::RansomNote
///////////////////////////////////////////////////////////////////////////
RansomNote::RansomNote(FunctionVersion version) : m_functionVersion(version) {}

///////////////////////////////////////////////////////////////////////////
// RansomNote::isValid()
///////////////////////////////////////////////////////////////////////////
bool RansomNote::ransomNote(std::string ransomNote, std::string magazine)
{
    // Initialize local variables
    bool status;

    // Execute the desired implementation of the RansomNote algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(ransomNote, magazine);
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
// RansomNote::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool RansomNote::bruteForce(std::string ransomNote, std::string magazine)
{
    bool isMatch = true;
    int characters[26];
    const int LOWER_A = 97;

    if (ransomNote.length() > magazine.length())
    {
        return false;
    }

    for (uint32_t index = 0; index < magazine.length(); index++)
    {
        characters[magazine.at(index) - 'a']++;

        if (index < ransomNote.length())
        {
            characters[ransomNote.at(index) - 'a']--;
        }
    }

    for (uint32_t index = 0; index < 26; index++)
    {
        isMatch &= characters[index] >= 0;
    }

    return isMatch;
}

///////////////////////////////////////////////////////////////////////////
// RansomNote::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// bool RansomNote::optimizedOne(std::string ransomnote, std::string magazine)
// {}
} // namespace alg
