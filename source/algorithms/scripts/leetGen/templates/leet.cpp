#include "LEET_OBJ.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// LEET_OBJ::LEET_OBJ
///////////////////////////////////////////////////////////////////////////
LEET_OBJ::LEET_OBJ(FunctionVersion version) : m_functionVersion(version) {}

///////////////////////////////////////////////////////////////////////////
// LEET_OBJ::LEET_FUNC()
///////////////////////////////////////////////////////////////////////////
LEET_RETURN LEET_OBJ::LEET_FUNC(LEET_PARAMS)
{
    // Initialize local variables
    LEET_RETURN status;

    // Execute the desired implementation of the LEET_OBJ algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(n);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(root);
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
// LEET_OBJ::bruteForce(): PASSED
// Time Complexity: O()
// Space Complexity: O()
///////////////////////////////////////////////////////////////////////////
LEET_RETURN LEET_OBJ::bruteForce(LEET_PARAMS) {}

///////////////////////////////////////////////////////////////////////////
// LEET_OBJ::optimizedOne():
// Time Complexity: O()
// Space Complexity: O()
///////////////////////////////////////////////////////////////////////////
// LEET_RETURN LEET_OBJ::optimizedOne(LEET_PARAMS)
// {
// }
} // namespace alg
