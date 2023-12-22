#include "AlgorithmTypes.h"

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// alg::functionVersionToString
///////////////////////////////////////////////////////////////////////////
std::string functionVersionToString(FunctionVersion version)
{
    switch (version)
    {
        case BRUTE_FORCE:
            return std::string("BRUTE_FORCE");
            break;
        case OPTIMIZATION_ONE:
            return std::string("OPTIMIZATION_ONE");
            break;
        case OPTIMIZATION_TWO:
            return std::string("OPTIMIZATION_TWO");
            break;
        case OPTIMIZATION_THREE:
            return std::string("OPTIMIZATION_THREE");
            break;
        case OPTIMIZATION_FOUR:
            return std::string("OPTIMIZATION_FOUR");
            break;
        case OPTIMIZATION_FIVE:
            return std::string("OPTIMIZATION_FIVE");
            break;
        case MAX_FUNCTION_VERSION:
        default:
            return std::string("UNKNOWN_FUNCTION_VERSION");
            break;
    }

    return std::string("UNKNOWN_FUNCTION_VERSION");
}
} // namespace alg
