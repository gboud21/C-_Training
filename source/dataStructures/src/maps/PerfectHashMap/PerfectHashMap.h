#ifndef PERFECTHASHMAP_H
#define PERFECTHASHMAP_H

#include <stdint.h>

#include "PerfectHashNode.h"

template <typename K, typename V>
class PerfectHashMap
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] tableSize - The size of the Map
    //////////////////////////////////////////////////////////////////
    PerfectHashMap(const uint32_t tableSize);

    //////////////////////////////////////////////////////////////////
    /// \brief Destructor
    //////////////////////////////////////////////////////////////////
    ~PerfectHashMap();

    //////////////////////////////////////////////////////////////////
    /// \brief Inserts a key into the map
    /// \param [in] key - The key to insert into the map
    /// \return void
    //////////////////////////////////////////////////////////////////
    void insertKey(const K key);

    //////////////////////////////////////////////////////////////////
    /// \brief True if the key is in the map. False otherwise
    /// \param [in] key - The key to find in the map
    /// \return bool
    //////////////////////////////////////////////////////////////////
    bool containsKey(const K key);

    //////////////////////////////////////////////////////////////////
    /// \brief Deletes the key from the map
    /// \param [in] key - The key to delete from the map
    /// \return void
    //////////////////////////////////////////////////////////////////
    void deleteKey(const K key);

private:
    //////////////////////////////////////////////////////////////////
    /// \brief When a collision is detected, all of the hashes for the
    /// entries are recalculated using a new hashing function to
    /// remove collisions. It will return the node that the new key
    /// will be inserted into.
    /// \param [in] key - The new key that caused the collision and
    /// requires a new hash function to be calculated for to be added
    /// to the map
    /// \return PerfectHashNode*
    //////////////////////////////////////////////////////////////////
    PerfectHashNode<K, V>* recalculateHashOffset(const K key);

    //////////////////////////////////////////////////////////////////
    /// \brief Calculates the hash for a specfic key and returns the
    /// calculated value of the hash
    /// \param [in] key - The key to calculate a hash for
    /// \return uint32_t
    //////////////////////////////////////////////////////////////////
    uint32_t calculateHash(const K key);

    // The table of data
    PerfectHashNode<K, V>* m_table;

    // The number of elements in the hash map
    uint32_t m_elementCount;

    // The total size of the table
    const uint32_t m_size;

    // The factor to apply to the hash map to try to get a unique number for
    // each entry
    uint32_t hashFactor;
};

#ifndef PERFECTHASHMAP_CPP
#define PERFECTHASHMAP_CPP
#include "PerfectHashMap.cpp"
#endif

#endif
