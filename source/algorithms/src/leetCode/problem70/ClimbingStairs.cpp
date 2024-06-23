#include "ClimbingStairs.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ClimbingStairs::ClimbingStairs
///////////////////////////////////////////////////////////////////////////
ClimbingStairs::ClimbingStairs(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// ClimbingStairs::isValid()
///////////////////////////////////////////////////////////////////////////
int ClimbingStairs::climbingStairs(int n)
{
    // Initialize local variables
    int status;

    // Execute the desired implementation of the ClimbingStairs algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(n);
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
// ClimbingStairs::bruteForce(): PASSED
// Time Complexity: O(log(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int ClimbingStairs::bruteForce(int n)
{
    // This problem is best solved using dynamic programming. The problem needs
    // to be reduced to its simplest form and then the solution for more complex
    // problems can be solved by using the solution to simpler problems

    // In this case the number of unique paths is equal to the sum of the number
    // of unique paths for the previous two number of stairs
    const size_t MAX_STAIRS = 46;
    int pathsPerStairs[MAX_STAIRS];

    pathsPerStairs[0] = 0;
    pathsPerStairs[1] = 1;
    pathsPerStairs[2] = 2;

    for (uint32_t index = 3; index <= n; index++)
    {
        pathsPerStairs[index] =
            pathsPerStairs[index - 1] + pathsPerStairs[index - 2];
    }

    return pathsPerStairs[n];
}

///////////////////////////////////////////////////////////////////////////
// ClimbingStairs::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// int ClimbingStairs::optimizedOne(int n) {}
} // namespace alg
