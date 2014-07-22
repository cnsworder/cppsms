/******************************************//**
 * @file Message.h
 * @author cnsworder, cnsworder@gmail.com
 * @brief Message use udp
 **********************************************/

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#if __cplusplus < 201103
#    error "used c++11"
#endif

#if !defined(__linux) && !defined(linux) && !defined(_linux_)
#    error "only suported linux"
#endif

#include <sys/types.h>

namespace msg
{

class Host;
class Buffer;

class Message
{
public:
    Message();
    ~Message();

    bool init(int port);

    ssize_t write(const Buffer &buffer, Host host);
    ssize_t read(Buffer &buffer, Host &host);

private:

    int sockd_;
    int port_;

};//end class Message
}//end namespace

#endif //__MESSAGE_H__
