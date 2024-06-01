#ifndef __UNORDEREDMAP_H__
#define __UNORDEREDMAP_H__
#include "Hash.h"
#include "UnorderedNode.h"

#include <functional>
#include <stdint.h>

namespace maps
{
template <typename K, typename V, typename hashFunction = Hash<K>()>
// template <typename K, typename V, typename hashFunction = std::less<K>>
class UnorderedMap
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    //////////////////////////////////////////////////////////////////
    UnorderedMap();

    //////////////////////////////////////////////////////////////////
    /// \brief Sets the Secret Value
    /// \details This function sets the Secret Value
    /// \param [in] value - value to assign to the Secret Value
    /// \return void
    //////////////////////////////////////////////////////////////////
    void insert(K key, V value);

    //////////////////////////////////////////////////////////////////
    /// \brief Returns the size of the map
    /// \details This function returns the number of elements currently
    /// stored in the hash map
    /// \return size_t
    //////////////////////////////////////////////////////////////////
    const size_t size() const;

private:
    //////////////////////////////////////////////////////////////////
    /// \brief Resizes the map
    /// \details This function checks if the map has exceeded its usage raito.
    /// If it has it will resize the map to ...
    //////////////////////////////////////////////////////////////////
    void resizeMap();

    // The starting size for a new map
    static const size_t DEFAULT_MAP_SIZE;

    // The maximum ratio of used elements to open spaces before the map will be
    // resized
    static const float MAP_USAGE_RATIO;

    // The total number of nodes currently allocated in the map
    size_t m_nodeCount;

    // The number of elements currently stored in the Hash Map
    size_t m_size;

    // Pointer to an array of nodes that makeup the map
    UnorderedNode<K, V>* mp_nodes;
};
} // namespace maps
#endif

#ifndef __UNORDEREDMAP_CPP__
#define __UNORDEREDMAP_CPP__
#include "UnorderedMap.cpp"
#endif
