#include "LongestPalindromicSubstring.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class LongestPalindromicSubstringTest
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
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_Minimal_Input1)
{
    // Initialize test data
    std::string output;
    std::string input = "abbac";
    std::string expected = "abba";
    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_SingleChar_Palindrome)
{
    // Initialize test data
    std::string output;
    std::string input = "a";
    std::string expected = "a";
    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_FullString_Palindrome)
{
    // Initialize test data
    std::string output;
    std::string input = "abba";
    std::string expected = "abba";
    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_MaxLength_Palindrome)
{
    // Initialize test data
    std::string output;
    std::string input = "";
    std::string palindrome = "1234567890987654321";
    std::string expected = "1234567890987654321";
    const uint32_t MAX_LENGTH = 1000;
    char nextChar = 'A';

    for (uint32_t index = 0; index < MAX_LENGTH; index++)
    {
        input += nextChar;

        if (nextChar == 'Z')
        {
            nextChar = 'A';
        }
        else
        {
            nextChar++;
        }
    }

    for (uint32_t index = 0; index < palindrome.length(); index++)
    {
        input[333 + index] = palindrome[index];
    }

    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_OddPalindrome)
{
    // Initialize test data
    std::string output;
    std::string input = "babad";
    std::string expected = "bab";
    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(LongestPalindromicSubstringTest, Sunny_EvenPalindrome)
{
    // Initialize test data
    std::string output;
    std::string input = "cbbd";
    std::string expected = "bb";
    LongestPalindromicSubstring testAlgorithm(m_version);

    output = testAlgorithm.longestPalindrome(input);
    EXPECT_EQ(output, expected);
}

INSTANTIATE_TEST_SUITE_P(PerInstance, LongestPalindromicSubstringTest,
                         testing::Values(/*alg::BRUTE_FORCE,*/
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
