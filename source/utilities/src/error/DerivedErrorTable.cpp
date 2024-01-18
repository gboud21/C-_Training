////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: errorTable.cpp
///
/// Class Name: ErrorTable
///
/// Description: The ErrorTable class is a singleton class that CodeWeb
/// uses to
///              check for errors. This class makes calls to the Logger class
///              when an error is detected to log the error to the log file and
///              then asserts to close the application.
///
////////////////////////////////////////////////////////////////////////////////////

#include "ErrorTable.h"

////////////////////////////////////////////////////////////////////////////////
///
///                            Static Variables
///
////////////////////////////////////////////////////////////////////////////////
template <typename ErrorCodeType>
const std::pair<ErrorCodeType, std::string>
    ErrorTable<ErrorCodeType>::m_errorCodes[ErrorCodeType::ERROR_MAX] = {
        ErrorPair(ErrorCodeType::NO_ERROR, std::string("No Error")),
        ErrorPair(ErrorCodeType::INVALID_ARGUMENT,
                  std::string("Invalid Argument")),
        ErrorPair(ErrorCodeType::ALREADY_EXISTS, std::string("Already Exists")),
        ErrorPair(ErrorCodeType::FAILED_ALLOCATION,
                  std::string("Failed Allocation")),
        ErrorPair(ErrorCodeType::OUT_OF_BOUNDS, std::string("Out of Bounds"))};

//////////////////////////////////////////////////////////////////
/// ErrorTable::getInstance()
//////////////////////////////////////////////////////////////////
template <typename ErrorCodeType>
ErrorTable<ErrorCodeType>& ErrorTable<ErrorCodeType>::getInstance(void)
{
    static ErrorTable<ErrorCodeType> errorTable;

    return errorTable;
}

//////////////////////////////////////////////////////////////////
/// ErrorTable::getErrorString()
//////////////////////////////////////////////////////////////////
template <typename ErrorCodeType>
std::string ErrorTable<ErrorCodeType>::getErrorString(ErrorCodeType errorCode)
{
    return m_errorStringMap[errorCode];
}

//////////////////////////////////////////////////////////////////
/// ErrorTable::ErrorTable()
//////////////////////////////////////////////////////////////////
template <typename ErrorCodeType>
ErrorTable<ErrorCodeType>::ErrorTable(void)
{
    for (uint32_t index = 0; index < ErrorCodeType::ERROR_MAX; index++)
    {
        m_errorStringMap.insert(m_errorCodes[index]);
    }
}

//////////////////////////////////////////////////////////////////
/// ErrorTable::~ErrorTable()
//////////////////////////////////////////////////////////////////
template <typename ErrorCodeType>
ErrorTable<ErrorCodeType>::~ErrorTable(void)
{
}
