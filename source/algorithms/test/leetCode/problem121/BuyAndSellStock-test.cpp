#include <cmath>
#include <limits.h>

#include "BuyAndSellStock.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class BuyAndSellStockTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(BuyAndSellStockTest, Sunny_Minimal)
{
    // Initialize the class to run the brute force method
    BuyAndSellStock testAlg(m_version);

    // Run the test with basic data set
    int expectedProfit = 0;
    std::vector<int> inputPrices = {0, 0, 0};
    EXPECT_EQ(expectedProfit, testAlg.maxProfit(inputPrices));

    int expectedProfit2 = 5;
    std::vector<int> inputPrices2 = {0, 1, 2, 3, 4, 5};
    EXPECT_EQ(expectedProfit2, testAlg.maxProfit(inputPrices2));

    int expectedProfit3 = 15;
    std::vector<int> inputPrices3 = {10, 5, 20, 3, 12};
    EXPECT_EQ(expectedProfit3, testAlg.maxProfit(inputPrices3));

    int expectedProfit4 = 0;
    std::vector<int> inputPrices4 = {10, 9, 8, 7, 6, 5};
    EXPECT_EQ(expectedProfit4, testAlg.maxProfit(inputPrices4));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, BuyAndSellStockTest,
                         testing::Values(alg::BRUTE_FORCE ,
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
