#include "TwoSum.h"

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
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedVector;
}

///////////////////////////////////////////////////////////////////////////
// TwoSum::bruteForce()
///////////////////////////////////////////////////////////////////////////
std::vector<int> TwoSum::bruteForce(std::vector<int>& nums, int target)
{
    // Initialize local variables
    std::vector<int> failedVector;

    return failedVector;
}

} // namespace alg
