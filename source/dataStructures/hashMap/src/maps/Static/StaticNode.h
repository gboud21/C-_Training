#ifndef __STATICNODE_H__
#define __STATICNODE_H__

#include <stdint.h>

template <typename K, typename V>
class StaticNode
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Default Constructor
    //////////////////////////////////////////////////////////////////
    StaticNode() {}

    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] value - A Constant Integer to assign to the
    ///                     constantSecretValue
    //////////////////////////////////////////////////////////////////
    StaticNode(K k, V v) : m_key(k), m_value(v) {}

private:
    K m_key;
    V m_value;
};
#endif