#include "Error.h"

namespace common
{
const std::string Error::ERROR_STRINGS[MAX_ERROR]{std::string("No Error"),
                                                  std::string("Buffer Full"),
                                                  std::string("Max_Error")};

Error::Error() : errorCode(MAX_ERROR) {}
Error::Error(ErrorCode code) : errorCode(code) {}

void Error::setErrorCode(ErrorCode code) { errorCode = code; }

const std::string Error::getErrorString() { return ERROR_STRINGS[errorCode]; }
} // namespace common