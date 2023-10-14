#ifndef __STATICMAP_H__
#define __STATICMAP_H__
#include "StaticNode.h"

#include <stdint.h>

template <typename K, typename V, uint32_t mapSize>
class StaticMap
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    //////////////////////////////////////////////////////////////////
    StaticMap() : m_maxSize(mapSize), m_size(0){};

    //////////////////////////////////////////////////////////////////
    /// \brief Sets the Secret Value
    /// \details This function sets the Secret Value
    /// \param [in] value - value to assign to the Secret Value
    /// \return void
    //////////////////////////////////////////////////////////////////
    void insert(K key, V value){};

    //////////////////////////////////////////////////////////////////
    /// \brief Returns the Maximum Size
    /// \details This function returns the maximum number of elements
    /// that the hash map can hold
    /// \return uint32_t
    //////////////////////////////////////////////////////////////////
    const uint32_t getMaxSize() const { return m_maxSize; }

    //////////////////////////////////////////////////////////////////
    /// \brief Returns the size of the map
    /// \details This function returns the number of elements currently
    /// stored in the hash map
    /// \return uint32_t
    //////////////////////////////////////////////////////////////////
    const uint32_t size() const { return m_size; }

private:
    // The maximum number of elements
    const uint32_t m_maxSize;

    // The number of elements currently stored in the Hash Map
    uint32_t m_size;

    StaticNode<K, V> mp_nodes[mapSize];
};
#endif