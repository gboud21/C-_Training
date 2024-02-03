#ifndef __UNORDEREDNODE_H__
#define __UNORDEREDNODE_H__

#include <stdint.h>

namespace maps
{
template <typename K, typename V>
class UnorderedNode
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Default Constructor
    //////////////////////////////////////////////////////////////////
    UnorderedNode() {}

    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] value - A Constant Integer to assign to the
    ///                     constantSecretValue
    //////////////////////////////////////////////////////////////////
    UnorderedNode(K k, V v) : m_key(k), m_value(v) {}

private:
    K m_key;
    V m_value;
};
} // namespace maps
#endif