#ifndef TCPSERVER_H
#define TCPSERVER_H

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides a wrapper around UDP Sockets
////////////////////////////////////////////////////////////////////////////////////
class TCPServer
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Default Constructor
    ////////////////////////////////////////////////////////////////////////////////
    TCPServer();

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~TCPServer();

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
#endif // TCPSERVER_H