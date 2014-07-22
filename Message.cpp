/******************************************//**
 * @file Message.cpp
 * @author cnsworder, cnsworder@gmail.com
 * @brief Message use udp
 **********************************************/

#include "Message.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Host.h"
#include "Buffer.h"

namespace msg
{

Message::Message()
{
}

Message::~Message()
{
    if (sockd_ > 0) {
        close(sockd_);
    }
}

bool Message::init(int port)
{
    port_ = port;
    sockd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockd_ <= 0) {
        return false;
    }
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sockd_, (sockaddr *)&addr, sizeof(sockaddr)) != 0) {
        return false;
    }
    int opts = fcntl(sockd_, F_GETFL);
    opts = opts | ~O_NONBLOCK;
    fcntl(sockd_, F_SETFL, opts);
    timeval tme = {6, 0};
    setsockopt(sockd_, SOL_SOCKET, SO_SNDTIMEO, (void *)&tme, sizeof(timeval));
    setsockopt(sockd_, SOL_SOCKET, SO_RCVTIMEO, (void *)&tme, sizeof(timeval));

    return true;
}

ssize_t Message::write(const Buffer &buffer, Host host)
{
    sockaddr addr = host.addr();
    return sendto(sockd_, buffer.data(), buffer.length(), 0, &addr, sizeof(sockaddr));
}

ssize_t Message::read(Buffer &buffer, Host &host)
{
    sockaddr addr;
    socklen_t sockLen = sizeof(sockaddr);
    return recvfrom(sockd_, buffer.data(), buffer.size(), 0, &addr, &sockLen);
}

}//end namespace msg
