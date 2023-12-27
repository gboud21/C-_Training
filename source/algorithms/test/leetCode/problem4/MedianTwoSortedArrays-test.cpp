#include <cmath>
#include <float.h>

#include "MedianTwoSortedArrays.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class MedianTwoSortedArraysTest
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
bool compareOutput(const double test, const double expected)
{
    bool compareOutput = (test == expected);
    EXPECT_EQ(test, expected);
    return compareOutput;
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_Minimal_Input1)
{
    // Initialize test data
    double output = DBL_MAX;
    std::vector<int> input1 = {1, 2, 3, 4};
    std::vector<int> input2 = {5, 6, 7};
    const double expected = 4;

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_Minimal_Input2)
{
    // Initialize test data
    double output = DBL_MAX;
    std::vector<int> input1 = {1, 2, 3};
    std::vector<int> input2 = {4, 5, 6, 7};
    const double expected = 4;

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates the algorithm correctly averages the median when
// (m + n) % 2 == 0
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_EvenLength)
{
    // Initialize test data
    double output = DBL_MAX;
    std::vector<int> input1 = {1, 2, 3};
    std::vector<int> input2 = {4, 5, 6};
    const double expected = 3.5; // "abcdefg"

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates the algorithm works when the second input is empty.
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_EmptyInput1)
{
    // Initialize test data
    double output = DBL_MAX;
    std::vector<int> input1;
    std::vector<int> input2 = {-1, 0, 1};
    const double expected = 0; // "abcdefg"

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates the algorithm works when the second input is empty.
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_EmptyInput2)
{
    // Initialize test data
    double output = DBL_MAX;
    std::vector<int> input1 = {-1, 0, 1};
    std::vector<int> input2;
    const double expected = 0; // "abcdefg"

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

////////////////////////////////////////////////////////////////////////////////
// Description: Validates the algorithm works when the second input is empty.
////////////////////////////////////////////////////////////////////////////////
TEST_P(MedianTwoSortedArraysTest, Sunny_BoundaryMaxNumValues)
{
    // Initialize test data
    double output = DBL_MAX;
    const size_t maxNumValues = 1000;
    std::vector<int> input1;
    std::vector<int> input2;
    const double expected = 999.5; // "abcdefg"

    // Insert the maximum number of values into the input arrays
    // input1 = {0, ... 999}
    // input2 = {1000, ... 1999}
    for (size_t index = 0; index < maxNumValues; index++)
    {
        input1.push_back(index);
        input2.push_back(index + maxNumValues);
    }

    // Initialize the class to run the brute force method
    MedianTwoSortedArrays testAlg(m_version);

    // Run the algorithm and verify the output
    output = testAlg.findMedianSortedArrays(input1, input2);
    EXPECT_TRUE(compareOutput(output, expected));
}

INSTANTIATE_TEST_SUITE_P(PerInstance, MedianTwoSortedArraysTest,
                         testing::Values(alg::BRUTE_FORCE,
                                         alg::OPTIMIZATION_ONE /*,
                                         alg::OPTIMIZATION_TWO*/));
} // namespace alg
