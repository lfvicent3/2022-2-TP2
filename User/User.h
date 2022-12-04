#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <fstream>
#include "../Residue/Residue.h"
class User
{
private:
    static int generatedIds;
    int id;

protected:
    std::string name;
    std::string login;
    std::string password;
    std::string adress;
    int document;
    int residuesInterest;
    User(std::string name, std::string login, std::string password, int document, std::string adress);

public:
    User();
    std::string getName();
    int getDocument();
    std::string getLogin();
    std::string getAdress();
    int &getResiduesInterest();
    int getId();
    bool checkPassword(std::string password);
    void setName(std::string name);
    void setResiduesInterest(int idResidue);
    void setAdress(std::string adress);


    ~User();
};
#endif