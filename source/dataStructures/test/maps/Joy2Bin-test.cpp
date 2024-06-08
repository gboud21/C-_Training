#include "Joy2Bin.h"

#include <gtest/gtest.h>

TEST(Joy2BinTest, ConstructorTest)
{
    Joy2Bin bin;
    ASSERT_EQ(bin.isFree(), true);
    ASSERT_EQ(bin.getKey(), 0);
}

TEST(Joy2BinTest, SetKeyTest)
{
    const uint32_t key = 100;
    Joy2Bin bin;

    bin.setKey(key);
    ASSERT_EQ(bin.isFree(), false);
    ASSERT_EQ(bin.getKey(), key);
}

TEST(Joy2BinTest, FreeKeyTest)
{
    const uint32_t key = 100;
    Joy2Bin bin;

    bin.setKey(key);
    ASSERT_EQ(bin.isFree(), false);
    ASSERT_EQ(bin.getKey(), key);

    bin.free();
    ASSERT_EQ(bin.isFree(), true);
}