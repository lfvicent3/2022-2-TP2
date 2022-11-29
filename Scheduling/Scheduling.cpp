#include "Scheduling.h"

Scheduling::Scheduling(Donor donor, Receiver receiver, std::list<Residue> residues, tm collectDate, CollectPoint collectPoint)
{
    this->donor = donor;
    this->receiver = receiver;
    this->residues = residues;
    this->collectDate = collectDate;
    this->collectPoint = collectPoint;
}

Donor Scheduling::getDonor()
{
    return this->donor;
}

Receiver Scheduling::getReceiver()
{
    return this->receiver;
}

std::list<Residue> Scheduling::getResidues()
{
    return this->residues;
}

tm Scheduling::getCollectDate()
{
    return this->collectDate;
}

CollectPoint Scheduling::getCollectPoint()
{
    return this->collectPoint;
}

bool Scheduling::getEffective()
{
    return this->effective;
}

void Scheduling::setEffective(bool effective)
{
    this->effective = effective;
}