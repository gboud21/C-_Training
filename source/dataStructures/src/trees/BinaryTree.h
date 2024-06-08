#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <vector>

#include "BinaryNode.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace dats
{
template <typename T>
class BinaryTree
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    BinaryTree(BinaryNode<T>* root);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function performs a depth-first search of the binary tree
    // for the specified value
    // \param [in] value - the value to find in the binary tree
    // \return BinaryNode<T> * - A pointer to the node that contains the value
    // being searched for
    ///////////////////////////////////////////////////////////////////////////
    BinaryNode<T>* depthFirstSearch(T value);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function inverts the binary tree
    // \return BinaryNode<T> - A reference to the pointer to the root node
    ///////////////////////////////////////////////////////////////////////////
    BinaryNode<T>* invertTree();

    ///////////////////////////////////////////////////////////////////////////
    // \details Returns a reference to the pointer for the root node
    // \return Reference to the pointer to the root node
    ///////////////////////////////////////////////////////////////////////////
    BinaryNode<T>* getRootNode();

    ///////////////////////////////////////////////////////////////////////////
    // \details Sets the pointer to the root node
    // \param [in] right - the pointer to set the root node to
    ///////////////////////////////////////////////////////////////////////////
    void setRightChild(BinaryNode<T>* right);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function recusively performs a depth-first search of the
    // binary tree for the specified value
    // \param [in] value - pointer to the value to find in the binary tree
    // \return BinaryNode<T> * - A pointer to the node that contains the value
    // being searched for
    ///////////////////////////////////////////////////////////////////////////
    BinaryNode<T>* depthSearchChildren(T* value, BinaryNode<T>* node);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function recursively inverts the binary tree over the
    // vertical axis of the tree
    // \param [in] node - Pointer to the node to invert
    ///////////////////////////////////////////////////////////////////////////
    void invertChildren(BinaryNode<T>* node);

    // The root node for the tree
    BinaryNode<T>* m_rootNode;
};
} // namespace dats
#endif

#ifndef BINARYTREE_CPP
#include "BinaryTree.cpp"
#endif