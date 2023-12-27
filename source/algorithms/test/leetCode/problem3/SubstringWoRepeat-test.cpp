#include <cmath>

#include "SubstringWoRepeat.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class SubstringWoRepeatTest
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
};

////////////////////////////////////////////////////////////////////////////////
// Description: Compares the ouput vector to the expected resulting vector
// and returns TRUE if the two are equal and FALSE otherwise
////////////////////////////////////////////////////////////////////////////////
bool compareOutput(const int test, const int expected)
{
    bool compareOutput = (test == expected);
    EXPECT_EQ(test, expected);
    return compareOutput;
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality with no repeats
////////////////////////////////////////////////////////////////////////////////
TEST_P(SubstringWoRepeatTest, Sunny_Minimal)
{
    // Initialize test data
    int output = -1;
    std::string input = "abcdefg";
    const int expected = input.length(); // "abcdefg"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates that when a character is detected it resets the count
// and correctly detects the substring at the end of the input string
////////////////////////////////////////////////////////////////////////////////
TEST_P(SubstringWoRepeatTest, Sunny_RepeatHalfWay)
{
    // Initialize test data
    int output = -1;
    std::string input = "abcabcd";
    const int expected = 4; // "abcd"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates that when a character is detected it
// resets the count. This should detect the character string at the front of the
// string
////////////////////////////////////////////////////////////////////////////////
TEST_P(SubstringWoRepeatTest, Sunny_RepeatHalfWayReversed)
{
    // Initialize test data
    int output = -1;
    std::string input = "abcdbc";
    const int expected = 4; // "abcd"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates it finds the substring within the maximum length
// string
////////////////////////////////////////////////////////////////////////////////
TEST_P(SubstringWoRepeatTest, Sunny_MaxStringLength)
{
    // Initialize test data
    int output = -1;
    std::string input = "";
    const int expected = 4; // "abcd"

    // Build the max length string
    for (size_t index = 0; index < 5 * pow(10, 4); index++)
    {
        input += 'a';
    }

    input[100] = 'b';
    input[101] = 'c';
    input[102] = 'd';

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

TEST_P(SubstringWoRepeatTest, Sunny_BackToBackDup)
{
    // Initialize test data
    int output = -1;
    std::string input = "jbpnbwwd";
    const int expected = 4; // "jbpn"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

TEST_P(SubstringWoRepeatTest, Sunny_MultipleDups)
{
    // Initialize test data
    int output = -1;
    std::string input = "kdgjkjhglfp";
    const int expected = 7; // "abcd"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

TEST_P(SubstringWoRepeatTest, Sunny_Extra)
{
    // Initialize test data
    int output = -1;
    std::string input = "aabaab!bb";
    const int expected = 3; // "abcd"

    // Initialize the class to run the brute force method
    SubstringWoRepeat testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.substringWoRepeat(input);
    EXPECT_TRUE(compareOutput(output, expected));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, SubstringWoRepeatTest,
                         testing::Values(alg::BRUTE_FORCE,
                                         alg::OPTIMIZATION_ONE,
                                         alg::OPTIMIZATION_TWO));
} // namespace alg
