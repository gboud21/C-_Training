#ifndef FLOODFILL_H
#define FLOODFILL_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Flood Fill
An image is represented by an m x n integer grid image where image[i][j]
represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood
fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected
4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same
color), and so on. Replace the color of all of the aforementioned pixels with
color.

Return the modified image after performing the flood fill.

Example 1:
Colors are 0 --> 4
Input: sr = 2, sc = 2, color = 3
    0 1 2 3 4 5 6 7

0   1 2 3 4 5 6 7 8
1   1 2 2 2 5 6 7 8
2   2 2 2 2 5 6 7 8
3   1 2 3 4 5 6 7 8
4   1 2 3 4 5 6 7 8
5   1 2 2 2 2 2 2 2
6   1 2 3 4 5 6 2 8
7   1 2 3 4 5 6 2 8

Output:
    0 1 2 3 4 5 6 7

0   1 3 3 4 5 6 7 8
1   1 3 3 3 5 6 7 8
2   3 3 3 3 5 6 7 8
3   1 3 3 4 5 6 7 8
4   1 3 3 4 5 6 7 8
5   1 3 3 3 3 3 3 3
6   1 3 3 4 5 6 3 8
7   1 3 3 4 5 6 3 8

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

/* Scratch Pad:
Analysis:
1) Given a pixel in a 2d array
2) Update all pixels that are both to the top, bottom, left and right that are
   the same color as it to the new color.
3) Repeat 2 for each pixel updated until no more pixels need to be updated.

- This type of problem lends itself to a recursive implementation that would
  terminate automatically when no more pixels need to be updated.
- Is there a possible effeciency by passing in the direction as an additional
parameter? Or would that just add additional checks that are actually less
efficient?

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
class FloodFill
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    FloodFill(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>>
    floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function uses a loop to execute a binary search on the
    // specified array for the index that the target value is at
    // \param [in] nums - array of integers in asscending order
    // \param [in] target - The value to find in the array
    // \return int - the index the target value is at, -1 if the target is not
    // found
    ///////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>>
    bruteForce(std::vector<std::vector<int>>& image, int sr, int sc, int color);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function executes a recursive binary search on the
    // specified array for the index that the target value is at
    // \param [in] nums - array of integers in asscending order
    // \param [in] target - The value to find in the array
    // \return int - the index the target value is at, -1 if the target is not
    // found
    ///////////////////////////////////////////////////////////////////////////
    // std::vector<std::vector<int>>
    // optimizedOne(std::vector<std::vector<int>>& image, int sr, int sc,
    //              int color);

    // Determines which private implementation of the FloodFill
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif