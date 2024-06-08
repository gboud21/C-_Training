#ifndef __HASH_H__
#define __HASH_H__

#include <cstddef>
#include <stdint.h>

template <typename T>
struct Hash;

template <>
struct Hash<uint32_t>
{
    size_t operator()(const uint32_t value)
    {
        return static_cast<size_t>(value);
    };
};
#endif

// #ifndef __HASH_CPP__
// #define __HASH_CPP__
// #include "Hash.cpp"
// #endif
