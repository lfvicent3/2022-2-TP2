#include "User.h"

User::User() {}

int User::generatedIds = 0;

User::User(std::string name, std::string login, std::string password, int document, std::string adress)
{
    this->name = name;
    this->login = login;
    this->password = password;
    this->document = document;
    this->adress = adress;
    this->id = User::generatedIds;

    User::generatedIds++;
}

std::string User::getName()
{
    return this->name;
}

std::string User::getLogin()
{
    return this->login;
}

std::string User::getAdress()
{
    return this->adress;
}

std::vector<Residue> &User::getResiduesInterest()
{
    return this->residuesInterest;
}

int User::getId()
{
    return this->id;
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

void User::setAdress(std::string adress)
{
    this->adress = adress;
}


void User::setResiduesInterest(Residue residue)
{
    this->residuesInterest.push_back(residue);
}

int User::getDocument()
{
    return this->document;
}

User::~User()
{
}