#include "ImplementQueueUsingStack.h"

#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ImplementQueueUsingStack::ImplementQueueUsingStack
///////////////////////////////////////////////////////////////////////////
ImplementQueueUsingStack::ImplementQueueUsingStack() {}

///////////////////////////////////////////////////////////////////////////
// ImplementQueueUsingStack::push()
///////////////////////////////////////////////////////////////////////////
void ImplementQueueUsingStack::push(int x)
{
    // Stacks push onto the top and then remove from the top
    // Need to reverse the stacks so that we can remove the first thing pushed
    // in

    // Will push into stack1
    m_stack1.push(x);
}

///////////////////////////////////////////////////////////////////////////
// ImplementQueueUsingStack::push()
///////////////////////////////////////////////////////////////////////////
int ImplementQueueUsingStack::pop()
{
    // All pops will occur from stack2
    // If stack2 is empty then move all of stack 1 into stack 2
    if (m_stack2.empty())
    {
        while (!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
    }

    // Remove the top of stack 2 and return it
    int value = m_stack2.top();
    m_stack2.pop();
    return value;
}

///////////////////////////////////////////////////////////////////////////
// ImplementQueueUsingStack::push()
///////////////////////////////////////////////////////////////////////////
int ImplementQueueUsingStack::peek()
{
    // All peeks will occur from stack2
    // If stack2 is empty then move all of stack 1 into stack 2
    if (m_stack2.empty())
    {
        while (!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
    }

    // Return the top of stack 2
    return m_stack2.top();
}

///////////////////////////////////////////////////////////////////////////
// ImplementQueueUsingStack::push()
///////////////////////////////////////////////////////////////////////////
bool ImplementQueueUsingStack::empty()
{
    return m_stack1.empty() && m_stack2.empty();
}
} // namespace alg
