#ifndef SUBSTRINGWOREPEAT_H
#define SUBSTRINGWOREPEAT_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

/* Scratch Pad:
Analysis:
Output: The middle value of all of the values in the two arrays

Input: Two arrays of integers that are already sorted.

Constraints:
Algorithm must run in log(m+n) time where m is the size of the first array and n
is the size of the second array

Questions:
Q: What happens if there are an even number of values (ie m+n%2 = 0). Should we
just get the average of the two center values?
A: Yes
*/

#include "AlgorithmTypes.h"
#include <vector>

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class MedianTwoSortedArrays
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    MedianTwoSortedArrays(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] nums1 - Sorted array of integers
    // \param [in] nums2 - Sorted array of integers
    // \return double - the median value of nums1+nums2. Will be in the range
    // {-10^6, 10^6}
    ///////////////////////////////////////////////////////////////////////////
    double findMedianSortedArrays(std::vector<int>& nums1,
                                  std::vector<int>& nums2);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // MedianTwoSortedArrays algorithm. It will not meet the target conditions,
    // but will solve the problem
    // \param [in] nums1 - Sorted array of integers
    // \param [in] nums2 - Sorted array of integers
    // \return double - the median value of nums1+nums2. Will be in the range
    // {-10^6, 10^6}
    ///////////////////////////////////////////////////////////////////////////
    double bruteForce(std::vector<int>& nums1, std::vector<int>& nums2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that meets the time complexity requirements of log(m+n)
    // \param [in] nums1 - Sorted array of integers
    // \param [in] nums2 - Sorted array of integers
    // \return double - the median value of nums1+nums2. Will be in the range
    // {-10^6, 10^6}
    ///////////////////////////////////////////////////////////////////////////
    double optimizedOne(std::vector<int>& nums1, std::vector<int>& nums2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that meets the time complexity requirements of log(m+n)
    // \param [in] nums1 - Sorted array of integers
    // \param [in] nums2 - Sorted array of integers
    // \return double - the median value of nums1+nums2. Will be in the range
    // {-10^6, 10^6}
    ///////////////////////////////////////////////////////////////////////////
    // double recursiveOptimizedOne(std::vector<int>& nums1,
    //                              std::vector<int>& nums2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides a private entry point into the Binary
    // Search with two array algorithm
    // \param [in] nums1 - The array with less elements
    // \param [in] nums2 - The array with more elements
    // \return double - the median value of nums1+nums2. Will be in the range
    // {-10^6, 10^6}
    ///////////////////////////////////////////////////////////////////////////
    // double recursiveFindMedian(std::vector<int>& nums1,
    //                            std::vector<int>& nums2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function evaluates special entry conditions that trigger an
    // automatic return of a median value
    // \param [in] nums1 - The array with less elements
    // \param [in] nums2 - The array with more elements
    // \param [out] nums2 - The median value of nums1+nums2. Will be in the
    // range {-10^6, 10^6}
    // \return bool - TRUE if one of the entry conditions was detected, FALSE
    // otherwise
    ///////////////////////////////////////////////////////////////////////////
    // bool evaluateSpecialEntryCases(std::vector<int>& nums1,
    //                                std::vector<int>& nums2, double& median);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function evaluates terminating conditions that can occur
    // when there is only one element in the first array
    // \param [in] nums1 - Array containing either one or two elements
    // \param [in] nums2 - Sorted array with an even number of elements
    // \param [in] nums2Middle - The center index of nums2
    // \param [out] nums2 - The median value of nums1+nums2. Will be in the
    // range {-10^6, 10^6}
    // \return bool - TRUE if one of the terminaitng conditions was detected,
    // FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    // bool evaluateEvenLengthArray(std::vector<int>& nums1,
    //                              std::vector<int>& nums2,
    //                              const size_t nums2Middle, double& median);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function evaluates terminating conditions that can occur
    // when there is only one element in the first array
    // \param [in] nums1 - Array containing either one or two elements
    // \param [in] nums2 - Sorted array with an odd number of elements
    // \param [in] nums2Middle - The center index of nums2
    // \param [out] nums2 - The median value of nums1+nums2. Will be in the
    // range {-10^6, 10^6}
    // \return bool - TRUE if one of the terminaitng conditions was detected,
    // FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    // bool evaluateOddLengthArray(std::vector<int>& nums1,
    //                             std::vector<int>& nums2,
    //                             const size_t nums2Middle, double& median);

    // Determines which private implementation of the MedianTwoSortedArrays
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif