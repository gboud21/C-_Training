#include "TwoSum.h"

#include <iostream>
#include <map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// TwoSum::TwoSum
///////////////////////////////////////////////////////////////////////////
TwoSum::TwoSum(FunctionVersion version) : m_functionVersion(version) {}

///////////////////////////////////////////////////////////////////////////
// TwoSum::twoSum()
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::twoSum(std::vector<int>& nums, int target)
{
    // Initialize local variables
    std::vector<int> failedVector;

    // Execute the desired implementation of the TwoSum algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(nums, target);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOneOrdered(nums, target);
            break;
        case OPTIMIZATION_TWO:
            return optimizedTwoOrdered(nums, target);
            break;
        case OPTIMIZATION_THREE:
            return optimizedThreeOrdered(nums, target);
            break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedVector;
}

///////////////////////////////////////////////////////////////////////////
// TwoSum::bruteForce(): PASSED
// Time Complexity:  O(N^2)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::bruteForce(std::vector<int>& nums, int target)
{
    // Initialize local variables
    std::vector<int> outputVector;

    // Loop over all elements summing them with all other elements and then
    // determining if any of them equal the target
    for (size_t i = 0; i < nums.size(); i++)
    {
        // Start the inner loop's index at 'i' so that the values which have
        // already been compared are not compared a second time
        for (size_t j = i; j < nums.size(); j++)
        {
            if ((i != j) && ((nums[i] + nums[j]) == target))
            {
                outputVector.push_back(i);
                outputVector.push_back(j);
                return outputVector;
            }
        }
    }

    return outputVector;
}

///////////////////////////////////////////////////////////////////////////
// TwoSum::optimizedOneOrdered():
// Time Complexity:  O(Nlog(N))
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::optimizedOneOrdered(std::vector<int>& nums, int target)
{
    // Initialize local variables
    std::vector<int> outputVector;
    std::map<int, int> orderedMap;

    // Sort the vector by inserting it into a map
    for (int frontIndex = 0; frontIndex < nums.size(); frontIndex++)
    {
        std::pair<std::map<int, int>::iterator, bool> ret = orderedMap.insert(
            std::pair<int, int>(nums[frontIndex], frontIndex));

        if (ret.second == false)
        {
            if (nums[frontIndex] + nums[frontIndex] == target)
            {
                outputVector.push_back(ret.first->second);
                outputVector.push_back(frontIndex);
                return outputVector;
            }
        }
    }

    // Start frontIt at the front of the ordered map
    // Start backIt at the end of the ordered map
    std::map<int, int>::iterator frontIt = orderedMap.begin();
    std::map<int, int>::iterator backIt = --orderedMap.end();

    // Loop until either a match is found or i and j have passed each other
    while (frontIt != backIt)
    {
        int value = frontIt->first + backIt->first;
        if (value == target)
        {
            outputVector.push_back(frontIt->second);
            outputVector.push_back(backIt->second);
            return outputVector;
        }
        else if (value > target)
        {
            backIt--;
        }
        else
        {
            frontIt++;
        }
    }

    return outputVector;
}

///////////////////////////////////////////////////////////////////////////
// TwoSum::optimizedTwoOrdered():
// Time Complexity:  O(Nlog(N))
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::optimizedTwoOrdered(std::vector<int>& nums, int target)
{
    // Initialize local variables
    std::vector<int> outputVector;
    std::map<int, int> orderedMap;

    // Sort the vector by inserting it into a map
    for (int frontIndex = 0; frontIndex < nums.size(); frontIndex++)
    {
        std::pair<std::map<int, int>::iterator, bool> ret = orderedMap.insert(
            std::pair<int, int>(nums[frontIndex], frontIndex));

        if (ret.second == false)
        {
            if (nums[frontIndex] + nums[frontIndex] == target)
            {
                outputVector.push_back(ret.first->second);
                outputVector.push_back(frontIndex);
                return outputVector;
            }
        }
    }

    // Iterate over the map trying to find a key that pairs with the current key
    for (std::map<int, int>::iterator it = orderedMap.begin();
         it != orderedMap.end(); it++)
    {
        std::map<int, int>::iterator secondIt =
            orderedMap.find(target - it->first);

        if (secondIt != orderedMap.end())
        {
            outputVector.push_back(it->second);
            outputVector.push_back(secondIt->second);
            return outputVector;
        }
    }

    return outputVector;
}

///////////////////////////////////////////////////////////////////////////
// TwoSum::optimizedThreeOrdered():
// Time Complexity:  O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::optimizedThreeOrdered(std::vector<int>& nums,
                                               int target)
{
    // Initialize local variables
    std::vector<int> outputVector;
    std::map<int, int> orderedMap;

    // Sort the vector by inserting it into a map
    for (int frontIndex = 0; frontIndex < nums.size(); frontIndex++)
    {
        // Try to find an exisitng key that is the difference of target and the
        // value at the current index
        std::map<int, int>::iterator it =
            orderedMap.find(target - nums[frontIndex]);

        // If a key is not found then insert the current index into the map
        if (it == orderedMap.end())
        {
            orderedMap[nums[frontIndex]] = frontIndex;
        }
        else
        {
            // Otherwise assign the values to the map and return
            outputVector.push_back(it->second);
            outputVector.push_back(frontIndex);
            return outputVector;
        }
    }

    return outputVector;
}

} // namespace alg
