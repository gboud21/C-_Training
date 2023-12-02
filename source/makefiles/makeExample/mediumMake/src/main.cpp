#include <iostream>

#include "driver/SingleThreadedDriver.h"

int main()
{
    std::cout << "Starting PickIt" << std::endl;
    std::cout << "HEre's another message" << std::endl;
    SingleThreadedDriver *driver = new SingleThreadedDriver();
    
    if ( nullptr != driver )
    {
        delete driver;
        driver = nullptr;
    }

    return 0;
}