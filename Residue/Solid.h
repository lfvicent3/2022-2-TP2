#ifndef SOLID_H
#define SOLID_H

#include "Residue.h"
class Solid : public Residue
{
private:

public:
    Solid(std::string name, std::string help);
    virtual std::string getHelp() const override;
    ~Solid();
};
#endif