#include "Scheduling.h"

int Scheduling::generatedIds = 0;

Scheduling::Scheduling(Donor donor, Receiver receiver, int idResidue, std::string pontoColeta, std::string data, std::string hora)
{
    this->donor = donor;
    this->receiver = receiver;
    this->idResidue = idResidue;
    this->pontoColeta = pontoColeta;
    this->data = data;
    this->hora = hora;

    this->id = Scheduling::generatedIds;

    Scheduling::generatedIds++;
}

Donor Scheduling::getDonor()
{
    return this->donor;
}

Receiver Scheduling::getReceiver()
{
    return this->receiver;
}

int Scheduling::getIdResidue()
{
    return this->idResidue;
}

std::string Scheduling::getData()
{
    return this->data;
}

std::string Scheduling::getHora()
{
    return this->hora;
}

std::string Scheduling::getPontoColeta()
{
    return this->pontoColeta;
}

std::string Scheduling::setPontoColeta(std::string pontoColeta)
{
    return this->pontoColeta;
}

bool Scheduling::getEffective()
{
    return this->effective;
}

void Scheduling::setEffective(bool effective)
{
    this->effective = effective;
}

int Scheduling::getId()
{
    return this->id;
}

Scheduling::~Scheduling()
{
}