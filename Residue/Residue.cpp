#include "Residue.h"

Residue::Residue(std::string name, std::string help)
{
    this->name = name;
    this->help = help;
    this->id = Residue::generatedIds;

    Residue::generatedIds++;
}

int Residue::generatedIds = 0;

std::string Residue::getName()
{
    return this->name;
}

std::string Residue::getHelp() const
{
    return "Esse residuo deve ser " + this->help;
}

int Residue::getId(){
    return this->id;
}

Residue::~Residue()
{
}