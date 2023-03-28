#ifndef STATICRAWDATABUFFER_H
#define STATICRAWDATABUFFER_H
#include "Error.h"

#include <cstring>
#include <stdint.h>

//////////////////////////////////////////////////////////////////////////
/// \class StaticRawDataBuffer
/// \details This class provides an implementation of a Raw Data Buffer
/// without using Dynamic Memory.
//////////////////////////////////////////////////////////////////////////
template <uint64_t size>
class StaticRawDataBuffer
{
public:
    StaticRawDataBuffer() : dataSize(0), maxSize(size)
    {
        memset(&data, 0, sizeof(uint8_t) * size);
    };

    common::Error add(uint8_t data)
    {
        uint64_t inputSize = sizeof(uint8_t);
        common::Error status(common::Error::NO_ERROR);

        if(checkOverflow(inputSize)
        {
            status.setErrorCode(common::Error::BUFFER_FULL);
        }
        else
        {
            memcpy(&(data[dataSize]), data, sizeof(uint8_t));
        }

        return status;
    };

    void printContents()
    {
        int index;

        std::cout << "StaticRawDataBuffer contents: ";

        for (index = 0; index < maxSize; index++)
        {
            std::cout << data[index] << " ";
        }

        std::cout << std::endl;
    }

private:
    bool checkOverflow(uint64_t inputSize)
    {
        return ((maxSize - dataSize) < inputSize);
    };

    uint8_t buffer[size];
    uint64_t dataSize;
    const uint64_t maxSize;
};
#endif // STATICRAWDATABUFFER_H