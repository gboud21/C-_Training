#ifndef __CONSTANTCLASS_H__
#define __CONSTANTCLASS_H__

#include <stdint.h>

class ConstantClass
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] value - A Constant Integer to assign to the
    ///                     constantSecretValue
    //////////////////////////////////////////////////////////////////
    ConstantClass(const int32_t value);

    //////////////////////////////////////////////////////////////////
    /// \brief Returns the Secret Value
    /// \details This function returns the Secret Value. This function
    /// will not modify any member variables within this class. Which
    /// is why the "const" keyword follows the function prototype.
    /// \return int32_t
    //////////////////////////////////////////////////////////////////
    const int32_t getSecretValue() const;

    //////////////////////////////////////////////////////////////////
    /// \brief Sets the Secret Value
    /// \details This function sets the Secret Value to a new value.
    /// Since this function modifies the secretValue member variable
    /// it cannot be declared as const.
    /// \param [in] value - value to assign to the Secret Value
    /// \return void
    //////////////////////////////////////////////////////////////////
    void setSecretValue(int32_t value);

    //////////////////////////////////////////////////////////////////
    /// \brief Returns the Constant Secret Value
    /// \details This function returns the Constant Secret Value. This
    /// function will not modify any member variables within this class.
    /// Which is why the "const" keyword follows the function prototype.
    /// \return int32_t
    //////////////////////////////////////////////////////////////////
    const int32_t getConstantSecretValue() const;

private:
    int32_t secretValue;
    const int32_t constantSecretValue;
};
#endif