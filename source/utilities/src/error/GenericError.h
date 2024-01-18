#ifndef GENERICERROR_H
#define GENERICERROR_H
////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: genericError.h
///
/// Class Name: GenericError
///
/// Description: The GenericError class is a singleton class that CodeWeb
/// uses to
///              check for errors. This class makes calls to the Logger class
///              when an error is detected to log the error to the log file and
///              then asserts to close the application.
///
////////////////////////////////////////////////////////////////////////////////////

#include <string>

class GenericError
{
public:
    enum GenericErrorCode
    {
        NO_ERROR,
        INVALID_ARGUMENT,
        ALREADY_EXISTS,
        FAILED_ALLOCATION,
        OUT_OF_BOUNDS,
        ERROR_MAX
    };

    enum GenericReaonCode
    {
        NO_REASON,
        REASON_1,
        REASON_2,
        REASON_3,
        REASON_4,
        REASON_MAX
    };

    enum Severity
    {
        DEBUG,
        INFO,
        NOTIC,
        WARNING,
        ERROR,
        CRITICAL,
        ALERT,
        EMERGENCY,
        SEVERITY_MAX
    };

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    GenericError(void);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Paramaterized Constructor
    ////////////////////////////////////////////////////////////////////////////////
    GenericError(const GenericErrorCode error, const GenericReaonCode reason,
                 const Severity severity);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~GenericError();

    void setError(const GenericErrorCode error);
    GenericErrorCode getError() const;

    void setReason(const GenericReaonCode reason);
    GenericReaonCode getReason() const;

    void setSeverity(const Severity severity);
    Severity getSeverity() const;

    void getErrorString(std::string& errorString);

    bool isOk();

private:
    GenericErrorCode m_error;
    GenericReaonCode m_reason;
    Severity m_severity;
};

#endif // GENERICERROR_H
