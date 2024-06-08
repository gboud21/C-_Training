#include "BinaryTree.h"

namespace dats
{
///////////////////////////////////////////////////////////////////////////
// BinaryTree::BinaryTree
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryTree<T>::BinaryTree(BinaryNode<T>* root) :
{
}

///////////////////////////////////////////////////////////////////////////
// BinaryTree::depthFirstSearch()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>* BinaryTree<T>::depthFirstSearch(T value)
{
    depthSearchChildren(&value, m_rootNode)
}

///////////////////////////////////////////////////////////////////////////
// BinaryTree::depthSearchChildren()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>* BinaryTree<T>::depthSearchChildren(T* value, BinaryNode<T>* node)
{
    // If either this node is NULL or contains the value being searched for then
    // return
    if (node == nullptr || node->getValue() == *value)
    {
        return node;
    }

    // If the node being searched for is in the left child's branch then return
    BinaryNode<T>* tempNode = depthSearchChildren(value, node->getLeftChild());
    if (tempNode != nullptr)
    {
        return tempNode;
    }

    // Otherwise return the results of searching the right child's branch
    return depthSearchChildren(value, node->getRightChild());
}

///////////////////////////////////////////////////////////////////////////
// BinaryTree::invertTree()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>* BinaryTree<T>::invertTree()
{
    // Start the recursive tree inversion call with the root node
    invertChildren(m_rootNode);

    return m_rootNode;
}

///////////////////////////////////////////////////////////////////////////
// BinaryTree::invertTree()
///////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryTree<T>::invertChildren(BinaryTree<T>* node)
{
    // If the node is NULL then return
    if (node == NULL)
    {
        return node;
    }

    // Swap the left and right node
    BinaryTree<T>* tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;

    // Recursively swap the children of the left and right nodes
    invertChildren(root->left);
    invertChildren(root->right);

    return root;
}
} // namespace dats
