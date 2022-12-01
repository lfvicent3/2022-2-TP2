#include "User.h"

User::User() {}

User::User(std::string name, std::string login, std::string password, int document)
{
    this->name = name;
    this->login = login;
    this->password = password;
    this->document = document;

}

std::string User::getName()
{
    return this->name;
}

std::string User::getLogin()
{
    return this->login;
}

std::list<Residue> &User::getResiduesInterest()
{
    return this->residuesInterest;
}

bool User::checkPassword(std::string password)
{
    if (this->password == password)
    {
        return true;
    }

    return false;
}

void User::setName(std::string name)
{
    this->name = name;
}

void User::setResiudesInterest(Residue residue)
{
    this->residuesInterest.push_back(residue);
}

User::~User()
{
}