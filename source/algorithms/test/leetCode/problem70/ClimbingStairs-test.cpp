#include "ClimbingStairs.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class ClimbingStairsTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(ClimbingStairsTest, Sunny_Minimal)
{
    // Initialize the class to run the brute force method
    ClimbingStairs testAlg(m_version);
    const int output[6] = {0, 1, 2, 3, 5, 8};

    for (uint32_t index = 0; index < 6; index++)
    {
        EXPECT_EQ(output[index], testAlg.climbingStairs(index));
    }
}

INSTANTIATE_TEST_SUITE_P(PerInstance, ClimbingStairsTest,
                         testing::Values(alg::BRUTE_FORCE/*,
                                         alg::OPTIMIZATION_ONE,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
