#include "Joy2Map.h"

#include <gtest/gtest.h>

TEST(Joy2MapTest, ConstructorTest)
{
    const uint32_t mapSize = 100;
    Joy2Map map(mapSize);

    for (uint32_t index = 0; index < mapSize * 2; index++)
    {
        ASSERT_EQ(map.containsKey(index), false);
    }
}

TEST(Joy2MapTest, InsertKeyTest_Sunny)
{
    const uint32_t mapSize = 100;
    Joy2Map map(mapSize);

    for (uint32_t key = 0; key < mapSize; key++)
    {
        map.insertKey(key);
        ASSERT_EQ(map.containsKey(key), true);
    }
}

TEST(Joy2MapTest, ContainsKeyTest_Rainy)
{
    const uint32_t mapSize = 100;
    Joy2Map map(mapSize);

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

TEST(Joy2MapTest, DeleteKeyTest_Sunny)
{
    const uint32_t mapSize = 100;
    Joy2Map map(mapSize);

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