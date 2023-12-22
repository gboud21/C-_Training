#ifndef ALGORITHMTYPES_H
#define ALGORITHMTYPES_H
// Just some data types that are useful across a variety of tests

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// \details Used to identifiy which version of a function should be run
// when executing. This value should be passed into the constructor of the
// class when it is instantiated.
///////////////////////////////////////////////////////////////////////////
enum FunctionVersion
{
    BRUTE_FORCE,
    OPTIMIZATION_ONE,
    OPTIMIZATION_TWO,
    OPTIMIZATION_THREE,
    OPTIMIZATION_FOUR,
    OPTIMIZATION_FIVE,
    MAX_FUNCTION_VERSION
};
} // namespace alg
#endif
