////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: errorHandler.cpp
///
/// Class Name: ErrorHandler
///
/// Description: The ErrorHandler class is a singleton class that CodeWeb uses
/// to
///              check for errors. This class makes calls to the Logger class
///              when an error is detected to log the error to the log file and
///              then asserts to close the application.
///
////////////////////////////////////////////////////////////////////////////////////

#include "ErrorHandler.h"
#include "Logger.h"

#include <assert.h>
#include <new.h>
#include <string.h>
#include <string>

////////////////////////////////////////////////////////////////////////////////
///
///                            Static Variables
///
////////////////////////////////////////////////////////////////////////////////
ErrorHandler* ErrorHandler::mp_errorHandler = nullptr;

////////////////////////////////////////////////////////////////////////////////
///
/// Name: getInstance
///
/// Description: The getInstance function returns the instance of the
///              Error Handler.
///
/// Inputs:
///    None
///
/// Outputs:
///    None
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
ErrorHandler* ErrorHandler::getInstance(void)
{
    // --- If the Error Handler has not been initialized then
    if (nullptr == mp_errorHandler)
    {
        // Initialize the Error Handler
        mp_errorHandler = new (std::nothrow) ErrorHandler();
        assert(mp_errorHandler);
    }

    return mp_errorHandler;
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: destroyInstance
///
/// Description: The destroyInstance function destroys the instance of the
///              Error Handler.
///
/// Inputs:
///    None
///
/// Outputs:
///    None
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
bool ErrorHandler::destroyInstance(void)
{
    // --- Initialize local variables
    bool status = false;

    // --- If the Error Handler has been initialized then
    if (nullptr != mp_errorHandler)
    {
        // --- Call the Error Handler Destructor
        delete mp_errorHandler;
        mp_errorHandler = nullptr;

        // --- Set the return value to true
        status = true;
    }

    return status;
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: handleError
///
/// Description: The handleError function evaluates an error condition and logs
///              an information about the error if a problem is found.
///
/// Inputs:
///    bool isError             - The error condition to be evaluated
///    const char *fileName     - The name of the file the error occured in
///    const char *functionName - The name of the function the error occured in
///    int lineNumber           - The line number the error occured on
///    ErrorCodes errorCode     - The type of error that has occured
///
/// Outputs:
///    None
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
void ErrorHandler::handleError(bool isError, const char* fileName,
                               const char* functionName,
                               unsigned int lineNumber, ErrorCodes errorCode)
{
    // --- Initialize local variables
    std::string outputMsg;

    // --- If there is an error then
    if (isError)
    {

        outputMsg = fileName;
        outputMsg.append(":");
        outputMsg.append(functionName);
        outputMsg.append(":");
        outputMsg.append(std::to_string(lineNumber));
        outputMsg.append(":");
        outputMsg.append(std::to_string(errorCode));

        // --- Log the message
        Logger::getInstance()->logMsg(&outputMsg);

        assert(false);
    }
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: ErrorHandler
///
/// Description: This is the constructor for the Error Handler.
///
/// Inputs:
///    None
///
/// Outputs:
///    None
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
ErrorHandler::ErrorHandler(void) {}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: ~ErrorHandler
///
/// Description: This is the destructor for the Error Handler.
///
/// Inputs:
///    None
///
/// Outputs:
///    None
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
ErrorHandler::~ErrorHandler(void) {}
