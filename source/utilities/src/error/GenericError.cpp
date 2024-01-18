////////////////////////////////////////////////////////////////////////////////////
///
/// File Name: genericError.cpp
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

#include "GenericError.h"

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
GenericError::GenericError(void)
    : m_error(GenericErrorCode::ERROR_MAX),
      m_reason(GenericReaonCode::REASON_MAX), m_severity(Severity::SEVERITY_MAX)
{
}

////////////////////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
////////////////////////////////////////////////////////////////////////////////
GenericError::GenericError(const GenericErrorCode error,
                           const GenericReaonCode reason,
                           const Severity severity)
    : m_error(error), m_reason(reason), m_severity(severity)
{
}

//////////////////////////////////////////////////////////////////
/// GenericError::~GenericError()
//////////////////////////////////////////////////////////////////
GenericError::~GenericError(void) {}

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
void GenericError::setError(const GenericErrorCode error) { m_error = error; }

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
GenericError::GenericErrorCode GenericError::getError() const
{
    return m_error;
}

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
void GenericError::setReason(const GenericReaonCode reason)
{
    m_reason = reason;
}

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
GenericError::GenericReaonCode GenericError::getReason() const
{
    return m_reason;
}

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
void GenericError::setSeverity(const Severity severity)
{
    m_severity = severity;
}

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
GenericError::Severity GenericError::getSeverity() const { return m_severity; }

//////////////////////////////////////////////////////////////////
/// GenericError::GenericError()
//////////////////////////////////////////////////////////////////
void GenericError::getErrorString(std::string& errorString) {}

bool GenericError::isOk() { return m_error == GenericErrorCode::NO_ERROR; }
