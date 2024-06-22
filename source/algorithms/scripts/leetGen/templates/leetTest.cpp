#include "LEET_OBJ.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class LEET_OBJTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(LEET_OBJTest, Sunny_Minimal)
{
    // Initialize the class to run the brute force method
    LEET_OBJ testAlg(m_version);
}

INSTANTIATE_TEST_SUITE_P(PerInstance, LEET_OBJTest,
                         testing::Values(alg::BRUTE_FORCE/*,
                                         alg::OPTIMIZATION_ONE,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
