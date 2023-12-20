#include "TwoSum.h"

#include <gtest/gtest.h>

namespace alg
{
// The fixture for testing class Foo.
class TwoSumTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

///////////////////////////////////////////////////////////////////////////
// Description: Compares the ouput vector to the expected resulting vector
// and returns TRUE if the two are equal and FALSE otherwise
///////////////////////////////////////////////////////////////////////////
bool compareOutput(const std::vector<int> test, const std::vector<int> expected)
{
    bool compareOutput = true;
    compareOutput = compareOutput && (test.size() == expected.size());
    EXPECT_EQ(test.size(), expected.size());

    if (compareOutput)
    {
        compareOutput =
            compareOutput && (test[0] == expected[0] || test[0] == expected[1]);
        EXPECT_TRUE(compareOutput);

        compareOutput =
            compareOutput && (test[1] == expected[1] || test[1] == expected[0]);
        EXPECT_TRUE(compareOutput);
    }

    return compareOutput;
}

///////////////////////////////////////////////////////////////////////////
//
//                              BRUTE_FORCE
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny_Minimal)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm correctly identifies the two indicies
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50, 100};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm still works when the higest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny_PositiveValueBoundary)
{
    // Initialize test data
    const int inputTarget = 109;
    std::vector<int> inputVec = {109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm still works when the lowest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny_NegativeValueBoundary)
{
    // Initialize test data
    const int inputTarget = -109;
    std::vector<int> inputVec = {-109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny_MaxLengthBoundary)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 50;
    inputVec[index2] = 50;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, BruteForce_Sunny_MixedSigns)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 109;
    inputVec[index2] = -9;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::BRUTE_FORCE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_ONE
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny_Minimal)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm correctly identifies the two indicies
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50, 100};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the higest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny_PositiveValueBoundary)
{
    // Initialize test data
    const int inputTarget = 109;
    std::vector<int> inputVec = {109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the lowest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny_NegativeValueBoundary)
{
    // Initialize test data
    const int inputTarget = -109;
    std::vector<int> inputVec = {-109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny_MaxLengthBoundary)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 50;
    inputVec[index2] = 50;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationOne_Sunny_MixedSigns)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 109;
    inputVec[index2] = -9;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_ONE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_TWO
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny_Minimal)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm correctly identifies the two indicies
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50, 100};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the higest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny_PositiveValueBoundary)
{
    // Initialize test data
    const int inputTarget = 109;
    std::vector<int> inputVec = {109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the lowest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny_NegativeValueBoundary)
{
    // Initialize test data
    const int inputTarget = -109;
    std::vector<int> inputVec = {-109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny_MaxLengthBoundary)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 50;
    inputVec[index2] = 50;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationTwo_Sunny_MixedSigns)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 109;
    inputVec[index2] = -9;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_TWO);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
//
//                            OPTIMIZATION_THREE
//
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny_Minimal)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm correctly identifies the two indicies
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny)
{
    // Initialize test data
    const int inputTarget = 100;
    std::vector<int> inputVec = {50, 50, 100};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 1};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the higest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny_PositiveValueBoundary)
{
    // Initialize test data
    const int inputTarget = 109;
    std::vector<int> inputVec = {109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the lowest possible value and target are used
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny_NegativeValueBoundary)
{
    // Initialize test data
    const int inputTarget = -109;
    std::vector<int> inputVec = {-109, 49, 0};

    // Initialize result data
    const std::vector<int> expectedResult = {0, 2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using an optimized algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny_MaxLengthBoundary)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 50;
    inputVec[index2] = 50;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Case using the brute force algorithm that verifies
// algorithm still works when the array is at the maximum size
///////////////////////////////////////////////////////////////////////////
TEST_F(TwoSumTest, OptimizationThree_Sunny_MixedSigns)
{
    // Initialize test data
    const int inputTarget = 100;
    const size_t maxVectorSize = 104;
    const size_t index1 = 20;
    const size_t index2 = 89;
    std::vector<int> inputVec;
    inputVec.resize(maxVectorSize);
    inputVec[index1] = 109;
    inputVec[index2] = -9;

    // Initialize result data
    const std::vector<int> expectedResult = {index1, index2};

    // Initialize the class to run the brute force method
    TwoSum testSum(alg::OPTIMIZATION_THREE);

    // Run the algorithm and verify the output
    std::vector<int> outputVector = testSum.twoSum(inputVec, inputTarget);
    EXPECT_TRUE(compareOutput(outputVector, expectedResult));
}
} // namespace alg
