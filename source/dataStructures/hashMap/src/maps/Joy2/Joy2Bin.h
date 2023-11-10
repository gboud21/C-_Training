#ifndef JOY2BIN_H
#define JOY2BIN_H
#include <stdint.h>

class Joy2Bin
{
public:
    //////////////////////////////////////////////////////////////////
    /// \brief Constructor
    /// \param [in] value - A Constant Integer to assign to the
    ///                     constantSecretValue
    //////////////////////////////////////////////////////////////////
    Joy2Bin();

    //////////////////////////////////////////////////////////////////
    /// \brief Destructor
    //////////////////////////////////////////////////////////////////
    ~Joy2Bin();

    //////////////////////////////////////////////////////////////////
    /// \brief Sets the entry as free
    /// \return void
    //////////////////////////////////////////////////////////////////
    void free();

    //////////////////////////////////////////////////////////////////
    /// \brief Returns m_isFree
    /// \return void
    //////////////////////////////////////////////////////////////////
    bool isFree();

    //////////////////////////////////////////////////////////////////
    /// \brief Sets the key and marks it as not free
    /// \param [in] key - The key value to assign
    //////////////////////////////////////////////////////////////////
    void setKey(const uint32_t key);

    //////////////////////////////////////////////////////////////////
    /// \brief Returns m_key
    /// \return void
    //////////////////////////////////////////////////////////////////
    uint32_t getKey();

private:
    // Is the bin in use
    bool m_isFree;

    // The key for the bin
    uint32_t m_key;
};

#endif