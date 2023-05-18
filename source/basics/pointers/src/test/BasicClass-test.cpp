#include "BasicClass.h"

#include <gtest/gtest.h>

TEST(SetSecretValueTest, PositiveNos)
{
    BasicClass myClass;
    myClass.setSecretValue(6);
    ASSERT_EQ(6, myClass.getSecretValue());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}