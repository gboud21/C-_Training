#include "FloodFill.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// FloodFill::FloodFill
///////////////////////////////////////////////////////////////////////////
FloodFill::FloodFill(FunctionVersion version) : m_functionVersion(version) {}

///////////////////////////////////////////////////////////////////////////
// FloodFill::floodFill()
///////////////////////////////////////////////////////////////////////////
std::vector<std::vector<int>>
FloodFill::floodFill(std::vector<std::vector<int>>& image, int sr, int sc,
                     int color)
{
    // Initialize local variables
    std::vector<std::vector<int>> status;

    // Execute the desired implementation of the FloodFill algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(image, sr, sc, color);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(image, sr, sc, color);
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
// FloodFill::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
std::vector<std::vector<int>>
FloodFill::bruteForce(std::vector<std::vector<int>>& image, int sr, int sc,
                      int color)
{
    int currentColor = image[sr][sc];
    image[sr][sc] = -1;

    // Check Up - Boundary Condition and color match
    if (sc < image[sr].size() - 1 && currentColor == image[sr][sc + 1])
    {
        bruteForce(image, sr, sc + 1, color);
    }

    // Check Down - Boundary Condition and color match
    if (sc > 0 && currentColor == image[sr][sc - 1])
    {
        bruteForce(image, sr, sc - 1, color);
    }

    // Check Right - Boundary Condition and color match
    if (sr < image.size() - 1 && currentColor == image[sr + 1][sc])
    {
        bruteForce(image, sr + 1, sc, color);
    }

    // Check Left - Boundary Condition and color match
    if (sr > 0 && currentColor == image[sr - 1][sc])
    {
        bruteForce(image, sr - 1, sc, color);
    }

    // Lastly set the current pixel to the color
    image[sr][sc] = color;

    return image;
}

///////////////////////////////////////////////////////////////////////////
// FloodFill::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// std::vector<std::vector<int>>
// FloodFill::optimizedOne(std::vector<std::vector<int>>& image, int sr, int sc,
//                         int color)
// {
// }
} // namespace alg
