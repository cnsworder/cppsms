/******************************************//**
 * @file Host.h
 * @author cnsworder, cnsworder@gmail.com
 * @brief Host struct define
 **********************************************/

#ifndef __HOST_H__
#define __HOST_H__

#include <string>
#include <sys/socket.h>

namespace msg
{
class Host
{
public:
    Host();
    Host(std::string ip, int port);
    Host(Host &host);
    ~Host();

    Host& operator =(Host &host);
    
    std::string ip() const;
    int port() const;

    sockaddr addr();

private:
    std::string ip_;
    int port_;
};//end class Host
}//end namespace msg
#endif //__HOST_H__
