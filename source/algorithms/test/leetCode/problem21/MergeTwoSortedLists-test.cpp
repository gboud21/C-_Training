#include <cmath>
#include <limits.h>

#include "MergeTwoSortedLists.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class MergeTwoSortedListsTest
    : public testing::TestWithParam<alg::FunctionVersion>
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
    ListNode* nullListNode = NULL;
    const uint32_t MAX_LIST_SIZE = 50;
};

////////////////////////////////////////////////////////////////////////////////
// Description: Compares the ouput vector to the expected resulting vector
// and returns TRUE if the two are equal and FALSE otherwise
////////////////////////////////////////////////////////////////////////////////
bool compareOutput(const ListNode* test, const ListNode* expected)
{
    bool compareOutput;

    if (expected == NULL)
    {
        compareOutput = (test == NULL);
        EXPECT_TRUE(compareOutput);
    }
    else
    {
        compareOutput = (test != NULL);
        EXPECT_TRUE(compareOutput);

        if (compareOutput)
        {
            while (test != NULL && expected != NULL)
            {
                compareOutput = compareOutput && (test->val == expected->val);
                EXPECT_EQ(test->val, expected->val);
                test = test->next;
                expected = expected->next;
            }
        }
    }

    return compareOutput;
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_Minimal)
{
    // Initialize test data
    ListNode* output = NULL;
    const ListNode* const expected = NULL;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verify algorithm handles a null L1
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_List1_NULL)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = NULL;
    ListNode* l2 = new ListNode(0);
    const ListNode* const expected = l2;

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verify algorithm handles a null L2
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_List2_NULL)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = NULL;
    const ListNode* const expected = l1;

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_List1_AllElementsFirst)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = new ListNode(0);
    ListNode* currentL1 = l1;
    ListNode* l2 = new ListNode(MAX_LIST_SIZE);
    ListNode* currentL2 = l2;
    ListNode* expected = new ListNode(0);
    ListNode* currentExpected = expected;

    // Build the lists and the first half of the expected list
    for (uint32_t index = 1; index < MAX_LIST_SIZE; index++)
    {
        currentL1->next = new ListNode(index);
        currentL1 = currentL1->next;
        currentL2->next = new ListNode(MAX_LIST_SIZE + index);
        currentL2 = currentL2->next;
        currentExpected->next = new ListNode(index);
        currentExpected = currentExpected->next;
    }

    // Build the second half of the expected list
    for (uint32_t index = 0; index < MAX_LIST_SIZE; index++)
    {
        currentExpected->next = new ListNode(MAX_LIST_SIZE + index);
        currentExpected = currentExpected->next;
    }

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_List1_AllElementsSecond)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = new ListNode(MAX_LIST_SIZE);
    ListNode* currentL1 = l1;
    ListNode* l2 = new ListNode(0);
    ListNode* currentL2 = l2;
    ListNode* expected = new ListNode(0);
    ListNode* currentExpected = expected;

    // Build the lists and the first half of the expected list
    for (uint32_t index = 1; index < MAX_LIST_SIZE; index++)
    {
        currentL1->next = new ListNode(MAX_LIST_SIZE + index);
        currentL1 = currentL1->next;
        currentL2->next = new ListNode(index);
        currentL2 = currentL2->next;
        currentExpected->next = new ListNode(index);
        currentExpected = currentExpected->next;
    }

    // Build the second half of the expected list
    for (uint32_t index = 0; index < MAX_LIST_SIZE; index++)
    {
        currentExpected->next = new ListNode(MAX_LIST_SIZE + index);
        currentExpected = currentExpected->next;
    }

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verify nodes are sorted in order when the lists are the same
// length
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_MixedOrderSameLength)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = NULL;
    ListNode* currentL1 = l1;
    ListNode* l2 = NULL;
    ListNode* currentL2 = l2;
    ListNode* expected = NULL;
    ListNode* currentExpected = expected;
    uint32_t index = 0;

    uint32_t l1Vals[5] = {10, 20, 30, 110, 120};
    uint32_t l2Vals[5] = {5, 15, 25, 70, 80};
    uint32_t expectedVals[10] = {5, 10, 15, 20, 25, 30, 70, 80, 110, 120};

    // Build the lists and the first half of the expected list
    for (index = 0; index < 5; index++)
    {
        currentL1 = new ListNode(l1Vals[index]);
        currentL2 = new ListNode(l2Vals[index]);
        currentExpected = new ListNode(expectedVals[index]);

        if (index == 0)
        {
            l1 = currentL1;
            l2 = currentL2;
            expected = currentExpected;
        }

        currentL1 = currentL1->next;
        currentL2 = currentL2->next;
        currentExpected = currentExpected->next;
    }

    // Build the second half of the expected list
    for (index; index < 10; index++)
    {
        currentExpected = new ListNode(expectedVals[index]);
        currentExpected = currentExpected->next;
    }

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verify that all remaining elements in L2 are appended to the
// linked list when L1 terminates first
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_MixedOrderShortL1)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = NULL;
    ListNode* currentL1 = l1;
    ListNode* l2 = NULL;
    ListNode* currentL2 = l2;
    ListNode* expected = NULL;
    ListNode* currentExpected = expected;
    uint32_t index = 0;

    uint32_t l1Vals[5] = {10, 20, 30, 110, 120};
    uint32_t l2Vals[8] = {5, 15, 25, 70, 80, 130, 140, 150};
    uint32_t expectedVals[13] = {5,  10,  15,  20,  25,  30, 70,
                                 80, 110, 120, 130, 140, 150};

    // Build the lists and the first half of the expected list
    for (index = 0; index < 5; index++)
    {
        currentL1 = new ListNode(l1Vals[index]);
        currentL2 = new ListNode(l2Vals[index]);
        currentExpected = new ListNode(expectedVals[index]);

        if (index == 0)
        {
            l1 = currentL1;
            l2 = currentL2;
            expected = currentExpected;
        }

        currentL1 = currentL1->next;
        currentL2 = currentL2->next;
        currentExpected = currentExpected->next;
    }

    // Build the second half of the expected list
    for (index; index < 10; index++)
    {
        currentExpected = new ListNode(expectedVals[index]);
        currentExpected = currentExpected->next;
    }

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verify that all remaining elements in L1 are appended to the
// linked list when L2 terminates first
////////////////////////////////////////////////////////////////////////////////
TEST_P(MergeTwoSortedListsTest, Sunny_MixedOrderShortL2)
{
    // Initialize test data
    ListNode* output = NULL;
    ListNode* l1 = NULL;
    ListNode* currentL1 = l1;
    ListNode* l2 = NULL;
    ListNode* currentL2 = l2;
    ListNode* expected = NULL;
    ListNode* currentExpected = expected;
    uint32_t index = 0;

    uint32_t l2Vals[5] = {10, 20, 30, 110, 120};
    uint32_t l1Vals[8] = {5, 15, 25, 70, 80, 130, 140, 150};
    uint32_t expectedVals[13] = {5,  10,  15,  20,  25,  30, 70,
                                 80, 110, 120, 130, 140, 150};

    // Build the lists and the first half of the expected list
    for (index = 0; index < 5; index++)
    {
        currentL1 = new ListNode(l1Vals[index]);
        currentL2 = new ListNode(l2Vals[index]);
        currentExpected = new ListNode(expectedVals[index]);

        if (index == 0)
        {
            l1 = currentL1;
            l2 = currentL2;
            expected = currentExpected;
        }

        currentL1 = currentL1->next;
        currentL2 = currentL2->next;
        currentExpected = currentExpected->next;
    }

    // Build the second half of the expected list
    for (index; index < 10; index++)
    {
        currentExpected = new ListNode(expectedVals[index]);
        currentExpected = currentExpected->next;
    }

    // Initialize the class to run the brute force method
    MergeTwoSortedLists testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.mergeTwoLists(l1, l2);
    EXPECT_TRUE(compareOutput(output, expected));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, MergeTwoSortedListsTest,
                         testing::Values(alg::BRUTE_FORCE ,
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
