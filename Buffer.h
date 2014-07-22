/******************************************//**
 * @file Buffer.h
 * @author cnsworder, cnsworder@gmail.com
 * @brief Message buffer
 **********************************************/

#ifndef __BUFFER_H__
#define __BUFFER_H__

namespace msg
{
class Buffer
{
public:
    Buffer();
    ~Buffer();

    char* data();
    size_t size();
    size_t length();
};

}//end namepsace msg

#endif //__BUFFER_H__
