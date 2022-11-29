#ifndef LIQUID_H
#define LIQUID_H

#include "Residue.h"

class Liquid : public Residue
{
private:

public:
    Liquid(std::string name, std::string help);
    virtual std::string getHelp() const override;
    ~Liquid();
};
#endif