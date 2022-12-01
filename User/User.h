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
    int document;
    std::list<Residue> residuesInterest;
    User(std::string name, std::string login, std::string password, int document);

public:
    User();
    std::string getName();
    int getDocument();
    std::string getLogin();
    std::list<Residue> &getResiduesInterest();
    bool checkPassword(std::string password);
    void setName(std::string name);
    void setResiudesInterest(Residue residue);

    ~User();
};
#endif