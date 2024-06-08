#include "InvertBinaryTree.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// InvertBinaryTree::InvertBinaryTree
///////////////////////////////////////////////////////////////////////////
InvertBinaryTree::InvertBinaryTree(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// InvertBinaryTree::isValid()
///////////////////////////////////////////////////////////////////////////
TreeNode* InvertBinaryTree::invertTree(TreeNode* root)
{
    // Initialize local variables
    TreeNode* status = NULL;

    // Execute the desired implementation of the InvertBinaryTree algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(root);
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
// InvertBinaryTree::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
TreeNode* InvertBinaryTree::bruteForce(TreeNode* root)
{
    // If the node is NULL then return
    if (root == NULL)
    {
        return root;
    }

    TreeNode* tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;

    bruteForce(root->left);
    bruteForce(root->right);

    return root;
}

///////////////////////////////////////////////////////////////////////////
// InvertBinaryTree::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// TreeNode* InvertBinaryTree::optimizedOne(TreeNode* root)
// {
//     // Initialize local variable

//     return root;
// }
} // namespace alg
