#ifndef AUTENTICATE_H
#define AUTENTICATE_H

#include <string>
#include <exception>

#include "../Database/Database.h"
#include "../User/User.h"
#include "../User/Donor.h"
#include "../User/Receiver.h"

class Autenticate
{
private:
    Database db;
    bool isUser();

public:
    Autenticate();
    User login(std::string login, std::string password, int op);
    void cadastro(std::string name, std::string login, std::string password, int document, int op);
    ~Autenticate();
};

#endif