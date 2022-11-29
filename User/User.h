#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include <fstream>
#include "../Residue/Residue.h"
class User
{
protected:
    std::string name;
    std::string login;
    std::string password;
    std::list<Residue> residuesInterest;
    User(std::string name, std::string login, std::string password);

public:
    User();
    std::string getName();
    std::string getLogin();
    std::list<Residue> &getResiduesInterest();
    bool checkPassword(std::string password);
    void setName(std::string name);
    void setResiudesInterest(Residue residue);

    ~User();
};
#endif