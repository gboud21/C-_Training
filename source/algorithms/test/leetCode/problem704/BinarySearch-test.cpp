#include "BinarySearch.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class BinarySearchTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(BinarySearchTest, Sunny_Minimal)
{
    // Initialize test variables
    const int target = 40;
    std::vector<int> input = {0, 10, 20, 30, 40, 50};
    const int expectedOutput = 4;

    // Initialize the class to run the brute force method
    BinarySearch testAlg(m_version);
    EXPECT_EQ(expectedOutput, testAlg.search(input, target));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(BinarySearchTest, Sunny_TwoItems)
{
    // Initialize test variables
    const int target = 0;
    std::vector<int> input = {0, 10};
    const int expectedOutput = 0;

    const int target2 = 10;
    const int expectedOutput2 = 1;

    // Initialize the class to run the brute force method
    BinarySearch testAlg(m_version);
    EXPECT_EQ(expectedOutput, testAlg.search(input, target));
    EXPECT_EQ(expectedOutput2, testAlg.search(input, target2));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(BinarySearchTest, Rainy_Minimal)
{
    // Initialize test variables
    const int target = 100;
    std::vector<int> input = {0, 10, 20, 30, 40, 50};
    const int expectedOutput = -1;

    // Initialize the class to run the brute force method
    BinarySearch testAlg(m_version);
    EXPECT_EQ(expectedOutput, testAlg.search(input, target));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, BinarySearchTest,
                         testing::Values(alg::BRUTE_FORCE,
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
