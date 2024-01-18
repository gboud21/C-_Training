#include "ErrorTable.h"

#include <gtest/gtest.h>

// The fixture for testing class Foo.
class ErrorTest : public testing::Test
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
// Description: Simple Test to proof out base functionality
///////////////////////////////////////////////////////////////////////////
TEST_F(ErrorTest, BasicErrorTableTest)
{
    EXPECT_EQ(ErrorTable<GenericError::GenericErrorCode>::getInstance()
                  .getErrorString(GenericError::GenericErrorCode::NO_ERROR),
              std::string("No Error"));

    EXPECT_EQ(
        ErrorTable<GenericError::GenericErrorCode>::getInstance()
            .getErrorString(GenericError::GenericErrorCode::ALREADY_EXISTS),
        std::string("Already Exists"));
}
