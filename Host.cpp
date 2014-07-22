/******************************************//**
 * @file Host.cpp
 * @author cnsworder, cnsworder@gmail.com
 * @brief Host struct define
 **********************************************/
#include "Host.h"

#include <netinet/in.h>
#include <arpa/inet.h>

namespace msg
{

Host::Host()
{}

Host::Host(std::string ip, int port)
{
    ip_ = ip;
    port_ = port;
}

Host::Host(Host &host)
{
    this->ip_ = host.ip_;
    this->port_ = host.port_;
}

Host::~Host()
{
}

Host& Host::operator =(Host &host)
{
    this->port_ = host.port_;
    this->ip_ = host.ip_;
    return *this;
}


std::string Host::ip() const
{
    return ip_;
}

int Host::port() const
{
    return port_;
}

sockaddr Host::addr()
{
    sockaddr resultAddr;
    resultAddr.sa_family = AF_INET;
    ((sockaddr_in *)&resultAddr)->sin_addr.s_addr = inet_addr(ip_.c_str());
    ((sockaddr_in *)&resultAddr)->sin_port = htons(port_);
    return resultAddr;
}

}//end namespce msg
