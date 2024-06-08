#include "UnorderedMap.h"

namespace maps
{

template <typename K, typename V, typename hashFunction>
const size_t UnorderedMap<K, V, hashFunction>::DEFAULT_MAP_SIZE = 31;

template <typename K, typename V, typename hashFunction>
const float UnorderedMap<K, V, hashFunction>::MAP_USAGE_RATIO = 0.2f;

///////////////////////////////////////////////////////////////////////////
/// UnorderedMap::UnorderedMap()
///////////////////////////////////////////////////////////////////////////
template <typename K, typename V, typename hashFunction>
UnorderedMap<K, V, hashFunction>::UnorderedMap()
    : m_nodeCount(DEFAULT_MAP_SIZE), m_size(0),
      mp_nodes(new UnorderedNode<K, V>[m_nodeCount])
{
}

///////////////////////////////////////////////////////////////////////////
/// UnorderedMap::insert()
///////////////////////////////////////////////////////////////////////////
template <typename K, typename V, typename hashFunction>
void UnorderedMap<K, V, hashFunction>::insert(K key, V value)
{
#include <iostream>
    std::cout << hashFunction() << std::endl;
}

///////////////////////////////////////////////////////////////////////////
/// UnorderedMap::size()
///////////////////////////////////////////////////////////////////////////
template <typename K, typename V, typename hashFunction>
const size_t UnorderedMap<K, V, hashFunction>::size() const
{
    return m_size;
}

///////////////////////////////////////////////////////////////////////////
/// UnorderedMap::resize()
///////////////////////////////////////////////////////////////////////////
template <typename K, typename V, typename hashFunction>
const void UnorderedMap<K, V, hashFunction>::resize() const
{
    // If the hash map has exceeded its usage ratio then
    if (m_size / m_nodeCount >= MAP_USAGE_RATIO)
    {
        // Double the size of the map
        m_nodeCount *= 2;

        // Allocate new space for the map

        // Add all of the elements in the current map to the new map
    }
}

} // namespace maps