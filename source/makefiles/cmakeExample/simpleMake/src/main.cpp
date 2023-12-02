#include "SimpleMakeConfig.h"

#include <iostream>

int main(int argc, char**argv)
{
    std::cout << "Hello World. This is " << argv[0]  
        << "Version " << SimpleMake_VERSION_MAJOR 
        << "." << SimpleMake_VERSION_MINOR << std::endl;
    return 0;
}