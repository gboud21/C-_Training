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
    StaticNode(K k, V v) : key(k), value(v) {}

private:
    K key;
    V value;
};
#endif