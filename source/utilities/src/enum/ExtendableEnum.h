#ifndef EXTENDABLEENUM_H
#define EXTENDABLEENUM_H

#include <map>
#include <stdint.h>

#include "BaseExtendableEnum.h"

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides the ability to mesh multiple enumerations
/// together into a single access point. This class provides the ability to
/// combine two C++ enum types together into a single list
////////////////////////////////////////////////////////////////////////////////////
class ExtendableEnum : public BaseExtendableEnum
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    ExtendableEnum(){};

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~ExtendableEnum(){};

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Adds an enumeration literal
    /// \details This function takes an enumeration literal whose type is
    /// specified by the template parameter. It then casts the literal to an
    /// 64-bit integer and attempts to add it to the list of enumeration
    /// literals. If an enumeration literal is able to be added then TRUE will
    /// be returned; otherwise it will return FALSE.
    /// \param enumValue - The enumeration literal to add to the list
    /// \return bool - TRUE if literal added, FALSE otherwise
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    bool addEnumerationLiteral(const T enumValue)
    {
        return m_enumerationMap
            .insert(std::pair<ExtendableEnumLiteral, bool>(
                ExtendableEnumLiteral(static_cast<uint64_t>(enumValue)), true))
            .second;
    };

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Determines if a C++ enumeration literal is a part of this list
    /// \details This function takes an enumeration literal
    /// whose type is specified by the template parameter. It then casts the
    /// literal to an 64-bit integer and checks to see if the raw literal value
    /// could be a part of this Enumerated Type
    /// \param [in] enumValue - The enumeration literal to check for
    /// \return bool - TRUE if literal is a valid literal, FALSE otherwise
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    bool isValid(const T enumValue)
    {
        return m_enumerationMap.find(ExtendableEnumLiteral(
                   static_cast<uint64_t>(enumValue))) != m_enumerationMap.end();
    };
};
#endif // EXTENDABLEENUM_H
