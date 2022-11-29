#ifndef RESIDUE_H
#define RESIDUE_H

#include <string>

class Residue
{
protected:
    std::string name;
    std::string help;

public:
    Residue(std::string name, std::string help);
    std::string getName();
    virtual std::string getHelp() const;
    ~Residue();
};
#endif