#include "BasicClass.h"
#include "ConstantClass.h"

#include <iostream>
#include <stdint.h>

int main()
{
    // --- In C++ the "new" keyword can be used to allocate an object on the
    //     heap. We will allocate an instance of the Basic Class to
    //     demonstrate how to create an object and assign it to a pointer
    //     When the newly allocated object is created, what is actually
    //     being assigned to the BasicClass pointer variable
    //     "myBasicClass" is the memory address that the object was created
    //     at
    BasicClass* myBasicClass = new BasicClass();

    // --- We can see what the memory address is by printing the pointer
    //     to the console.
    std::cout << myBasicClass << std::endl;

    // --- In contrast to a object created on the stack. We access the
    //     member variables and functions using "->" instead of '.'
    int32_t myNewSecretValue = 2;
    myBasicClass->setSecretValue(myNewSecretValue);
    std::cout << "myBasicClass's Secret Value is: "
              << myBasicClass->getSecretValue() << std::endl;

    // --- Another important thing to understand is how the "const"
    //     keyword interacts with pointers.
    // --- In C++, the "const" keyword applies to the Symbol/Type
    //     that is immediately to the left of it EXCEPT for when
    //     const is the first keyword. In that case it applies to
    //     the Symbol/Type to the right of it.
    // --- For example, the line below defines an integer that
    //     cannot be modified once it is created
    const int32_t myConstantInt = 8;

    // --- In practice, the following statement does the same
    //     thing, but the former is the prefered notation
    int32_t const myOtherConstantInt = 8;

    // --- Meanwhile, the next line defines a constant pointer
    //     to an integer. In this example, the value of the integer
    //     can be modified; however, the address that the pointer
    //     variable points to cannot
    int32_t* const constantPointerToInt = new int32_t(2);
    std::cout << "constantPointerToInt Value: " << *constantPointerToInt
              << std::endl;

    // --- Since we can modify the integer stored at the memory address,
    //     we can still dereference the pointer by prepending the variable
    //     with '*' and modify the value
    *constantPointerToInt = 10;
    std::cout << "constantPointerToInt Value: " << *constantPointerToInt
              << std::endl;

    // --- If we can create a constant pointer to a constant value by
    //     doing the following. In effect this creates a value that
    //     can never be modified. (Of course that is assuming you)
    //     do not cast the const-ness away using "const_cast"
    const int32_t* const myPermanentIntPtr = new int32_t(100);

    // --- The same logic that is described above can also be extended to
    //     classes; however, there is an additional wrinkle for classes.
    // --- The additional wrinkle is that if you declare a class to be
    //     const than you can only call functions on the class which are
    //     themselves declared as const.
    // --- Declaring a function as const garuntees that you will not
    //     modify the data contained within the class through the
    //     execution of the function. A good example of this would
    //     be a "getter", a function which simply returns the value
    //     stored in a member variable within the class.
    // --- Go to ConstantClass.cpp and ConstantClass.h for more
    //     information
    const ConstantClass myConstantClass(myConstantInt);

    std::cout << "myConstantClass contains the Secret Value: "
              << myConstantClass.getSecretValue()
              << "\nmyConstantClass contains the Constant Secret Value: "
              << myConstantClass.getConstantSecretValue() << std::endl;

    return 0;
}