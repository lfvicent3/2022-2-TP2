#include "Liquid.h"

Liquid::Liquid(std::string name, std::string help) : Residue(name, help)
{
}

std::string Liquid::getHelp() const
{
    return "Esse residuo liquido deve ser " + this->help;
}

Liquid::~Liquid() {}