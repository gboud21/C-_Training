////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: logger.cpp
///
/// Class Name: Logger
///
/// Description: The Logger class is a singleton class that CodeWeb uses to
///              write to a log file for debugging purposes.
///
////////////////////////////////////////////////////////////////////////////////////
///
#include "Logger.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
///
///                            Static Variables
///
////////////////////////////////////////////////////////////////////////////////
Logger *Logger::mp_logger = nullptr;

////////////////////////////////////////////////////////////////////////////////
///
/// Name: getInstance
///
/// Description: The getInstance function returns the instance of the
///              Logger.
///
/// Inputs:
///    None
///
/// Outputs:
///    Logger * - Returns the singleton instance of this class
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
Logger *Logger::getInstance ( void )
{
    // --- If the Error Handler has not been initialized then
    if( nullptr == mp_logger )
    {
        // Initialize the Error Handler
        mp_logger = new (std::nothrow) Logger();
    }

    return mp_logger;
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
///    bool - Returns whether the function destroyed the instance of this class
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
bool Logger::destroyInstance ( void )
{
    // --- Initialize local variables
    bool status = false;

    // --- If the Logger has been initialized then
    if( nullptr != mp_logger )
    {
        // --- Call the Logger Destructor
        delete mp_logger;
        mp_logger = nullptr;

        // --- Set the return value to true
        status = true;
    }

    return status;
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: logMsg
///
/// Description: The logMsg function logs a message to the log file.
///
/// Inputs:
///    std::string *msg   - The message to be written to the log file
///
/// Outputs:
///    bool - Returns whether the message was successfully logged
///
/// Errors:
///    None
///
////////////////////////////////////////////////////////////////////////////////
bool Logger::logMsg ( std::string *msg )
{
    std::cout << "logMsg" << std::endl;
    // --- Initialize local variables
    std::string outputMsg;
    bool status = true;
    std::time_t currentTime = std::time( nullptr );
    outputMsg = std::asctime( std::localtime( &currentTime ) );

    // --- Save the log to the outputMsg
    outputMsg.append( ":" );
    outputMsg.append( *msg );

    // --- If the file is open then
    if( m_myFile.is_open() )
    {
        std::cout << "is_open" << outputMsg << std::endl;
        // --- Write the message to the log file
        m_myFile.write( outputMsg.c_str(), outputMsg.size() );
        m_myFile.flush();
        
        // --- If the logging failed then
        if( m_myFile.bad() )
        {
            std::cout << "bad" << std::endl;
            // --- Set the status to false
            status = false;
        }
    }

    return status;
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: Logger
///
/// Description: This is the constructor for the Logger.
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
Logger::Logger ( void ) : m_logFileName("LogPickIt.txt")
{
    // --- Open the log file
    m_myFile.open( m_logFileName, std::ios::in | std::ios::app );
}

////////////////////////////////////////////////////////////////////////////////
///
/// Name: ~Logger
///
/// Description: This is the destructor for the Logger.
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
Logger::~Logger ( void )
{
    // --- Close the log file
    m_myFile.close();
}
