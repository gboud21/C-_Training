#include "ConstantClass.h"

ConstantClass::ConstantClass(const int32_t value)
    : constantSecretValue(value), secretValue(0)
{
}

const int32_t ConstantClass::getSecretValue() const { return secretValue; }

void ConstantClass::setSecretValue(int32_t value) { secretValue = value; }

const int32_t ConstantClass::getConstantSecretValue() const
{
    return constantSecretValue;
}
