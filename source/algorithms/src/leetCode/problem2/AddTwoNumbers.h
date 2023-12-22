#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H
///////////////////////////////////////////////////////////////////////////////
/* Problem:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

-The number of nodes in each linked list is in the range [1, 100].
-0 <= Node.val <= 9
-It is guaranteed that the list represents a number that does not have leading
 zeros.
*/

/* Scratch Pad:
Analysis:
-Output: A linked list where each node represents a digit in the sum of two
 numbers. Maximum number of nodes in returned list is 100 + 1 = 101 to support
the carry

-Input: Two pointers to the start of a linked list where each node in the list
represents a digit in the number.

Constraints:
-Each number represented by the list is greater than or equal to 0.
-Each number represented by the list is guaranteed to not have leading zeros.
    -This basically just means that the list will not go on infinitely
-Numbers are stored in reverse order which means that the least significant
number is at the start of the list and the most significant number is at the end
of the list
-The first element in each list is guaranteed to not be NULL

Questions:
Q: In this scenario, is the expectation that the input lists are unmodified?
Basically is it important that additional memory should not be used unless
absoloutely necessary? This would come at the expense of additonal compelxity
A: Start with the simple case where additional memory can be allocated for the
new list and then tackle the more complex case.

Q: Is the expectation that the output list is also in reverse order?
A: Yes.
*/

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{
///////////////////////////////////////////////////////////////////////////
// \details Struct to be used when operating on the list, this was supplied
// as part of the problem.
///////////////////////////////////////////////////////////////////////////
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class AddTwoNumbers
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    AddTwoNumbers(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] l1 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \param [in] l2 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \return ListNode* - A pointer to the start of a linked list where each
    // node represents a digit in a number where the value that the pointer is
    // pointing to is the least significant digit in the number
    ///////////////////////////////////////////////////////////////////////////
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // AddTwoNumbers algorithm. It just iterates over the nodes summing them
    // until it runs out of data in one of the lists. At that point it swaps
    // over to the other list and continues adding digits. This algorithm
    // allocates a new node for each node that is necessary
    // \param [in] l1 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \param [in] l2 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \return ListNode* - A pointer to the start of a linked list where each
    // node represents a digit in a number where the value that the pointer is
    // pointing to is the least significant digit in the number
    ///////////////////////////////////////////////////////////////////////////
    ListNode* bruteForce(ListNode* l1, ListNode* l2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm to reduce the space complexity to O(1)
    // \param [in] l1 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \param [in] l2 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \return ListNode* - A pointer to the start of a linked list where each
    // node represents a digit in a number where the value that the pointer is
    // pointing to is the least significant digit in the number
    ///////////////////////////////////////////////////////////////////////////
    ListNode* optimizedOne(ListNode* l1, ListNode* l2);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides a cleaner version of the previous version
    // \param [in] l1 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \param [in] l2 - A pointer to the start of a list where each node
    // represents a digit in a number. The pointer passed in is the least
    // significant digit and is guaranteed to not be NULL
    // \return ListNode* - A pointer to the start of a linked list where each
    // node represents a digit in a number where the value that the pointer is
    // pointing to is the least significant digit in the number
    ///////////////////////////////////////////////////////////////////////////
    ListNode* optimizedTwo(ListNode* l1, ListNode* l2);

    // Determines which private implementation of the AddTwoNumbers algorithm is
    // called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif