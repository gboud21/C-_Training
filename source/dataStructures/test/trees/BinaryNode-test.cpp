#include "BinaryNode.h"

#include <gtest/gtest.h>

namespace dats
{
// The fixture for testing class Foo.
class BinaryNodeTest : public testing::Test
{
protected:
    void SetUp()
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_F(BinaryNodeTest, Sunny_ValueConstructor)
{
    const int input = 100;
    BinaryNode<int>* nullNode = nullptr;
    BinaryNode<int> testNode(input);

    EXPECT_EQ(input, testNode.getValue());
    EXPECT_EQ(nullNode, testNode.getLeftChild());
    EXPECT_EQ(nullNode, testNode.getRightChild());
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_F(BinaryNodeTest, Sunny_FullConstructor)
{
    const int input = 100;
    BinaryNode<int> leftNode(input - 1);
    BinaryNode<int> rightNode(input + 1);

    BinaryNode<int>* expectedLeft = &leftNode;
    BinaryNode<int>* expectedRight = &rightNode;

    BinaryNode<int> testNode(input, expectedLeft, expectedRight);

    EXPECT_EQ(input, testNode.getValue());
    EXPECT_EQ(expectedLeft, testNode.getLeftChild());
    EXPECT_EQ(expectedRight, testNode.getRightChild());
}

////////////////////////////////////////////////////////////////////////////////
// Description: Simple Test to proof out base functionality of the algorithm
////////////////////////////////////////////////////////////////////////////////
TEST_F(BinaryNodeTest, Sunny_Setters)
{
    const int input = 1000;
    BinaryNode<int>* nullNode = nullptr;
    BinaryNode<int> testNode(0);

    BinaryNode<int> leftNode(input - 1);
    BinaryNode<int> rightNode(input + 1);

    BinaryNode<int>* expectedLeft = &leftNode;
    BinaryNode<int>* expectedRight = &rightNode;

    testNode.setValue(input);
    testNode.setLeftChild(expectedLeft);
    testNode.setRightChild(expectedRight);

    EXPECT_EQ(input, testNode.getValue());
    EXPECT_EQ(expectedLeft, testNode.getLeftChild());
    EXPECT_EQ(expectedRight, testNode.getRightChild());
}
} // namespace dats
