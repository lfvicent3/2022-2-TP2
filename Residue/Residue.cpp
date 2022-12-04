#include "Residue.h"

Residue::Residue(std::string name, std::string help)
{
    this->name = name;
    this->help = help;
    this->id = Residue::generatedIds;

    Residue::generatedIds++;
}

int Residue::generatedIds = 0;

/*
std::string Residue::getName() const
{
    return this->name;
}
*/
std::string Residue::getHelp() const
{
    return this->help;
}

int Residue::getId(){
    return this->id;
}

std::string Residue::getName() {
    return this->name;
}

Residue::~Residue()
{
}
