#include <cmath>
#include <limits.h>

#include "ValidPalindrome.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class ValidPalindromeTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(ValidPalindromeTest, Sunny_Minimal)
{
    // Initialize the class to run the brute force method
    ValidPalindrome testAlg(m_version);

    // Run the test with basic data set
    std::string inputString1 = "AbcddcbA";
    EXPECT_TRUE(testAlg.isPalindrome(inputString1));

    std::string inputString2 = "Abcddcba";
    EXPECT_TRUE(testAlg.isPalindrome(inputString2));

    std::string inputString3 = "A11A";
    EXPECT_TRUE(testAlg.isPalindrome(inputString3));

    std::string inputString4 = "aba";
    EXPECT_TRUE(testAlg.isPalindrome(inputString4));

    std::string inputString5 = "a b c c b a";
    EXPECT_TRUE(testAlg.isPalindrome(inputString5));

    std::string inputString6 = "abc.ba";
    EXPECT_TRUE(testAlg.isPalindrome(inputString6));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidPalindromeTest, Rainy_Minimal)
{
    // Initialize the class to run the brute force method
    ValidPalindrome testAlg(m_version);

    // Run the test with basic data set
    std::string inputString1 = "abcb";
    EXPECT_FALSE(testAlg.isPalindrome(inputString1));

    std::string inputString2 = "abcb.ba";
    EXPECT_FALSE(testAlg.isPalindrome(inputString2));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, ValidPalindromeTest,
                         testing::Values(alg::BRUTE_FORCE,
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
