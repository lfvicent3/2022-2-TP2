#ifndef DATABASE_H
#define DABATASE_H

#include <vector>
#include "../User/Donor.h"
#include "../User/Receiver.h"
#include "../Residue/Solid.h"
#include "../Residue/Liquid.h"

class Database
{
private:
    static std::vector<Donor> listDonorUsers;
    static std::vector<Receiver> listReceiverUsers;
    static std::vector<Solid> listSolidResidues;
    static std::vector<Liquid> listLiquidResidues;

    int searchItem(Donor donor);
    int searchItem(Receiver receiver);
    int searchItem(Solid solid);
    int searchItem(Liquid liquid);

public:
    Database();
    void createItem(const Donor &donor);
    void createItem(const Receiver &receiver);
    void createItem(const Solid &solid);
    void createItem(const Liquid &liquid);
    const std::vector<Donor> &readDonorUsers();
    const std::vector<Receiver> &readReceiverUsers();
    const std::vector<Solid> &readSolidResidues();
    const std::vector<Liquid> &readLiquidResidues();
    void updateItem(const Donor &donor);
    void updateItem(const Receiver &receiver);
    void updateItem(const Solid &solid);
    void updateItem(const Liquid &liquid);
    void deleteItem(Donor donor);
    void deleteItem(Receiver receiver);
    void deleteItem(Solid solid);
    void deleteItem(Liquid liquid);

    ~Database();
};

#endif