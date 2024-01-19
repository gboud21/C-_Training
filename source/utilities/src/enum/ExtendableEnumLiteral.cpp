#include "ExtendableEnumLiteral.h"

// #include "BaseExtendableEnum.h"

//////////////////////////////////////////////////////////////////
/// ExtendableEnumLiteral::ExtendableEnumLiteral()
//////////////////////////////////////////////////////////////////
ExtendableEnumLiteral::ExtendableEnumLiteral(
    /*const BaseExtendableEnum& enumType*/)
    : /*mp_enumType(enumType),*/ m_literal(0)
{
}

// //////////////////////////////////////////////////////////////////
// /// ExtendableEnumLiteral::ExtendableEnumLiteral()
// //////////////////////////////////////////////////////////////////
ExtendableEnumLiteral::ExtendableEnumLiteral(/*const BaseExtendableEnum&
                                                enumType,*/
                                             int64_t literal)
    : /*mp_enumType(enumType),*/ m_literal(literal)
{
}

// //////////////////////////////////////////////////////////////////
// /// ExtendableEnumLiteral::~ExtendableEnumLiteral()
// //////////////////////////////////////////////////////////////////
ExtendableEnumLiteral::~ExtendableEnumLiteral(void) {}

//////////////////////////////////////////////////////////////////
/// ExtendableEnumLiteral::setLiteral()
//////////////////////////////////////////////////////////////////
template <typename T>
void ExtendableEnumLiteral::setLiteral(const T literal)
{
    m_literal = static_cast<int64_t>(literal);
}

// //////////////////////////////////////////////////////////////////
// /// ExtendableEnumLiteral::isEqual()
// //////////////////////////////////////////////////////////////////
template <typename T>
bool ExtendableEnumLiteral::isEqual(const T literal)
{
    return (mp_enumType.isValid(*this) &&
            (static_cast<int64_t>(literal) == m_literal));
}

//////////////////////////////////////////////////////////////////
/// ExtendableEnumLiteral::operator<()
//////////////////////////////////////////////////////////////////
bool ExtendableEnumLiteral::operator<(const ExtendableEnumLiteral& rhs) const
{
    return (m_literal < rhs.m_literal);
}
