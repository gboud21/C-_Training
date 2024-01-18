#ifndef EXTENDABLEERROR_H
#define EXTENDABLEERROR_H
////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: extendableError.h
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

#include "GenericError.h"

template <typename errorCode, typename reasonCode, class Lookup>
class ExtendableError
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    ExtendableError(void);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~ExtendableError();

    GenericError& getGenericError();

private:
    GenericError m_genericError;
};

#endif // EXTENDABLEERROR_H

#ifndef EXTENDABLEERROR_CPP
#define EXTENDABLEERROR_CPP
#include "ExtendableError.cpp"
#endif