#include "ExtendableEnum.h"

#include <gtest/gtest.h>
#include <limits.h>

namespace utl
{
// The fixture for testing class Foo.
class ExtendableEnumTest : public testing::Test
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

enum TestEnum
{
    VALUE_0,
    VALUE_1,
    VALUE_2,
    VALUE_3,
    VALUE_4,
    VALUE_5,
    VALUE_6,
    VALUE_MAX = INT_MAX
};

enum AnotherEnum
{
    ANOTER_0 = 500,
    ANOTER_1,
    ANOTER_2,
    ANOTER_3,
    ANOTER_4,
    ANOTER_5,
    ANOTER_6
};

///////////////////////////////////////////////////////////////////////////
// Description: Tests adding enumerations of multiple types and checking for
// comparisons
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumTest, AddAndEqualTestSunny)
{
    ExtendableEnum extEnum;
    // ExtendableEnumLiteral testLiteral(extEnum);
    ExtendableEnum::ExtendableEnumLiteral testLiteral(extEnum);

    EXPECT_TRUE(true);

    // // Verify that the default literal is not a part of the ExtendEnumeration
    EXPECT_FALSE(testLiteral.isEqual<TestEnum>(VALUE_0));

    // Add a value using the Base methods and verify the enumeration value
    // equals the literal
    testLiteral.setLiteral<TestEnum>(VALUE_1);
    extEnum.addExtendableLiteral(testLiteral);
    EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_1));

    // // Add all of the Test Enum Values
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_0));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_2));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_3));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_4));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_5));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_6));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<TestEnum>(VALUE_MAX));

    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_0));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_1));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_2));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_3));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_4));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_5));
    EXPECT_TRUE(extEnum.addEnumerationLiteral<AnotherEnum>(ANOTER_6));

    // // Use each of the Enumerations and verify that each entry added to the
    // list
    // // can be used
    // // Verify ExtendedEnumeration value is set correctly
    // // Verify ExtendedEnumeration is equal to itself
    // testLiteral.setLiteral<TestEnum>(VALUE_0);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_0));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_1);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_1));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_2);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_2));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_3);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_3));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_3);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_3));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_3);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_3));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_4);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_4));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_5);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_5));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_6);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_6));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<TestEnum>(VALUE_MAX);
    // EXPECT_TRUE(testLiteral.isEqual<TestEnum>(VALUE_MAX));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_0);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_0));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_1);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_1));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_2);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_2));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_3);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_3));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_4);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_4));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_5);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_5));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));

    // testLiteral.setLiteral<AnotherEnum>(ANOTER_6);
    // EXPECT_TRUE(testLiteral.isEqual<AnotherEnum>(ANOTER_6));
    // EXPECT_TRUE(testLiteral.isEqual(testLiteral));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test the less than operator
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumTest, LessThanOperator) {}
} // namespace utl
