#include "SubstringWoRepeat.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// SubstringWoRepeat::SubstringWoRepeat
///////////////////////////////////////////////////////////////////////////
SubstringWoRepeat::SubstringWoRepeat(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// SubstringWoRepeat::substringWoRepeat()
///////////////////////////////////////////////////////////////////////////
int SubstringWoRepeat::substringWoRepeat(std::string s)
{
    // Initialize local variables
    int failedStatus = -1;

    // Execute the desired implementation of the SubstringWoRepeat algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(s);
            break;
        case OPTIMIZATION_TWO:
            return optimizedTwo(s);
            break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// SubstringWoRepeat::bruteForce(): PASSED
// Time Complexity: O(N^2)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
int SubstringWoRepeat::bruteForce(std::string s)
{
    // Initialize local variable
    int maxLength = 0;

    // Return immediately if the string is empty
    if (s.length() == 0)
    {
        return 0;
    }

    // Loop over every character and then loop over every other character to
    // find the maximum string keeping track of the current length of the string
    // and what characters are currently contained in the string
    for (size_t index = 0; index < s.length(); index++)
    {
        // Initialize loop variables
        bool duplicateFound = false;
        size_t index2 = index + 1;
        int tempCount = 1;
        std::map<char, int> substringChars;
        substringChars.insert(std::pair<char, int>(s[index], index));

        // Loop over the remaining characters until either a duplicate is found
        // or the end of the string is reached
        while (duplicateFound == false && index2 < s.length())
        {
            // Try to insert the character into a HashMap. This provides a quick
            // way to check if the character has been used
            std::pair<std::map<char, int>::iterator, bool> node =
                substringChars.insert(std::pair<char, int>(s[index2], index2));

            // If the character is successfully inserted then add to the count
            // and increment the current index
            duplicateFound = !node.second;
            if (duplicateFound == false)
            {
                tempCount++;
            }

            index2++;
        }

        // If a longer substring was found then update the maximum length found
        if (maxLength < tempCount)
        {
            maxLength = tempCount;
        }
    }

    // Return the maximum length of the substring without repeats
    return maxLength;
}

///////////////////////////////////////////////////////////////////////////
// SubstringWoRepeat::optimizedOne():
// Time Complexity: O(Nlog(N))
// Space Complexity: O(2N)
///////////////////////////////////////////////////////////////////////////
int SubstringWoRepeat::optimizedOne(std::string s)
{
    // Initialize local variables
    int maxLength = 0;
    std::map<char, size_t> substringChars;

    // Return immediately if the string is empty
    if (s.length() == 0)
    {
        return 0;
    }

    // Loop over the input string keeping track of the current substring as well
    // as the characters currerntly contained within the substring
    // Initialize local variable
    for (size_t index = 0; index < s.length(); index++)
    {
        // Try to insert the character into a HashMap. This provides a quick
        // way to check if the character has been used
        std::pair<std::map<char, size_t>::iterator, bool> node =
            substringChars.insert(
                std::pair<char, size_t>(s[index], substringChars.size()));

        // If the character already exists in the substring then remove all of
        // the characters up to the previous entry
        if (node.second == false)
        {
            char duplicateChar = s[index];

            // If the current substring is longer than the maximum then update
            // the maximum length
            if (maxLength < substringChars.size())
            {
                maxLength = substringChars.size();
            }

            // Remove all of the characters up to the duplicated character from
            // the map
            std::map<char, size_t>::iterator it = substringChars.begin();
            while (it != substringChars.end())
            {
                // If the character is located before the duplicate then delete
                // it from the map
                if (it->second < substringChars[duplicateChar])
                {
                    std::map<char, size_t>::iterator tempIt = it++;
                    substringChars.erase(tempIt);
                }
                else if (it != node.first)
                {
                    // Otherwise if the character is after the duplicate
                    // character's position AND it is not the duplicate
                    // character
                    // then subtract the number of deleted characters
                    // from its current position
                    it->second -= node.first->second + 1;
                    it++;
                }
                else
                {
                    it++;
                }
            }

            // Update the index of the found character to the current index
            substringChars[duplicateChar] = substringChars.size() - 1;
        }
    }

    // If the final substring is longer than the max length detected then
    // update the max length
    if (maxLength < substringChars.size())
    {
        maxLength = substringChars.size();
    }

    // Return the maximum length of the substring without repeats
    return maxLength;
}

///////////////////////////////////////////////////////////////////////////
// SubstringWoRepeat::optimizedTwo(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
int SubstringWoRepeat::optimizedTwo(std::string s)
{
    // Initialize local variables
    // Initialize left and right bounds of Sliding Window
    size_t left = 0;
    size_t right = 0;
    int maxLength = 0;
    std::unordered_map<char, int> substringChars;

    // Return immediately if the string is empty
    if (s.length() == 0)
    {
        return maxLength;
    }

    // Loop over the input string to find the maximum substring without
    // repeating characters
    while (right < s.length())
    {
        // Increase the count for the character at the current position in the
        // string. This will create the element if it does not already exist
        substringChars[s[right]]++;

        // Calculate the size of the window
        int windowSize = right - left + 1;

        // If the map size is equal to the window size then all characters in
        // the map are unique
        if (substringChars.size() == windowSize)
        {
            // Update the Maximum Substring Length if the current window size is
            // larger
            maxLength = std::max(maxLength, windowSize);
        }
        else if (substringChars.size() < windowSize)
        {
            // Otherwise not all characters are unique because the map contains
            // less elements than the window contains so the window edges and
            // the map's elements must be adjusted

            // Loop until the duplicates are removed
            while (substringChars.size() < windowSize)
            {
                // Remove the duplicates from the map
                substringChars[s[left]]--;

                // If this is the last instance of the character
                if (substringChars[s[left]] == 0)
                {
                    // Delete it from the map
                    substringChars.erase(s[left]);
                }

                left++;
                windowSize = right - left + 1;
            }
        }

        right++;
    }

    return maxLength;
}
} // namespace alg
