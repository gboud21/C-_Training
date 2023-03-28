#include <iostream>

#include "StaticRawDataBuffer.h"

int main(int argc, char** argv)
{
    std::cout << "Running FileIO" << std::endl;

    StaticRawDataBuffer<100> staticBuffer;

    staticBuffer.printContents();

    return 0;
}