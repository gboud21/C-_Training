#include "AddTwoNumbers.h"

#include <cmath>
#include <iostream>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// AddTwoNumbers::AddTwoNumbers
///////////////////////////////////////////////////////////////////////////
AddTwoNumbers::AddTwoNumbers(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// AddTwoNumbers::addTwoNumbers()
///////////////////////////////////////////////////////////////////////////
ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    // Initialize local variables
    ListNode* failedNode = nullptr;

    // Execute the desired implementation of the AddTwoNumbers algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(l1, l2);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(l1, l2);
            break;
        case OPTIMIZATION_TWO:
            return optimizedTwo(l1, l2);
            break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedNode;
}

///////////////////////////////////////////////////////////////////////////
// AddTwoNumbers::bruteForce(): PASSED
// Time Complexity:  O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
ListNode* AddTwoNumbers::bruteForce(ListNode* l1, ListNode* l2)
{
    // Initialize local variables
    ListNode* retNode = nullptr;
    ListNode* currentNode = nullptr;
    ListNode* remainingNode = nullptr;
    int carry = 0;
    const int TEN = 10;

    // Set the first node
    int digit = l1->val + l2->val + carry;
    if (digit >= TEN)
    {
        digit %= TEN;
        retNode = new ListNode(digit);

        if (carry > 0)
        {
            carry--;
        }

        carry++;
    }
    else
    {
        retNode = new ListNode(digit);

        if (carry > 0)
        {
            carry--;
        }
    }

    currentNode = retNode;
    l1 = l1->next;
    l2 = l2->next;

    // Loop over both nodes at the same time creating a new node for each digit
    // by summing the two nodes. Terminate the loop when one of the nodes is
    // nullptr
    while (l1 != nullptr && l2 != nullptr)
    {
        digit = l1->val + l2->val + carry;
        if (digit >= TEN)
        {
            digit %= TEN;
            currentNode->next = new ListNode(digit);

            if (carry > 0)
            {
                carry--;
            }

            carry++;
        }
        else
        {
            currentNode->next = new ListNode(digit);

            if (carry > 0)
            {
                carry--;
            }
        }

        l1 = l1->next;
        l2 = l2->next;
        currentNode = currentNode->next;
    }

    // Set the node to the node who's list did not complete
    if (l1 != nullptr)
    {
        remainingNode = l1;
    }
    else if (l2 != nullptr)
    {
        remainingNode = l2;
    }

    // Continue adding nodes to the list equal to the digit in the list that did
    // not complete
    while (remainingNode != nullptr)
    {
        digit = remainingNode->val + carry;
        if (digit >= TEN)
        {
            digit %= TEN;
            currentNode->next = new ListNode(digit);

            if (carry > 0)
            {
                carry--;
            }

            carry++;
        }
        else
        {
            currentNode->next = new ListNode(digit);

            if (carry > 0)
            {
                carry--;
            }
        }

        remainingNode = remainingNode->next;
        currentNode = currentNode->next;
    }

    if (carry > 0)
    {
        currentNode->next = new ListNode(carry);
    }

    // Return the pointer to the start of the list
    return retNode;
}

///////////////////////////////////////////////////////////////////////////
// AddTwoNumbers::optimizedOne(): PASSED
// Time Complexity:  O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
ListNode* AddTwoNumbers::optimizedOne(ListNode* l1, ListNode* l2)
{
    // Initialize local variables
    ListNode* currentNode = nullptr;
    int carry = 0;
    const int ZERO = 0;
    const int ONE = 1;
    const int TEN = 10;

    // Set the first node
    // Realistically I would make the following if/else block into a private
    // function to reduce duplicate code in the rest of the function, but I'm
    // leaving it this way to simplify working with tools
    int digit = l1->val + l2->val;
    if (digit >= TEN)
    {
        l1->val = digit % TEN;
        carry = ONE;
    }
    else
    {
        l1->val = digit % TEN;
    }

    currentNode = l1;

    // Loop over both nodes at the same time creating a new node for each digit
    // by summing the two nodes. Terminate the loop when one of the nodes is
    // nullptr
    while (currentNode->next != nullptr && l2->next != nullptr)
    {
        digit = currentNode->next->val + l2->next->val + carry;
        if (digit >= TEN)
        {
            currentNode->next->val = digit % TEN;
            carry = ONE;
        }
        else
        {
            currentNode->next->val = digit % TEN;
            carry = ZERO;
        }

        currentNode = currentNode->next;
        l2 = l2->next;
    }

    // Set the node to the node who's list did not complete
    if (currentNode->next == nullptr)
    {
        currentNode->next = l2->next;
    }

    // Continue adding nodes to the list equal to the digit in the list that did
    // not complete
    while (currentNode->next != nullptr)
    {
        digit = currentNode->next->val + carry;
        if (digit >= TEN)
        {
            currentNode->next->val = digit % TEN;
            carry = ONE;
        }
        else
        {
            currentNode->next->val = digit % TEN;
            carry = ZERO;
        }

        currentNode = currentNode->next;
    }

    if (carry > ZERO)
    {
        currentNode->next = new ListNode(carry);
    }

    // Return the pointer to the start of the list
    return l1;
}

///////////////////////////////////////////////////////////////////////////
// AddTwoNumbers::optimizedTwo(): PASSED
// Time Complexity:  O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
ListNode* AddTwoNumbers::optimizedTwo(ListNode* l1, ListNode* l2)
{
    // Initialize local variables
    ListNode* currentNode = l1;
    ListNode* previousNode = nullptr;
    int carry = 0;
    const int TEN = 10;

    // Collapse the whole function down into a single loop.
    // This does not significantly improve code performance, but it does reduce
    // code maintenance and improve readability, though it does it at the
    // expense of having slightly more complex logic
    while (currentNode != nullptr)
    {
        // Set the digit to the value stored in currentNode
        int digit = currentNode->val;

        // If l2 is not null then add its value to the digit and advance it to
        // the next node
        if (l2 != nullptr)
        {
            digit += l2->val;
            l2 = l2->next;
        }

        // Add any "carry the one" to the digit and then calculate whether a
        // "carry the one" is required for the next iteration
        digit += carry;
        carry = digit / TEN;

        // Set the value of the current digit
        currentNode->val = digit % TEN;
        previousNode = currentNode;

        // If the next node in the sequence is NULL then flip to the other list
        // and continue processing
        if (currentNode->next == nullptr && l2 != nullptr)
        {
            currentNode = l2;
            previousNode->next = currentNode;
            l2 = nullptr;
        }
        else
        {
            // Otherwise just advance it to the next node, this will eventually
            // terminate the loop
            currentNode = currentNode->next;
        }
    }

    // If there is a "carry by one" remaining then add a node to the end of the
    // list for it
    if (carry > 0)
    {
        previousNode->next = new ListNode(carry);
    }

    return l1;
}
} // namespace alg
