#include "ExtendableEnumLiteral.h"

#include <gtest/gtest.h>
#include <limits.h>

namespace utl
{
// The fixture for testing class Foo.
class ExtendableEnumLiteralTest : public testing::Test
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
// Description: Test Default Constructor does not initialize any values
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumLiteralTest, DefaultConstructorTest)
{
    ExtendableEnumLiteral testEnum;

    EXPECT_FALSE(testEnum.isEqual<TestEnum>(VALUE_0));
    EXPECT_FALSE(testEnum.isEqual<TestEnum>(VALUE_MAX));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Constructor correctly initializes values
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumLiteralTest, ParamaterizedConstructorTest)
{
    ExtendableEnumLiteral testEnum(static_cast<uint64_t>(VALUE_0));

    EXPECT_TRUE(testEnum.isEqual<TestEnum>(VALUE_0));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test Constructor correctly sets the value and performs
// comparisons between Enumerations and the class
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumLiteralTest, SetAndEqualTest)
{
    ExtendableEnumLiteral testEnum;

    // Set the enumeration to TestEnum::VALUE_1 and verify the value is set
    testEnum.setLiteral<TestEnum>(VALUE_1);
    EXPECT_TRUE(testEnum.isEqual<TestEnum>(VALUE_1));
    EXPECT_FALSE(testEnum.isEqual<TestEnum>(VALUE_5));

    // Set the enumeration to TestEnum::VALUE_5 and verify the value is set
    testEnum.setLiteral<TestEnum>(VALUE_5);
    EXPECT_TRUE(testEnum.isEqual<TestEnum>(VALUE_5));
    EXPECT_FALSE(testEnum.isEqual<TestEnum>(VALUE_1));

    // Set the enumeration using a different type AnotherEnum::ANOTER_0
    testEnum.setLiteral<AnotherEnum>(ANOTER_0);
    EXPECT_TRUE(testEnum.isEqual<AnotherEnum>(ANOTER_0));
    EXPECT_FALSE(testEnum.isEqual<TestEnum>(VALUE_1));
}

///////////////////////////////////////////////////////////////////////////
// Description: Test the less than operator
///////////////////////////////////////////////////////////////////////////
TEST_F(ExtendableEnumLiteralTest, LessThanOperator)
{
    ExtendableEnumLiteral testEnum;
    ExtendableEnumLiteral anotherEnum;

    // Using two different enumeration types, perform a comparison to ensure
    // TestEnum is less than anotherEnum (1 < 500)
    testEnum.setLiteral<TestEnum>(VALUE_1);
    anotherEnum.setLiteral<AnotherEnum>(ANOTER_0);
    EXPECT_TRUE(testEnum < anotherEnum);
    EXPECT_FALSE(anotherEnum < testEnum);

    // Set the values equal and ensure less than returns false if they are equal
    // (1 == 1)
    anotherEnum.setLiteral<TestEnum>(VALUE_1);
    EXPECT_FALSE(testEnum < anotherEnum);
}
} // namespace utl
