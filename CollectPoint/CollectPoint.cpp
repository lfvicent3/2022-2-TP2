#include "CollectPoint.h"

CollectPoint::CollectPoint() {}
CollectPoint::CollectPoint(std::string line1, std::string line2, std::string cep, std::string referencia)
{
    this->line1 = line1;
    this->line2 = line2;
    this->cep = cep;
    this->reference = reference;
}

std::string CollectPoint::getLine1()
{
    return this->line1;
}

std::string CollectPoint::getLine2()
{
    return this->line2;
}

std::string CollectPoint::getCep()
{
    return this->cep;
}

std::string CollectPoint::getReference()
{
    return this->reference;
}

CollectPoint::~CollectPoint()
{
}