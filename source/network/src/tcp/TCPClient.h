#ifndef TCPCLIENT_H
#define TCPCLIENT_H

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides a wrapper around UDP Sockets
////////////////////////////////////////////////////////////////////////////////////
class TCPClient
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    TCPClient();

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~TCPClient();

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief TODO
    /// \details TODO
    ////////////////////////////////////////////////////////////////////////////////
    void open();

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief TODO
    /// \details This function TODO
    ////////////////////////////////////////////////////////////////////////////////
    void close();
};
#endif // TCPCLIENT_H