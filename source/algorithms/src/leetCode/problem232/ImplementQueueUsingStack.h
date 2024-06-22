#ifndef IMPLEMENTQUEUEUSINGSTACK_H
#define IMPLEMENTQUEUEUSINGSTACK_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Implement Queue Using Stack
Implement a first in first out (FIFO) queue using only two stacks. The
implemented queue should support all the functions of a normal queue (push,
peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top,
peek/pop from top, size, and is empty operations are valid. Depending on your
language, the stack may not be supported natively. You may simulate a stack
using a list or deque (double-ended queue) as long as you use only a stack's
standard operations.

Follow-up: Can you implement the queue such that each operation is amortized
O(1) time complexity? In other words, performing n operations will take overall
O(n) time even if one of those operations may take longer.

Example 1:
Input:
Output:

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
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
#include <stack>

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{
class ImplementQueueUsingStack
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    ImplementQueueUsingStack();

    ///////////////////////////////////////////////////////////////////////////
    // \details This funciton pushes an integer to the back of the queue
    // \param [in] int - The value to push into the queue
    ///////////////////////////////////////////////////////////////////////////
    void push(int x);

    ///////////////////////////////////////////////////////////////////////////
    // \details This funciton removes the item at the front of the queue and
    // returns it
    // \return int - The value to push into the queue
    ///////////////////////////////////////////////////////////////////////////
    int pop();

    ///////////////////////////////////////////////////////////////////////////
    // \details This funciton returns the item at the front of the queue without
    // removing it
    // \return int - The value to push into the queue
    ///////////////////////////////////////////////////////////////////////////
    int peek();

    ///////////////////////////////////////////////////////////////////////////
    // \details This funciton returns whether the queue contains items or not
    // \return bool - TRUE if no items are in the queue, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool empty();

private:
    std::stack<int> m_stack1;
    std::stack<int> m_stack2;
};
} // namespace alg
#endif