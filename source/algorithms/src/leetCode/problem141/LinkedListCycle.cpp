#include "LinkedListCycle.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// LinkedListCycle::LinkedListCycle
///////////////////////////////////////////////////////////////////////////
LinkedListCycle::LinkedListCycle(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// LinkedListCycle::hasCycle()
///////////////////////////////////////////////////////////////////////////
bool LinkedListCycle::hasCycle(ListNode* head)
{
    // Initialize local variables
    bool status;

    // Execute the desired implementation of the LinkedListCycle algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(head);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(image, sr, sc, color);
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
// LinkedListCycle::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool LinkedListCycle::bruteForce(ListNode* head)
{
    bool isCycle = false;
    ListNode* fast = head;
    ListNode* slow = head;

    // Advance the pointers until either:
    // 1) The fast pointer has reached the end of the linked list
    // 2) The fast's next pointer has reached the end of the linked list
    // 3) A cycle has been detected
    while (fast != NULL && fast->next != NULL && !isCycle)
    {
        // Advance the fast pointer by two
        fast = fast->next->next;

        // Advance the slow pointer by one
        slow = slow->next;

        // If there is a loop then the fastPointer has entered a cycle and
        // caught up to the slow pointer
        if (fast == slow)
        {
            isCycle = true;
        }
    }

    return isCycle;
}

///////////////////////////////////////////////////////////////////////////
// LinkedListCycle::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// bool
// LinkedListCycle::optimizedOne(bool& image, int sr,
// int sc,
//                         int color)
// {
// }
} // namespace alg
