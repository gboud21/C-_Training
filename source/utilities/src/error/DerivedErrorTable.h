#ifndef DERIVEDERRORTABLE_H
#define DERIVEDERRORTABLE_H
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

class DerivedErrorTable : ErrorTable<GenericError::GenericErrorCode>
{
public:
    typedef std::pair<GenericError::GenericErrorCode, std::string> ErrorPair;

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Returns instance of ErrorTable
    /// \return ErrorTable
    ////////////////////////////////////////////////////////////////////////////////
    static DerivedErrorTable& getInstance(void);

private:
    DerivedErrorTable(void);

    ~DerivedErrorTable();
};

#endif // DERIVEDERRORTABLE_H

#ifndef DERIVEDERRORTABLE_C
#define DERIVEDERRORTABLE_C
#include "DerivedErrorTable.cpp"
#endif