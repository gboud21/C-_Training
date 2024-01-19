#ifndef BASEEXTENDABLEENUM_H
#define BASEEXTENDABLEENUM_H

#include <map>
#include <stdint.h>

#include "ExtendableEnumLiteral.h"

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides the ability to mesh multiple enumerations
/// together into a single access point. This class provides the ability to
/// combine two C++ enum types together into a single list
////////////////////////////////////////////////////////////////////////////////////
class BaseExtendableEnum
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    BaseExtendableEnum();

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~BaseExtendableEnum();

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Adds an enumeration literal
    /// \details This function adds an Enumeration Literal to the list
    /// \param literal - The enumeration literal to add to the list
    /// \return bool - TRUE if literal added, FALSE otherwise
    ////////////////////////////////////////////////////////////////////////////////
    bool addEnumerationLiteral(const ExtendableEnumLiteral& literal);

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Determines if an enumeration literal is valid
    /// \details This function takes an BaseExtendableEnumerationLiteral and
    /// determines if it is a part of this Enumerated Type
    /// \param [in] literal - The enumeration literal to validate list
    /// \return bool - TRUE if literal is a valid literal, FALSE otherwise
    ////////////////////////////////////////////////////////////////////////////////
    bool isValid(const ExtendableEnumLiteral& literal) const;

protected:
    // Mapping that tracks the integer equivalent value for an enumeration
    std::map<ExtendableEnumLiteral, bool> m_enumerationMap;
};
#endif // BASEEXTENDABLEENUM_H
