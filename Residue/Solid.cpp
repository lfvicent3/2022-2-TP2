#include "Solid.h"

Solid::Solid(std::string name, std::string help) : Residue(name, help) {}

std::string Solid::getHelp() const
{
    return "Esse residuo solido deve ser " + this->help;
}

Solid::~Solid() {}