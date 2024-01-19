#ifndef BASEEXTENDABLEENUM_H
#define BASEEXTENDABLEENUM_H

#include <map>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides the ability to mesh multiple enumerations
/// together into a single access point. This class provides the ability to
/// combine two C++ enum types together into a single list
////////////////////////////////////////////////////////////////////////////////////
class BaseExtendableEnum
{
public:
    ////////////////////////////////////////////////////////////////////////////////////
    /// \details This class provides the ability to mesh multiple enumerations
    /// together into a single access point
    ////////////////////////////////////////////////////////////////////////////////////
    class ExtendableEnumLiteral
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        /// \details Constructor as unassigned
        /// \param [in] enumType - Pointer to the Extenable Enumeration Type
        /// that this object is associated with
        ////////////////////////////////////////////////////////////////////////////////
        ExtendableEnumLiteral(const BaseExtendableEnum& enumType)
            : mp_enumType(enumType), m_literal(0){};

        ////////////////////////////////////////////////////////////////////////////////
        /// \details Constructor as assigned
        /// \param [in] enumType - Pointer to the Extenable Enumeration Type
        /// that this object is associated with \param [in] literal - The
        /// enumeration literal to assign to the object
        ////////////////////////////////////////////////////////////////////////////////
        ExtendableEnumLiteral(const BaseExtendableEnum& enumType,
                              int64_t literal)
            : mp_enumType(enumType), m_literal(literal){};

        ////////////////////////////////////////////////////////////////////////////////
        /// \details Destructor
        ////////////////////////////////////////////////////////////////////////////////
        ~ExtendableEnumLiteral(){};

        ////////////////////////////////////////////////////////////////////////////////
        /// \brief Assigns literal
        /// \details This function takes an enumeration literal whose type is
        /// specified by the template parameter. It then casts the literal to an
        /// 64-bit integer and sets the value for this object to it.
        /// \param [in] literal - The enumeration literal to assign to the
        /// object
        ////////////////////////////////////////////////////////////////////////////////
        template <typename T>
        void setLiteral(const T literal)
        {
            m_literal = static_cast<int64_t>(literal);
        };

        ////////////////////////////////////////////////////////////////////////////////
        /// \brief Compares a literal to this object
        /// \details This function takes an enumeration literal
        /// whose type is specified by the template parameter. It then casts the
        /// literal to an 64-bit integer and checks to see if the casted value
        /// is
        /// equal to this object
        /// \param [in] literal - The enumeration literal to compare aginst
        /// \return bool - TRUE if literal is equal to this object, FALSE if
        /// either
        /// the literal is not equal, or a value was never assigned
        ////////////////////////////////////////////////////////////////////////////////
        template <typename T>
        bool isEqual(const T literal)
        {
            return (mp_enumType.isExtendableValid(*this) &&
                    (static_cast<int64_t>(literal) == m_literal));
        };

        ////////////////////////////////////////////////////////////////////////////////
        /// \brief Less than operator
        /// \details This function specifies the less than operator to use in a
        /// std::map
        /// \param [in] rhs - The ExtendableEnumLiteral to compare against
        /// \return bool - TRUE if this instance is less than the rhs, FALSE
        /// otherwise
        ////////////////////////////////////////////////////////////////////////////////
        bool operator<(const ExtendableEnumLiteral& rhs) const
        {
            return (m_literal < rhs.m_literal);
        };

    private:
        // The Extendable Enumerated Type that this variable is associated with
        const BaseExtendableEnum& mp_enumType;

        // The integer equivalent value of the enumeration literal that was
        // assigned
        int64_t m_literal;
    };

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
    bool addExtendableLiteral(const ExtendableEnumLiteral& literal);

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Determines if an enumeration literal is valid
    /// \details This function takes an BaseExtendableEnumerationLiteral and
    /// determines if it is a part of this Enumerated Type
    /// \param [in] literal - The enumeration literal to validate list
    /// \return bool - TRUE if literal is a valid literal, FALSE otherwise
    ////////////////////////////////////////////////////////////////////////////////
    bool isExtendableValid(const ExtendableEnumLiteral& literal) const;

protected:
    // Mapping that tracks the integer equivalent value for an enumeration
    std::map<ExtendableEnumLiteral, bool> m_enumerationMap;
};
#endif // BASEEXTENDABLEENUM_H
