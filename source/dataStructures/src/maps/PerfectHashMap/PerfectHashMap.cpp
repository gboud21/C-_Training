#include "PerfectHashMap.h"

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::PerfectHashMap()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
PerfectHashMap<K, V>::PerfectHashMap(const uint32_t tableSize)
    : m_table(new PerfectHashNode<K, V>[tableSize]), m_size(tableSize),
      hashFactor(1)
{
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::~PerfectHashMap()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
PerfectHashMap<K, V>::~PerfectHashMap()
{
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::insertKey()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
void PerfectHashMap<K, V>::insertKey(const K key)
{
    // Hash the key into an array index
    const uint32_t index = calculateHash(key);

    // Get the node from the table using the calculated hash for the key
    PerfectHashNode<K, V>* bin = &m_table[index];

    // If the node is already in use then a collision has occurred
    if (!bin->isFree())
    {
        // Calculate a new hash function to resolve the collision and
        // then redistribute the nodes
        bin = recalculateHashOffset(key);
    }

    // If the entry in the array is free then store the key
    bin->setKey(key);
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::containsKey()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
bool PerfectHashMap<K, V>::containsKey(const K key)
{
    bool value = false;

    // Hash the key into an array index
    const uint32_t index = calculateHash(key);

    // Get the node from the table using the calculated hash for the key
    PerfectHashNode<K, V>* bin = &m_table[index];

    // If the entry is not free and the key matches
    if (!bin->isFree() && bin->getKey() == key)
    {
        value = true;
    }

    return value;
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::deleteKey()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
void PerfectHashMap<K, V>::deleteKey(const K key)
{
    // Hash the key into an array index
    const uint32_t index = key % m_size;

    PerfectHashNode<K, V>* bin = &m_table[index];

    // If the entry in the array is free then store the key
    if (bin->isFree() && bin->getKey() == key)
    {
        bin->free();
    }
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::recalculateHashOffset()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
PerfectHashNode<K, V>* PerfectHashMap<K, V>::recalculateHashOffset(const K key)
{
    return nullptr;
}

//////////////////////////////////////////////////////////////////
/// PerfectHashMap::calculateHash()
//////////////////////////////////////////////////////////////////
template <typename K, typename V>
uint32_t PerfectHashMap<K, V>::calculateHash(const K key)
{
    const uint32_t prime = 12289;
    uint32_t hash = (hashFactor * key & prime) % m_size;
    return hash;
}