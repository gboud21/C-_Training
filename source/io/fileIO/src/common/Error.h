#ifndef ERROR_H
#define ERROR_H

#include <iostream>

namespace common
{
class Error
{
public:
    enum ErrorCode
    {
        NO_ERROR = 0,
        BUFFER_FULL,
        MAX_ERROR
    };

    Error();
    Error(ErrorCode code);

    void setErrorCode(ErrorCode code);

    const std::string getErrorString();

private:
    ErrorCode errorCode;
    static const std::string ERROR_STRINGS[MAX_ERROR];
};
} // namespace common
#endif // ERROR_H