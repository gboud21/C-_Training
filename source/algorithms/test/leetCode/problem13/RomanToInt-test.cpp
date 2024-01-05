#include <cmath>
#include <limits.h>

#include "RomanToInt.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class RomanToIntTest : public testing::TestWithParam<alg::FunctionVersion>
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
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_Minimal)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "II";
    const int expected = 2;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies an I is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_I_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "III";
    const int expected = 3;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies an I is subtracted when preceding a V or X
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_I_Subtract)
{
    // Initialize test data
    int output = INT_MAX;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a V
    std::string input1 = "IV";
    int expected = 4;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a X
    input1 = "IX";
    expected = 9;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a V is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_V_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "V";
    const int expected = 5;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies an X is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_X_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "XXX";
    const int expected = 30;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a X is subtracted when preceding a L or C
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_X_Subtract)
{
    // Initialize test data
    int output = INT_MAX;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a V
    std::string input1 = "XL";
    int expected = 40;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a X
    input1 = "XC";
    expected = 90;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a L is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_L_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "L";
    const int expected = 50;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies an C is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_C_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "CCC";
    const int expected = 300;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a C is subtracted when preceding a D or M
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_C_Subtract)
{
    // Initialize test data
    int output = INT_MAX;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a D
    std::string input1 = "CD";
    int expected = 400;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));

    ////////////////////////////////////////////////////////////////////////////
    // Tests before a M
    input1 = "CM";
    expected = 900;

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a D is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_D_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "D";
    const int expected = 500;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Verifies a M is added to the maximum amount
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_M_Add)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "MMM";
    const int expected = 3000;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Tests the Maximum number
////////////////////////////////////////////////////////////////////////////////
TEST_P(RomanToIntTest, Sunny_MaxNumber)
{
    // Initialize test data
    int output = INT_MAX;
    std::string input1 = "MMMCMXCIX";
    const int expected = 3999;

    // Initialize the class to run the brute force method
    RomanToInt testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.romanToInt(input1);
    EXPECT_TRUE(compareOutput(output, expected));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, RomanToIntTest,
                         testing::Values(alg::BRUTE_FORCE,
                                         alg::OPTIMIZATION_ONE/*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
