#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Binary Search
Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: [0,10,20,30,40,50] target: 40
Output: 4

Input: [0,10,20,30,40,50] target: 100
Output: -1

Constraints:
1 <= nums.length <= 104
-10^4 < nums[i], target < 10^4
All the integers in nums are unique.
nums is sorted in ascending order.
*/

/* Scratch Pad:
Analysis:

Output:

Input:

Constraints:

Questions:
Q:
A:
*/

#include <iostream>
#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{
class BinarySearch
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    BinarySearch(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    int search(std::vector<int>& nums, int target);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function uses a loop to execute a binary search on the
    // specified array for the index that the target value is at
    // \param [in] nums - array of integers in asscending order
    // \param [in] target - The value to find in the array
    // \return int - the index the target value is at, -1 if the target is not
    // found
    ///////////////////////////////////////////////////////////////////////////
    int bruteForce(std::vector<int>& nums, int target);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function executes a recursive binary search on the
    // specified array for the index that the target value is at
    // \param [in] nums - array of integers in asscending order
    // \param [in] target - The value to find in the array
    // \return int - the index the target value is at, -1 if the target is not
    // found
    ///////////////////////////////////////////////////////////////////////////
    int optimizedOne(std::vector<int>& nums, int target);

    // Determines which private implementation of the BinarySearch
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif