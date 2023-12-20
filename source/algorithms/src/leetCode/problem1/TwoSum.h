#ifndef TWOSUM_H
#define TWOSUM_H
///////////////////////////////////////////////////////////////////////////////
/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time
complexity?
*/

#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{
class TwoSum
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    TwoSum(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] nums - An array of integers whose length is between 2 and 104
    // and whose values are between -109 and 109
    // \param [in] target - The desired sum of two intergers from within nums.
    // It is bound between -109 and 109
    // \return An array containing the two indicies from nums whose sum equals
    // target. Expected length of the array is 2
    ///////////////////////////////////////////////////////////////////////////
    std::vector<int> twoSum(std::vector<int>& nums, int target);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // TwoSum algorithm. It takes in an array of intergers and finds the two
    // indicies within the array whose sum is equal to the specified target. It
    // is guaranteed that there is only one pair of intergers whose sum equals
    // the target.
    // \param [in] nums - An array of integers whose length is between 2 and 104
    // and whose values are between -109 and 109
    // \param [in] target - The desired sum of two intergers from within nums.
    // It is bound between -109 and 109
    // \return An array containing the two indicies from nums whose sum equals
    // target. Expected length of the array is 2
    ///////////////////////////////////////////////////////////////////////////
    std::vector<int> bruteForce(std::vector<int>& nums, int target);

    // Determines which private implementation of the TwoSum algorithm is called
    // when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif