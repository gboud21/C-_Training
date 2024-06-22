#include <cmath>
#include <limits.h>

#include "LinkedListCycle.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class LinkedListCycleTest : public testing::TestWithParam<alg::FunctionVersion>
{
protected:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
        m_version = GetParam();
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    alg::FunctionVersion m_version;
};

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LinkedListCycleTest, Sunny_Minimal)
{
    // Initialize the class to run the brute force method
    LinkedListCycle testAlg(m_version);

    ListNode* head = new ListNode(-1);
    ListNode* node = new ListNode(0);
    head->next = node;

    for (uint32_t index = 1; index < 10; index++)
    {
        node->next = new ListNode(index);
        node = node->next;
    }

    EXPECT_FALSE(testAlg.hasCycle(head));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LinkedListCycleTest, Rainy_Minimal)
{
    // Initialize the class to run the brute force method
    LinkedListCycle testAlg(m_version);

    ListNode* cycleNode = NULL;
    ListNode* head = new ListNode(-1);
    ListNode* node = new ListNode(0);
    head->next = node;

    for (uint32_t index = 1; index < 10; index++)
    {
        node->next = new ListNode(index);

        if (index < 9)
        {
            node = node->next;
        }

        if (index == 5)
        {
            cycleNode = node;
        }
    }

    node->next = cycleNode;

    EXPECT_TRUE(testAlg.hasCycle(head));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, LinkedListCycleTest,
                         testing::Values(alg::BRUTE_FORCE/*,
                                         alg::OPTIMIZATION_ONE,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
