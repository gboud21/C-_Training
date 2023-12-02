#ifndef RAWDATABUFFER_H
#define RAWDATABUFFER_H
#include <stdint.h>

class RawDataBuffer
{
public:
    RawDataBuffer(uint64_t size);
    void printContents();

private:
    uint8_t* data;
    uint64_t dataSize;
    uint64_t maxSize;
};
#endif // RAWDATABUFFER_H