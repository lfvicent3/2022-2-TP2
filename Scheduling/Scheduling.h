#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <list>
#include <ctime>

#include "../User/Donor.h"
#include "../User/Receiver.h"
#include "../CollectPoint/CollectPoint.h"
#include "../Residue/Residue.h"

class Scheduling
{
private:
    Donor donor;
    Receiver receiver;
    int idResidue;
    std::string data;
    std::string hora;
    std::string pontoColeta;
    bool effective;
    static int generatedIds;
    int id;

public:
    Scheduling(Donor donor, Receiver receiver, int idResidue, std::string pontoColeta, std::string data, std::string hora);
    Donor getDonor();
    Receiver getReceiver();
    int getIdResidue();
    std::string getData();
    std::string getHora();
    std::string setPontoColeta(std::string pontoColeta);
    std::string getPontoColeta();
    bool getEffective();
    void setEffective(bool effective);     
    int getId();                  
    ~Scheduling();
};


#endif