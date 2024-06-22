#include "Joy2Map.h"

//////////////////////////////////////////////////////////////////
/// Joy2Map::Joy2Map()
//////////////////////////////////////////////////////////////////
Joy2Map::Joy2Map(const uint32_t tableSize)
    : m_table(new Joy2Bin[tableSize]), m_size(tableSize)
{
}

//////////////////////////////////////////////////////////////////
/// Joy2Map::~Joy2Map()
//////////////////////////////////////////////////////////////////
Joy2Map::~Joy2Map() {}

//////////////////////////////////////////////////////////////////
/// Joy2Map::insertKey()
//////////////////////////////////////////////////////////////////
void Joy2Map::insertKey(const uint32_t key)
{
    // Hash the key into an array index
    const uint32_t index = key % m_size;

    Joy2Bin* bin = &m_table[index];

    // If the entry in the array is free then store the key
    if (bin->isFree())
    {
        bin->setKey(key);
    }
    else
    {
        // Collision detected. There is already a key here
    }
}

//////////////////////////////////////////////////////////////////
/// Joy2Map::containsKey()
//////////////////////////////////////////////////////////////////
bool Joy2Map::containsKey(const uint32_t key)
{
    bool value = false;

    // Hash the key into an array index
    const uint32_t index = key % m_size;

    Joy2Bin* bin = &m_table[index];

    // If the entry is nmot free and the key matches
    if (!bin->isFree() && bin->getKey() == key)
    {
        value = true;
    }

    return value;
}

//////////////////////////////////////////////////////////////////
/// Joy2Map::deleteKey()
//////////////////////////////////////////////////////////////////
void Joy2Map::deleteKey(const uint32_t key)
{
    // Hash the key into an array index
    const uint32_t index = key % m_size;

    Joy2Bin* bin = &m_table[index];

    // If the entry in the array is free then store the key
    if (bin->isFree() && bin->getKey() == key)
    {
        bin->free();
    }
}