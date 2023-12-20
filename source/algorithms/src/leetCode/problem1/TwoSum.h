#ifndef TWOSUM_H
#define TWOSUM_H
///////////////////////////////////////////////////////////////////////////////
/* Problem:
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

/* Scratch Pad:
Analysis:
-Output is a vector of size 2 with two unique values in the range of
 [0,nums.length - 1]

-Both target and the value at each index in the array is in
 the range of [-109,109] so maximum integer overflow does not need to be
 considered

-Maximum length of the input array is 104 so a more sophisticated calculation
 algorithm does noticeably improve performance

Questions:
Q:  Can I assume that the input constraints are always true, or
    do I need to provide error handling if one of the constraints are violated?
    If so then is there an expected output for the error case? Should an
    exception be thrown?
A:  Error handling is not required. The inputs are guaranteed to be within the
    specified bounds.

Q:  Is the array sorted or unsorted?
A:  Unsorted.
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

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm to reduce the time complexity down to O(Nlog(N))
    // \param [in] nums - An array of integers whose length is between 2 and 104
    // and whose values are between -109 and 109
    // \param [in] target - The desired sum of two intergers from within nums.
    // It is bound between -109 and 109
    // \return An array containing the two indicies from nums whose sum
    // equals target. Expected length of the array is 2
    ///////////////////////////////////////////////////////////////////////////
    std::vector<int> optimizedOneOrdered(std::vector<int>& nums, int target);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides a cleaner version of the previous version
    // \param [in] nums - An array of integers whose length is between 2 and 104
    // and whose values are between -109 and 109
    // \param [in] target - The desired sum of two intergers from within nums.
    // It is bound between -109 and 109
    // \return An array containing the two indicies from nums whose sum
    // equals target. Expected length of the array is 2
    ///////////////////////////////////////////////////////////////////////////
    std::vector<int> optimizedTwoOrdered(std::vector<int>& nums, int target);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm to reduce the time complexity down to O(N)
    // \param [in] nums - An array of integers whose length is between 2 and 104
    // and whose values are between -109 and 109
    // \param [in] target - The desired sum of two intergers from within nums.
    // It is bound between -109 and 109
    // \return An array containing the two indicies from nums whose sum
    // equals target. Expected length of the array is 2
    ///////////////////////////////////////////////////////////////////////////
    std::vector<int> optimizedThreeOrdered(std::vector<int>& nums, int target);

    // Determines which private implementation of the TwoSum algorithm is called
    // when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif