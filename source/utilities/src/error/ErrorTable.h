#ifndef ERRORTABLE_H
#define ERRORTABLE_H
////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: errorTable.h
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

#include <map>
#include <string>

#include "GenericError.h"

template <typename ErrorCodeType>
class ErrorTable
{
public:
    typedef std::pair<ErrorCodeType, std::string> ErrorPair;

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Returns instance of ErrorTable
    /// \return ErrorTable
    ////////////////////////////////////////////////////////////////////////////////
    static ErrorTable<ErrorCodeType>& getInstance(void);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Returns a string associated with an Error Code
    /// \return std::string - A string representing the error code
    ////////////////////////////////////////////////////////////////////////////////
    std::string getErrorString(ErrorCodeType errorCode);

protected:
    // // --- The mapping of Generic Error Codes to strings
    std::map<ErrorCodeType, std::string> m_errorStringMap;

    static const ErrorPair m_errorCodes[ErrorCodeType::ERROR_MAX];

private:
    ErrorTable(void);

    ~ErrorTable();
};

#endif // ERRORTABLE_H

#ifndef ERRORTABLE_C
#define ERRORTABLE_C
#include "ErrorTable.cpp"
#endif