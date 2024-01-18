////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: extendableError.cpp
///
/// Class Name: ExtendableError
///
/// Description: The ExtendableError class is a singleton class that CodeWeb
/// uses to
///              check for errors. This class makes calls to the Logger class
///              when an error is detected to log the error to the log file and
///              then asserts to close the application.
///
////////////////////////////////////////////////////////////////////////////////////

#include "ExtendableError.h"

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
ExtendableError* ExtendableError::getInstance(void)
{
    // --- If the Error Handler has not been initialized then
    if (nullptr == mp_extendableError)
    {
        // Initialize the Error Handler
        mp_extendableError = new (std::nothrow) ExtendableError();
        assert(mp_extendableError);
    }

    return mp_extendableError;
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
bool ExtendableError::destroyInstance(void)
{
    // --- Initialize local variables
    bool status = false;

    // --- If the Error Handler has been initialized then
    if (nullptr != mp_extendableError)
    {
        // --- Call the Error Handler Destructor
        delete mp_extendableError;
        mp_extendableError = nullptr;

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
void ExtendableError::handleError(bool isError, const char* fileName,
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
/// Name: ExtendableError
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
ExtendableError::ExtendableError(void) {}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: ~ExtendableError
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
ExtendableError::~ExtendableError(void) {}
