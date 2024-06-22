#include "FirstBadVersion.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// FirstBadVersion::FirstBadVersion
///////////////////////////////////////////////////////////////////////////
FirstBadVersion::FirstBadVersion(FunctionVersion version, const int badVersion)
    : m_functionVersion(version), m_badVersion(badVersion)
{
}

///////////////////////////////////////////////////////////////////////////
// FirstBadVersion::isValid()
///////////////////////////////////////////////////////////////////////////
int FirstBadVersion::firstBadVersion(int n)
{
    // Initialize local variables
    int status = NULL;

    // Execute the desired implementation of the FirstBadVersion algorithm
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
// FirstBadVersion::bruteForce(): PASSED
// Time Complexity: O(log(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
int FirstBadVersion::bruteForce(int n)
{
    int min = 1;
    int badVersion = n / 2;

    // Perform a binary search of the version numbers to detect the first bad
    // version
    // Continue searching until the current version is bad and the version
    // before it is not bad
    while (!(isBadVersion(badVersion) && !isBadVersion(badVersion - 1)))
    {
        // If the current version is bad then the original bad version must be a
        // lower version number
        if (isBadVersion(badVersion))
        {
            n = badVersion - 1;
        }
        // Otherwise the bad version is a higher version number
        else
        {
            min = badVersion + 1;
        }

        // Update the bad version to the new middle of min and n
        badVersion = (n - min) / 2 + min;
    }

    return badVersion;
}

///////////////////////////////////////////////////////////////////////////
// FirstBadVersion::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// int FirstBadVersion::optimizedOne(int n)
// {
//     // Initialize local variable

//     return root;
// }

bool FirstBadVersion::isBadVersion(int version)
{
    // Return TRUE if
    // 1) Version is the first bad version or any version after than and it is
    // not the 0 version
    return ((version >= m_badVersion) && (version != 0));
}
} // namespace alg
