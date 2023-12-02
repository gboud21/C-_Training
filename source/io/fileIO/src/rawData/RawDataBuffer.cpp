#include "RawDataBuffer.h"

#include <iostream>

RawDataBuffer::RawDataBuffer(uint64_t size)
    : data(nullptr), dataSize(0), maxSize(size)
{
    data = new uint8_t[size];
}

void RawDataBuffer::printContents()
{
    std::cout << "RawDataBuffer contents: " << std::endl;
}