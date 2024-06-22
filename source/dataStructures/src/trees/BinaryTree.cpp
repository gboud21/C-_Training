#include "BinaryTree.h"

#include <queue>

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
// BinaryTree::addNode()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>* BinaryTree<T>::addNode(BinaryNode<T>* node)
{
    // If the tree is empty then just return
    if (m_rootNode == nullptr)
    {
        m_rootNode = node;
        return m_rootNode;
    }

    // Initialize a queue with the root node
    std::queue<BinaryNode<T>*> nodeQueue = {m_rootNode};

    // Iterate over each node layer from left to right searching for the target
    // value
    while (queue.front().getLeftChild() != nullptr &&
           queue.front().getRightChild() != nullptr)
    {
        // Push the queue's children and then pop the node at the front of the
        // queue
        nodeQueue.push(queue.front().getLeftChild());
        nodeQueue.push(queue.front().getRightChild());
        nodeQueue.pop();
    }

    // Set the node to the left child if it is NULL otherwise set the node to
    // the right child
    if (queue.front().getLeftChild() == nulltpr)
    {
        queue.front().setLeftChild(node);
    }
    else
    {
        queue.front().setRightChild(node);
    }
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
// BinaryTree::breadthFirstSearch()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>* BinaryTree<T>::breadthFirstSearch(T value)
{
    // If the tree is empty then just return
    if (m_rootNode == nullptr)
    {
        return nullptr;
    }

    // Initialize a queue with the root node
    std::queue<BinaryNode<T>*> nodeQueue = {m_rootNode};

    // Iterate over each node layer from left to right searching for the target
    // value
    while (queue.length() > 0)
    {
        // Retrieve the node at the front of the queue
        const BinaryNode<T>* currentNode = nodeQueue.front();

        // If the current node contains the value being searched for then return
        // the node
        if (currentNode.getValue() == value)
        {
            return currentNode;
        }

        // Remove the current node from the queue
        nodeQueue.pop();

        // Push each of the children of the current node to the queue to search
        // the next layer
        if (currentNode.getLeftChild() != nullptr)
        {
            nodeQueue.push(currentNode.getLeftChild());
        }

        if (currentNode.getRightChild() != nullptr)
        {
            nodeQueue.push(currentNode.getRightChild());
        }
    }
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
