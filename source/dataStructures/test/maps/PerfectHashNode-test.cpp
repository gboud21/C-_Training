#include "PerfectHashNode.h"

#include <gtest/gtest.h>

class PerfectHashNodeTest : public testing::Test
{
protected:
    void SetUp() {}

    void TearDown() {}
};

// Verifies the default constructor properly initializes all values
TEST_F(PerfectHashNodeTest, DefaultConstructorTest)
{
    const uint32_t keyValue = 0;
    const uint32_t nodeValue = 0;
    PerfectHashNode<uint32_t, uint32_t> node;

    // Verify the node is set to free
    EXPECT_TRUE(node.isFree());

    // Verify the key is initialize to 0
    EXPECT_EQ(node.getKey(), keyValue);
    EXPECT_EQ(node.getValue(), nodeValue);
}

// Verify the key is set properly
TEST_F(PerfectHashNodeTest, SetDataTest)
{
    const uint32_t keyValue = 100;
    const uint32_t nodeValue = 200;
    PerfectHashNode<uint32_t, uint32_t> node;
    node.setKey(keyValue);
    node.setValue(nodeValue);

    // Verify the key is initialize to (100,200)
    EXPECT_EQ(node.getKey(), keyValue);
    EXPECT_EQ(node.getValue(), nodeValue);
}
