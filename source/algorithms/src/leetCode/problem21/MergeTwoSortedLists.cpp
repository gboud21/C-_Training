#include "MergeTwoSortedLists.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// MergeTwoSortedLists::MergeTwoSortedLists
///////////////////////////////////////////////////////////////////////////
MergeTwoSortedLists::MergeTwoSortedLists(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// MergeTwoSortedLists::mergeTwoLists()
///////////////////////////////////////////////////////////////////////////
ListNode* MergeTwoSortedLists::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    // Initialize local variables
    ListNode* failedStatus = NULL;

    // Execute the desired implementation of the MergeTwoSortedLists algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(l1, l2);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(l1, l2);
            break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(l1, l2);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// MergeTwoSortedLists::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
ListNode* MergeTwoSortedLists::bruteForce(ListNode* l1, ListNode* l2)
{
    // Initialize local variable
    ListNode* initialNode = NULL;
    ListNode* currentNode = NULL;

    // Check boundary conditions and initial conditions
    // If both are null then just return null
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    // Otherwise if l1 is NULL then just return l2
    else if (l1 == NULL)
    {
        return l2;
    }
    // Otherwise if l2 is NULL then just return l1
    else if (l2 == NULL)
    {
        return l1;
    }
    // Otherwise if l1 is less than l2 then set the initial to l1
    else if (l1->val < l2->val)
    {
        initialNode = new ListNode(l1->val);
        l1 = l1->next;
    }
    // Otherwise assign l2 to the start node
    else
    {
        initialNode = new ListNode(l2->val);
        l2 = l2->next;
    }

    currentNode = initialNode;

    // Loop over the linked lists until the end of one of the lists has been
    // reached
    while (l1 != NULL && l2 != NULL)
    {
        // Compare l1 and l2 and then
        // 1) Assign the lesser to the next node in the list
        // 2) Advance the pointer for the one that was assigned
        if (l1->val < l2->val)
        {
            currentNode->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            currentNode->next = new ListNode(l2->val);
            l2 = l2->next;
        }

        currentNode = currentNode->next;
    }

    // If there are still more elements in l1 then add the next node in l1 to
    // the end of the list
    if (l1 != NULL)
    {
        currentNode->next = l1;
    }
    // Otherwise if there are still more elements in l2 then add the next node
    // in l2 to the end of the list
    else if (l2 != NULL)
    {
        currentNode->next = l2;
    }

    return initialNode;
}

///////////////////////////////////////////////////////////////////////////
// MergeTwoSortedLists::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
ListNode* MergeTwoSortedLists::optimizedOne(ListNode* l1, ListNode* l2)
{
    // Initialize local variable
    ListNode* initialNode = NULL;
    ListNode* currentNode = NULL;

    // Check boundary conditions and initial conditions
    // If both are null then just return null
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    // Otherwise if l1 is NULL then just return l2
    else if (l1 == NULL)
    {
        return l2;
    }
    // Otherwise if l2 is NULL then just return l1
    else if (l2 == NULL)
    {
        return l1;
    }
    // Otherwise if l1 is less than l2 then set the initial to l1
    else if (l1->val < l2->val)
    {
        initialNode = l1;
        l1 = l1->next;
    }
    // Otherwise assign l2 to the start node
    else
    {
        initialNode = l2;
        l2 = l2->next;
    }

    currentNode = initialNode;

    // Loop over the linked lists until the end of one of the lists has been
    // reached
    while (l1 != NULL && l2 != NULL)
    {
        // Compare l1 and l2 and then
        // 1) Assign the lesser to the next node in the list
        // 2) Advance the pointer for the one that was assigned
        if (l1->val < l2->val)
        {
            currentNode->next = l1;
            l1 = l1->next;
        }
        else
        {
            currentNode->next = l2;
            l2 = l2->next;
        }

        currentNode = currentNode->next;
    }

    // If there are still more elements in l1 then add the next node in l1 to
    // the end of the list
    if (l1 != NULL)
    {
        currentNode->next = l1;
    }
    // Otherwise if there are still more elements in l2 then add the next node
    // in l2 to the end of the list
    else if (l2 != NULL)
    {
        currentNode->next = l2;
    }

    return initialNode;
}
} // namespace alg
