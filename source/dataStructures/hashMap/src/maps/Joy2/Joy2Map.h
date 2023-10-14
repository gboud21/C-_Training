#ifndef JOY2MAP_H
#define JOY2MAP_H

#include "Joy2Bin.h"

#include <stdint.h>

class Joy2Map
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] tableSize - The size of the Map
    //////////////////////////////////////////////////////////////////
    Joy2Map(const uint32_t tableSize);

    //////////////////////////////////////////////////////////////////
    /// \brief Destructor
    //////////////////////////////////////////////////////////////////
    ~Joy2Map();

    //////////////////////////////////////////////////////////////////
    /// \brief Inserts a key into the map
    /// \param [in] key - The key to insert into the map
    /// \return void
    //////////////////////////////////////////////////////////////////
    void insertKey(const uint32_t key);

    //////////////////////////////////////////////////////////////////
    /// \brief True if the key is in the map. False otherwise
    /// \param [in] key - The key to find in the map
    /// \return bool
    //////////////////////////////////////////////////////////////////
    bool containsKey(const uint32_t key);

    //////////////////////////////////////////////////////////////////
    /// \brief Deletes the key from the map
    /// \param [in] key - The key to delete from the map
    /// \return void
    //////////////////////////////////////////////////////////////////
    void deleteKey(const uint32_t key);

private:
    // The table of data
    Joy2Bin* m_table;

    // The size of the table
    uint32_t m_size;
};

#endif