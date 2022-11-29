#include "Residue.h"

Residue::Residue(std::string name, std::string help)
{
    this->name = name;
    this->help = help;
}

std::string Residue::getName()
{
    return this->name;
}

std::string Residue::getHelp() const
{
    return "Esse residuo deve ser " + this->help;
}

Residue::~Residue()
{
}