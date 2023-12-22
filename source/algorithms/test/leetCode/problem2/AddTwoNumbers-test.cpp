#include "AddTwoNumbers.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class AddTwoNumbersTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

///////////////////////////////////////////////////////////////////////////
// Description: This function builds a linked list of nodes
///////////////////////////////////////////////////////////////////////////
void buildList(std::vector<int>& reverseDigitVector, ListNode*& listStart)
{
    ListNode* currentNode = new ListNode(reverseDigitVector[0]);
    listStart = currentNode;

    // Build List
    for (size_t index = 1; index < reverseDigitVector.size(); index++)
    {
        currentNode->next = new ListNode(reverseDigitVector[index]);
        currentNode = currentNode->next;
    }
}

///////////////////////////////////////////////////////////////////////////
// Description: Compares the ouput vector to the expected resulting vector
// and returns TRUE if the two are equal and FALSE otherwise
///////////////////////////////////////////////////////////////////////////
bool compareOutput(const ListNode* test, const ListNode* expected)
{
    bool compareOutput = true;
    compareOutput = compareOutput && (test != nullptr && expected != nullptr);
    EXPECT_TRUE(compareOutput);

    if (compareOutput)
    {
        while (test != nullptr && expected != nullptr)
        {
            compareOutput = compareOutput && (test->val == expected->val);
            EXPECT_TRUE(compareOutput);

            test = test->next;
            expected = expected->next;
        }

        // Check if the test node contains more digits than the expected
        // node
        compareOutput = compareOutput && (expected == nullptr);
        EXPECT_TRUE(expected == nullptr);

        // Check if the test node contains less digits than the expected
        // node
        compareOutput = compareOutput && (test == nullptr);
        EXPECT_TRUE(test == nullptr);
    }

    return compareOutput;
}

///////////////////////////////////////////////////////////////////////////
//
//                              BRUTE_FORCE
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, BruteForce_Sunny_Minimal)
{
    // Initialize test data
    // Input Number 1 = 11
    std::vector<int> inputVec1 = {1, 1};
    // Input Number 2 = 11
    std::vector<int> inputVec2 = {1, 1};
    // Expected Number = 22
    std::vector<int> expectedVec = {2, 2};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, BruteForce_Sunny_Carry)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {1, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {1, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {2, 8, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the algorithm works for the
// maximum Linked List length of 100.
// NOTE***THIS TEST IS PURPOSEFULLY COMMENTED OUT BECAUSE IT BREAKS THE
// BRUTE FORCE ALGORITHM
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, BruteForce_Sunny_MaxValuesBoundary)
{
    // Initialize test data
    // Input Number 1 = 91
    const size_t maxListLength = 100;
    const int ONE = 1;
    const int TWO = 2;
    std::vector<int> inputVec1;
    // Input Number 2 = 91
    std::vector<int> inputVec2;
    // Expected Number = 182
    std::vector<int> expectedVec;
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    for (size_t index = 0; index < maxListLength; index++)
    {
        inputVec1.push_back(ONE);
        inputVec2.push_back(ONE);
        expectedVec.push_back(TWO);
    }

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_ONE
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_ONE_Sunny_Minimal)
{
    // Initialize test data
    // Input Number 1 = 11
    std::vector<int> inputVec1 = {1, 1};
    // Input Number 2 = 11
    std::vector<int> inputVec2 = {1, 1};
    // Expected Number = 22
    std::vector<int> expectedVec = {2, 2};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_ONE_Sunny_Carry)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {1, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {1, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {2, 8, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the algorithm works for the
// maximum Linked List length of 100.
// NOTE***THIS TEST IS PURPOSEFULLY COMMENTED OUT BECAUSE IT BREAKS THE
// BRUTE FORCE ALGORITHM
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_ONE_Sunny_MaxValuesBoundary)
{
    // Initialize test data
    // Input Number 1 = 91
    const size_t maxListLength = 100;
    const int ONE = 1;
    const int TWO = 2;
    std::vector<int> inputVec1;
    // Input Number 2 = 91
    std::vector<int> inputVec2;
    // Expected Number = 182
    std::vector<int> expectedVec;
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    for (size_t index = 0; index < maxListLength; index++)
    {
        inputVec1.push_back(ONE);
        inputVec2.push_back(ONE);
        expectedVec.push_back(TWO);
    }

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_ONE_Sunny_CarryDiffLengths)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {9, 9, 9, 9, 9, 9, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {9, 9, 9, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {8, 9, 9, 9, 0, 0, 0, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_TWO
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_TWO_Sunny_Minimal)
{
    // Initialize test data
    // Input Number 1 = 11
    std::vector<int> inputVec1 = {1, 1};
    // Input Number 2 = 11
    std::vector<int> inputVec2 = {1, 1};
    // Expected Number = 22
    std::vector<int> expectedVec = {2, 2};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_TWO_Sunny_Carry)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {1, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {1, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {2, 8, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the algorithm works for the
// maximum Linked List length of 100.
// NOTE***THIS TEST IS PURPOSEFULLY COMMENTED OUT BECAUSE IT BREAKS THE
// BRUTE FORCE ALGORITHM
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_TWO_Sunny_MaxValuesBoundary)
{
    // Initialize test data
    // Input Number 1 = 91
    const size_t maxListLength = 100;
    const int ONE = 1;
    const int TWO = 2;
    std::vector<int> inputVec1;
    // Input Number 2 = 91
    std::vector<int> inputVec2;
    // Expected Number = 182
    std::vector<int> expectedVec;
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    for (size_t index = 0; index < maxListLength; index++)
    {
        inputVec1.push_back(ONE);
        inputVec2.push_back(ONE);
        expectedVec.push_back(TWO);
    }

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_TWO_Sunny_CarryDiffLengths)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {9, 9, 9, 9, 9, 9, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {9, 9, 9, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {8, 9, 9, 9, 0, 0, 0, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out that the "carry the one" operation
// works
///////////////////////////////////////////////////////////////////////////
TEST_F(AddTwoNumbersTest, OPTIMIZATION_TWO_Sunny_CarryDiffLengthsReverse)
{
    // Initialize test data
    // Input Number 1 = 91
    std::vector<int> inputVec1 = {9, 9, 9, 9};
    // Input Number 2 = 91
    std::vector<int> inputVec2 = {9, 9, 9, 9, 9, 9, 9};
    // Expected Number = 182
    std::vector<int> expectedVec = {8, 9, 9, 9, 0, 0, 0, 1};
    ListNode* listStart1 = nullptr;
    ListNode* listStart2 = nullptr;
    ListNode* expectedStart = nullptr;
    ListNode* outputStart = nullptr;

    // Build List 1
    buildList(inputVec1, listStart1);

    // Build List 2
    buildList(inputVec2, listStart2);

    // Build Expected List
    buildList(expectedVec, expectedStart);

    // Initialize the class to run the brute force method
    AddTwoNumbers testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    outputStart = testSum.addTwoNumbers(listStart1, listStart2);
    EXPECT_TRUE(compareOutput(outputStart, expectedStart));
}
///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_THREE
//
///////////////////////////////////////////////////////////////////////////

} // namespace alg
