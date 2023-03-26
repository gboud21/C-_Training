#include <iostream>

#include "RawDataBuffer.h"

int main(int argc, char** argv)
{
    std::cout << "Running FileIO" << std::endl;

    RawDataBuffer buffer;

    buffer.printContents();

    return 0;
}