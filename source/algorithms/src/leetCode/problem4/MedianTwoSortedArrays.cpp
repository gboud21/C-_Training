#include "MedianTwoSortedArrays.h"

#include <algorithm>
#include <cmath>
#include <float.h>
#include <iostream>
#include <limits.h>
#include <map>
#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::MedianTwoSortedArrays
///////////////////////////////////////////////////////////////////////////
MedianTwoSortedArrays::MedianTwoSortedArrays(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::medianTwoSortedArrays()
///////////////////////////////////////////////////////////////////////////
double MedianTwoSortedArrays::findMedianSortedArrays(std::vector<int>& nums1,
                                                     std::vector<int>& nums2)
{
    // Initialize local variables
    double failedStatus = -1;

    // Execute the desired implementation of the MedianTwoSortedArrays algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(nums1, nums2);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(nums1, nums2);
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
// MedianTwoSortedArrays::bruteForce(): PASSED
// Time Complexity: O(M+N)
// Space Complexity: O(M+N)
///////////////////////////////////////////////////////////////////////////
double MedianTwoSortedArrays::bruteForce(std::vector<int>& nums1,
                                         std::vector<int>& nums2)
{
    // Initialize local variable
    double median = 0;
    std::vector<int> combinedNums;
    size_t index1 = 0;
    size_t index2 = 0;

    // Loop over the arrays incrementing until we reach the median of the two
    // arrays.
    // Need to do something extra for even number since we need both
    // values.
    // The loop also needs to handle the mismatched length of arrays.
    while (index1 < nums1.size() && index2 < nums2.size())
    {
        if (nums1[index1] < nums2[index2])
        {
            combinedNums.push_back(nums1[index1]);
            index1++;
        }
        else
        {
            combinedNums.push_back(nums2[index2]);
            index2++;
        }
    }

    // If there are still numbers left in the first array then continue adding
    // them
    if (index1 < nums1.size())
    {
        for (index1; index1 < nums1.size(); index1++)
        {
            combinedNums.push_back(nums1[index1]);
        }
    }
    else if (index2 < nums2.size())
    {
        // Otherwise there are still numbers left in the second array then
        // continue adding them
        for (index2; index2 < nums2.size(); index2++)
        {
            combinedNums.push_back(nums2[index2]);
        }
    }

    // Calculate the median
    if (combinedNums.size() % 2 == 0)
    {
        median =
            static_cast<double>(combinedNums[combinedNums.size() / 2] +
                                combinedNums[combinedNums.size() / 2 - 1]) /
            2;
    }
    else
    {
        median = combinedNums[combinedNums.size() / 2];
    }

    // Return the maximum length of the substring without repeats
    return median;
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::optimizedOne():
// Time Complexity: O(log(M+N))
// Space Complexity:
///////////////////////////////////////////////////////////////////////////
double MedianTwoSortedArrays::optimizedOne(std::vector<int>& nums1,
                                           std::vector<int>& nums2)
{
    // Initialize local variables
    double median = 0;

    size_t nums1Size = nums1.size();
    size_t nums2Size = nums2.size();
    size_t totalSize = nums1.size() + nums2.size();

    // If the first array contains more elements than the second array then swap
    // nums2 to be the first array to reduce the number of base cases that need
    // to be handled by the algorithm
    if (nums1Size > nums2Size)
    {
        return optimizedOne(nums2, nums1);
    }

    // Find the middle index of the theoretically combined array of elements
    size_t combinedMiddle = (totalSize + 1) / 2;
    size_t nums1Middle = nums1Size / 2;
    size_t nums2Middle = nums2Size / 2;

    // If the first array is empty then just calculate the median of the second
    // array
    if (nums1Size == 0)
    {
        if (nums2Size % 2 == 0)
        {
            return (nums2[nums2Middle] + nums2[nums2Middle - 1]) / 2.0;
        }
        else
        {
            return nums2[nums2Middle];
        }
    }

    // If the second array is empty then just calculate the median of the first
    // array
    if (nums2Size == 0)
    {
        if (nums1Size % 2 == 0)
        {
            return (nums1[nums1Middle] + nums1[nums1Middle - 1]) / 2.0;
        }
        else
        {
            return nums1[nums1Middle];
        }
    }

    // Enter loop to try to search through the data set
    size_t nums1Left = 0;
    size_t nums1Right = nums1Size;

    // The left bound of the dataset range
    int cut1;

    // The right bound of the dataset range
    int cut2;

    // The left and right bounds of the range of data being evaluated from nums1
    int l1;
    int r1;

    // The left and right bounds of the range of data being evaluated from nums2
    int l2;
    int r2;

    do
    {
        // Calculate the slice positions in the data set
        // cut1 identifies the middle of the first array
        cut1 = (nums1Left + nums1Right) / 2;

        // cut2 identifies the data from
        cut2 = combinedMiddle - cut1;

        // Calculate l1
        if (cut1 == 0)
        {
            l1 = INT_MIN;
        }
        else
        {
            l1 = nums1[cut1 - 1];
        }

        if (cut2 == 0)
        {
            l2 = INT_MIN;
        }
        else
        {
            l2 = nums2[cut2 - 1];
        }

        // Calculate r1
        if (cut1 >= nums1Size)
        {
            r1 = INT_MAX;
        }
        else
        {
            r1 = nums1[cut1];
        }

        // Calculate r2
        if (cut2 >= nums2Size)
        {
            r2 = INT_MAX;
        }
        else
        {
            r2 = nums2[cut2];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            if (totalSize % 2 == 0)
            {
                return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
            }
            else
            {
                return std::max(l1, l2);
            }
        }
        else
        {
            if (l1 > r2)
            {
                nums1Right = cut1 - 1;
            }
            else
            {
                nums1Left = cut1 + 1;
            }
        }
    } while (nums1Left <= nums1Right);

    // Return the maximum length of the substring without repeats
    return median;
}

/* ToDo: Come back and see if I can get this working properly.
         Probably some flawed logic in
         recursiveFindMedian()::nums1.size() == 2
///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::optimizedOne():
// Time Complexity: O(log(M+N))
// Space Complexity:
///////////////////////////////////////////////////////////////////////////
double MedianTwoSortedArrays::optimizedOne(std::vector<int>& nums1,
                                           std::vector<int>& nums2)
{
    // Initialize local variables
    double median = DBL_MIN;

    // If the first array is shorter than the second array then call the entry
    // function with the first array as the shorter array
    if (nums1.size() < nums2.size())
    {
        median = recursiveFindMedian(nums1, nums2);
    }
    else
    {
        // Otherwise call the entry with the second array set as the shorter
        // array
        median = recursiveFindMedian(nums2, nums1);
    }

    return median;
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::recursiveFindMedian():
///////////////////////////////////////////////////////////////////////////
double MedianTwoSortedArrays::recursiveFindMedian(std::vector<int>& nums1,
                                                  std::vector<int>& nums2)
{
    double median = DBL_MIN;

    if (evaluateSpecialEntryCases(nums1, nums2, median))
    {
        return median;
    }

    // Calculate the middle position of each array
    size_t nums1Middle = nums1.size() / 2;
    size_t nums2Middle = nums2.size() / 2;

    // Base case evaluation for when there is only one element left in the first
    // array
    if (nums1.size() == 1)
    {
        // If the number of elements in the second array is even then
        if (nums2.size() % 2 == 0)
        {
            if (evaluateEvenLengthArray(nums1, nums2, nums2Middle, median))
            {
                return median;
            }
        }
        else
        {
            if (evaluateOddLengthArray(nums1, nums2, nums2Middle, median))
            {
                return median;
            }
        }
    }
    else if (nums1.size() == 2)
    {
        if (nums2.size() == 2)
        { // If there are four elements left AND they are divided evenly
            // between the two arrays then return the average of the maximum of
            // the first two values and the minimum of the second two values.
            // This avoids an infinite loop conditions
            return (std::max(nums1[0], nums2[0]) +
                    std::min(nums1[1], nums2[1])) /
                   2;
        }
        // If the number of elements in the second array is even then
        else if (nums2.size() % 2 == 0)
        {
            if (evaluateEvenLengthArray(nums1, nums2, nums2Middle, median))
            {
                return median;
            }
        }
        else
        {
            if (evaluateOddLengthArray(nums1, nums2, nums2Middle, median))
            {
                return median;
            }
        }
    }
    else
    {
        // Make a decision on what the next range to search is
        // If the median of the first array is less than the median of the
        // second array then examine the upper half of the first array and the
        // lower half of the second array
        if (nums1[nums1Middle] < nums2[nums2Middle])
        {
            std::vector<int> upperNums1;
            std::vector<int> lowerNums2;

            for (size_t index = nums1Middle + 1; index < nums1.size(); index++)
            {
                upperNums1.push_back(nums1[index]);
            }

            for (size_t index = 0; index < (nums2.size() - nums1Middle);
                 index++)
            {
                lowerNums2.push_back(nums2[index]);
            }

            return recursiveFindMedian(upperNums1, lowerNums2);
        }
        else
        {
            std::vector<int> lowerNums1;
            std::vector<int> upperNums2;

            for (size_t index = 0; index < nums1Middle - 1; index++)
            {
                lowerNums1.push_back(nums1[index]);
            }

            for (size_t index = nums1Middle; index < nums2.size(); index++)
            {
                upperNums2.push_back(nums2[index]);
            }

            return recursiveFindMedian(lowerNums1, upperNums2);
        }
    }

    return median;
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::recursiveFindMedian():
///////////////////////////////////////////////////////////////////////////
bool MedianTwoSortedArrays::evaluateSpecialEntryCases(std::vector<int>& nums1,
                                                      std::vector<int>& nums2,
                                                      double& median)
{
    bool specialCaseDetected = false;

    // Remeber, when this function is called. It is guaranteed that nums1 has
    // less elements in it than nums2
    // If the first array does not contain any elements then we can return
    // immediately with either an error, or with the middle value of nums2
    if (nums1.size() == 0)
    {
        if (nums2.size() == 0)
        {
            median = DBL_MIN;
        }
        else
        {
            median = nums2[nums2.size() / 2];
        }

        specialCaseDetected = true;
    }

    // Evaluate the special cases provided by the data sets
    // If there are only two elements left AND they are divided evenly between
    // the two arrays then return the average of the two values. This avoids an
    // infinite loop condition
    if (nums1.size() == 1 && nums2.size() == 1)
    {
        median = (nums1[0] + nums2[0]) / 2;
        specialCaseDetected = true;
    }

    return specialCaseDetected;
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::evaluateEvenLengthArray():
///////////////////////////////////////////////////////////////////////////
bool MedianTwoSortedArrays::evaluateEvenLengthArray(std::vector<int>& nums1,
                                                    std::vector<int>& nums2,
                                                    const size_t nums2Middle,
                                                    double& median)
{
    bool terminatingCaseDetected = false;

    // If the value in the first array is less than the median of the
    // second array then the median is the median of the second array
    if (nums1[0] < nums2[nums2Middle])
    {
        median = nums2[nums2Middle];
        terminatingCaseDetected = true;
    }
    else if (nums1[0] > nums2[nums2Middle] && nums1[0] > nums2[nums2Middle + 1])
    {
        // Otherwise if the value in the first array is greater than the
        // median of the second array and the value above the median
        // than the median is the value in the first array
        median = nums1[0];
        terminatingCaseDetected = true;
    }
    else if (nums1[0] > nums2[nums2Middle + 1])
    {
        // Otherwise if the value in the first array is less than the
        // median of the second array and greater than the value above
        // the median than the median is the greater value in the second
        // array
        median = nums2[nums2Middle + 1];
        terminatingCaseDetected = true;
    }

    return terminatingCaseDetected;
}

///////////////////////////////////////////////////////////////////////////
// MedianTwoSortedArrays::evaluateOddLengthArray():
///////////////////////////////////////////////////////////////////////////
bool MedianTwoSortedArrays::evaluateOddLengthArray(std::vector<int>& nums1,
                                                   std::vector<int>& nums2,
                                                   const size_t nums2Middle,
                                                   double& median)
{
    bool terminatingCaseDetected = false;

    // Otherwise there is an odd number of values in the second array
    if (nums1[0] > nums2[nums2Middle - 1])
    {
        // Otherwise if the value in the first array is less than the
        // median of the second array and greater than the value above
        // the median than the median is the average of the median and
        // the value less than the median from the second array
        return nums2[nums2Middle + 1];
    }
    else if (nums1[0] > nums2[nums2Middle - 1] && nums1[0] > nums2[nums2Middle])
    {
        return (nums1[0] + nums2[nums2Middle]);
    }
    else if (nums1[0] > nums2[nums2Middle] && nums1[0] > nums2[nums2Middle + 1])
    {
        return (nums1[0] + nums2[nums2Middle + 1]);
    }
    else
    {
        return (nums2[nums2Middle] + nums2[nums2Middle + 1]);
    }
    return terminatingCaseDetected;
}*/

} // namespace alg
