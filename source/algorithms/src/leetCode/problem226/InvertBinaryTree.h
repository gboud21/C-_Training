#ifndef INVERTBINARYTREE_H
#define INVERTBINARYTREE_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: [null]
Output: [null]

Example 2:
Input:
                    1
                2       3
            4     5   6     7
Output:
                    1
                3       2
            7     6   5     4

Example 3:
Input:
                    1
                2       3
            4         5
Output:
                    1
                3       2
                   5       4

Example 4:
Input:
                    1
                2          3
            4     5      6     7
          8   9  0  1  2   3  4  5
Output:
                    1
                3          2
            7     6      5     4
          5   4  3  2  1   0  9  8


Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

/* Scratch Pad:
Analysis:
-Basically flip the tree along the vertical axis

Output: Pointer to the root node of the tree

Input: Pointer to the root node

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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class InvertBinaryTree
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    InvertBinaryTree(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    TreeNode* invertTree(TreeNode* root);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function filters the input string to remove all
    // non-alplanumeric characters and then uses the two pointer method to start
    // at each end of the string and compare the left and right pointer to each
    // other to check if the characters are equivalent (case-insensitive).
    // Pointers move towards each other if either they match or are the
    // character is not alphanumeric.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    TreeNode* bruteForce(TreeNode* root);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function filters the input string to remove all
    // non-alplanumeric characters and then uses the two pointer method to start
    // at each end of the string and compare the left and right pointer to each
    // other to check if the characters are equivalent (case-insensitive).
    // Pointers move towards each other if either they match or are the
    // character is not alphanumeric.
    // \param [in] s - string of ascii characters
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    // TreeNode* optimizedOne(TreeNode* root);

    // Determines which private implementation of the InvertBinaryTree
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif