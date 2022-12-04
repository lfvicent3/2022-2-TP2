#ifndef RECEIVER_H
#define RECEIVER_H

#include "User.h"

class Receiver: public User
{
private:
    
public:
    Receiver();
    Receiver(std::string name, std::string login, std::string password, int document, std::string adress);
    ~Receiver();
};
#endif