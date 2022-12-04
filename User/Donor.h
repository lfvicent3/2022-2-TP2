#ifndef DONOR_H
#define DONOR_H

#include "User.h"

class Donor : public User
{
private:

public:
    Donor();
    Donor(std::string name, std::string login, std::string password, int document, std::string adress);
    ~Donor();
};

#endif