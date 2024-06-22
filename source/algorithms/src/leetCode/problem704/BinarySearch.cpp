#include "BinarySearch.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// BinarySearch::BinarySearch
///////////////////////////////////////////////////////////////////////////
BinarySearch::BinarySearch(FunctionVersion version) : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// BinarySearch::isValid()
///////////////////////////////////////////////////////////////////////////
int BinarySearch::search(std::vector<int>& nums, int target)
{
    // Initialize local variables
    int status = -2;

    // Execute the desired implementation of the BinarySearch algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(nums, target);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(nums, target);
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
// BinarySearch::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int BinarySearch::bruteForce(std::vector<int>& nums, int target)
{
    int searchMin = 0;
    int searchMax = nums.size() - 1;

    // Binary search starts in the middle and divides the search range in half
    // until either the target is found or there is only one element left
    while (searchMin <= searchMax)
    {
        int searchIndex = (searchMax + searchMin) / 2;
        if (nums[searchIndex] == target)
        {
            return searchIndex;
        }
        else if (target > nums[searchIndex])
        {
            searchMin = searchIndex + 1;
        }
        else
        {
            searchMax = searchIndex - 1;
        }
    }

    return -1;
}

int recursiveBinarySearch(std::vector<int>& nums, int target, int minIndex,
                          int maxIndex)
{
    // Get the midpoint of the range of values
    const int searchIndex = (maxIndex - minIndex) / 2 + minIndex;

    // If we found the target then return the index
    if (nums[searchIndex] == target)
    {
        return searchIndex;
    }
    // If this was the last index to check then the value was not found
    else if (maxIndex - minIndex <= 0)
    {
        return -1;
    }
    // If the target is greater then the value then search the upper half of the
    // range
    else if (target > nums[searchIndex])
    {
        return recursiveBinarySearch(nums, target, searchIndex + 1, maxIndex);
    }
    // If the target is less then the value then search the lower half of the
    // range
    else
    {
        return recursiveBinarySearch(nums, target, minIndex, searchIndex - 1);
    }
}

///////////////////////////////////////////////////////////////////////////
// BinarySearch::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int BinarySearch::optimizedOne(std::vector<int>& nums, int target)
{
    return recursiveBinarySearch(nums, target, 0, nums.size() - 1);
}
} // namespace alg
