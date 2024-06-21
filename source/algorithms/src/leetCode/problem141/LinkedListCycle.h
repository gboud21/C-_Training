#ifndef LINKEDLISTCYCLE_H
#define LINKEDLISTCYCLE_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle
in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input:

Output:


Constraints:
The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list
*/

/* Scratch Pad:
Analysis:

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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    LinkedListCycle(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] head - Pointer to the start of the Linked List
    // \return int - TRUE if it is a a palindrome, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool hasCycle(ListNode* head);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function uses the tortoise and the hare method to detect a
    // loop/cycle in the linked list
    // \param [in] head - Pointer to the start of the Linked List
    // \return bool - TRUE if the linked list repeats, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool bruteForce(ListNode* head);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function executes a recursive binary search on the
    // specified array for the index that the target value is at
    // \param [in] nums - array of integers in asscending order
    // \param [in] target - The value to find in the array
    // \return int - the index the target value is at, -1 if the target is not
    // found
    ///////////////////////////////////////////////////////////////////////////
    // bool
    // optimizedOne(bool& image, int sr, int sc,
    //              int color);

    // Determines which private implementation of the LinkedListCycle
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif