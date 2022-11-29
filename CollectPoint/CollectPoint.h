#ifndef COLLECTPOINT_H
#define COLLECTPOINT_H

#include <string>

class CollectPoint
{
private:
    std::string line1;
    std::string line2;
    std::string cep;
    std::string reference;

public:
    CollectPoint();
    CollectPoint(std::string line1, std::string line2, std::string cep, std::string referencia);
    std::string getLine1();
    std::string getLine2();
    std::string getCep();
    std::string getReference();

    ~CollectPoint();
};

#endif