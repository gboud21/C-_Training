#include <cmath>
#include <limits.h>

#include "ValidParentheses.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class ValidParenthesesTest : public testing::TestWithParam<alg::FunctionVersion>
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
TEST_P(ValidParenthesesTest, Sunny_Minimal)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "aa";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_FALSE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Rainy_OddCharCount)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "(";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_FALSE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Sunny_SimplyParen)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "()";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_TRUE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Sunny_SimplyCurly)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "{}";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_TRUE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Sunny_SimplySquare)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "[]";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_TRUE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Sunny_Combo)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "({[]})";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_TRUE(testAlg.isValid(input));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(ValidParenthesesTest, Rainy_Combo)
{
    // Initialize test data
    const bool expected = false;
    std::string input = "({[)})";
    std::string input2 = "({[]))";
    std::string input3 = "({[]}]";

    // Initialize the class to run the brute force method
    ValidParentheses testAlg(m_version);

    // Run the algorithm and verify the output
    EXPECT_FALSE(testAlg.isValid(input));
    EXPECT_FALSE(testAlg.isValid(input2));
    EXPECT_FALSE(testAlg.isValid(input3));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, ValidParenthesesTest,
                         testing::Values(alg::BRUTE_FORCE /*,
                                         alg::OPTIMIZATION_ONE,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
