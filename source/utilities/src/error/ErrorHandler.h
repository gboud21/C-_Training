#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: errorHandler.h
///
/// Class Name: ErrorHandler
///
/// Description: The ErrorHandler class is a singleton class that CodeWeb uses to
///              check for errors. This class makes calls to the Logger class when
///              an error is detected to log the error to the log file and then
///              asserts to close the application.
///
////////////////////////////////////////////////////////////////////////////////////


enum ErrorCodes
{
    ERROR_ALLOCATION,
    ERROR_INVALID_WIDGET,
    ERROR_OUT_OF_BOUNDS,
    ERROR_MAX
};


class ErrorHandler
{
public:

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
    ///    ErrorHandler * - Returns the singleton instance of this class
    ///
    /// Errors:
    ///    None
    ///
    ////////////////////////////////////////////////////////////////////////////////
    static ErrorHandler *getInstance( void );

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
    ///    bool - Returns whether the function destroyed the instance of this class
    ///
    /// Errors:
    ///    None
    ///
    ////////////////////////////////////////////////////////////////////////////////
    static bool destroyInstance ( void ) ;

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
    void handleError( bool isError,
                      const char *fileName,
                      const char *functionName,
                      unsigned int lineNumber,
                      ErrorCodes errorCode );

private:

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
    ErrorHandler ( void ) ;

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
    ~ErrorHandler ( void ) ;

    ////////////////////////////////////////////////////////////////////////////////
    ///
    ///                            Member Variables
    ///
    ////////////////////////////////////////////////////////////////////////////////

    // --- Singleton Instance of ErrorHandler
    static ErrorHandler *mp_errorHandler;

};

#endif // ERRORHANDLER_H
