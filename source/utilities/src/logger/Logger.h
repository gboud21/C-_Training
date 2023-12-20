#ifndef LOGGER_H
#define LOGGER_H
////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: logger.h
///
/// Class Name: Logger
///
/// Description: The Logger class is a singleton class that CodeWeb uses to
///              write to a log file for debugging purposes.
///
////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>

class Logger
{
public:
    static Logger* getInstance(void);
    static bool destroyInstance(void);
    bool logMsg(std::string* msg);

private:
    Logger(void);
    ~Logger(void);

    // --- Singleton Instance of ErrorHandler
    static Logger* mp_logger;

    // --- Stream to log errors to
    std::ofstream m_myFile;

    // --- Name of the log file
    const char* m_logFileName;
};

#endif // LOGGER_H
