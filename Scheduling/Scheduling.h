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
    std::list<Residue> residues;
    tm collectDate;
    CollectPoint collectPoint;
    bool effective;

public:
    Scheduling(Donor donor, Receiver receiver, std::list<Residue> residues, tm collectDate, CollectPoint collectPoint);
    Donor getDonor();
    Receiver getReceiver();
    std::list<Residue> getResidues();
    tm getCollectDate();
    CollectPoint getCollectPoint();
    bool getEffective();
    void setEffective(bool effective);                       
    ~Scheduling();
};


#endif