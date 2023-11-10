#include "PerfectHashMap.h"

#include <gtest/gtest.h>

class PerfectHashMapTest : public testing::Test
{
protected:
    void SetUp() {}

    void TearDown() {}
};

TEST_F(PerfectHashMapTest, ConstructorTest)
{
    const uint32_t mapSize = 100;
    PerfectHashMap<uint32_t, uint32_t> map(mapSize);

    for (uint32_t index = 0; index < mapSize * 2; index++)
    {
        ASSERT_EQ(map.containsKey(index), false);
    }
}

TEST_F(PerfectHashMapTest, InsertKeyTest_Sunny)
{
    const uint32_t mapSize = 100;
    PerfectHashMap<uint32_t, uint32_t> map(mapSize);

    for (uint32_t key = 0; key < mapSize; key++)
    {
        map.insertKey(key);
        ASSERT_EQ(map.containsKey(key), true);
    }
}

TEST_F(PerfectHashMapTest, ContainsKeyTest_Rainy)
{
    const uint32_t mapSize = 100;
    PerfectHashMap<uint32_t, uint32_t> map(mapSize);

    for (uint32_t key = 0; key < mapSize; key++)
    {
        map.insertKey(key);
        ASSERT_EQ(map.containsKey(key), true);
    }

    for (uint32_t key = mapSize; key < mapSize * 2; key++)
    {
        ASSERT_EQ(map.containsKey(key), false);
    }
}

TEST_F(PerfectHashMapTest, DeleteKeyTest_Sunny)
{
    const uint32_t mapSize = 100;
    PerfectHashMap<uint32_t, uint32_t> map(mapSize);

    for (uint32_t key = 0; key < mapSize; key++)
    {
        map.insertKey(key);
        ASSERT_EQ(map.containsKey(key), true);
    }

    for (uint32_t key = mapSize; key < mapSize * 2; key++)
    {
        const uint32_t originalKey = key - mapSize;
        map.deleteKey(key);
        ASSERT_EQ(map.containsKey(originalKey), true);
    }

    for (uint32_t key = 0; key < mapSize; key++)
    {
        map.deleteKey(key);
        ASSERT_EQ(map.containsKey(key), false);
    }
}