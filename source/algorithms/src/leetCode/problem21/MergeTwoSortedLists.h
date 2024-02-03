#ifndef MERGETWOSORTEDLISTS_H
#define MERGETWOSORTEDLISTS_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Roman to Integer
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

/* Scratch Pad:
Analysis:
Output: A pointer to the head of a sorted list with length list1.length +
        list2.length

Input: Two pointers to a linked list

Constraints:

Questions:
Q:
A:
*/

#include <iostream>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MergeTwoSortedLists
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    MergeTwoSortedLists(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] l1 - A pointer to the start of a sorted linked list
    // \param [in] l2 - A pointer to the start of a sorted linked list
    // \return ListNode* - A pointer to the start of a sorted linked list that
    // combines the input lists
    ///////////////////////////////////////////////////////////////////////////
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function iterates over each of the linked list comparing
    // each current node and selecting the node with the lesser value to add to
    // the output list
    // \param [in] l1 - A pointer to the start of a sorted linked list
    // \param [in] l2 - A pointer to the start of a sorted linked list
    // \return ListNode* - A pointer to the start of a sorted linked list that
    // combines the input lists
    ///////////////////////////////////////////////////////////////////////////
    ListNode* bruteForce(ListNode* l1, ListNode* l2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function iterates over each of the linked list comparing
    // each current node and re-linking the existing nodes to build the output
    // list to reduce memory consumption
    // \param [in] l1 - A pointer to the start of a sorted linked list
    // \param [in] l2 - A pointer to the start of a sorted linked list
    // \return ListNode* - A pointer to the start of a sorted linked list that
    // combines the input lists
    ///////////////////////////////////////////////////////////////////////////
    ListNode* optimizedOne(ListNode* l1, ListNode* l2);

    // Determines which private implementation of the MergeTwoSortedLists
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif