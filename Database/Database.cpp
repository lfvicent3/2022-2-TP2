#include "Database.h"

std::vector<Donor> Database::listDonorUsers = std::vector<Donor>();
std::vector<Receiver> Database::listReceiverUsers = std::vector<Receiver>();
std::vector<Solid> Database::listSolidResidues = std::vector<Solid>();
std::vector<Liquid> Database::listLiquidResidues = std::vector<Liquid>();
std::vector<CollectPoint> Database::listCollectPoint = std::vector<CollectPoint>();

Database::Database() {}

void Database::fakePopulate()
{

}

int Database::searchItem(Donor donor)
{
    for (int i = 0; i < Database::listDonorUsers.size(); i++)
    {
        if (Database::listDonorUsers[i].getId() == donor.getId())
        {
            return i;
        }
    }

    return -1;
}
int Database::searchItem(Receiver receiver)
{
    for (int i = 0; i < Database::listReceiverUsers.size(); i++)
    {
        if (Database::listDonorUsers[i].getId() == receiver.getId())
        {
            return i;
        }
    }

    return -1;
}
int Database::searchItem(Solid solid)
{
    for (int i = 0; i < Database::listSolidResidues.size(); i++)
    {
        if (Database::listDonorUsers[i].getId() == solid.getId())
        {
            return i;
        }
    }

    return -1;
}
int Database::searchItem(Liquid liquid)
{
    for (int i = 0; i < Database::listLiquidResidues.size(); i++)
    {
        if (Database::listDonorUsers[i].getId() == liquid.getId())
        {
            return i;
        }
    }

    return -1;
}

int Database::searchItem(CollectPoint collectPoint)
{
    for (int i = 0; i < Database::listCollectPoint.size(); i++)
    {
        if (Database::listCollectPoint[i].getId() == collectPoint.getId())
        {
            return i;
        }
    }

    return -1;
}

void Database::createItem(const Donor &donor)
{
    Database::listDonorUsers.push_back(donor);
}

void Database::createItem(const Receiver &receiver)
{
    Database::listReceiverUsers.push_back(receiver);
}

void Database::createItem(const Solid &solid)
{
    Database::listSolidResidues.push_back(solid);
}

void Database::createItem(const Liquid &liquid)
{
    Database::listLiquidResidues.push_back(liquid);
}

void Database::createItem(const CollectPoint &collectPoint)
{
    Database::listCollectPoint.push_back(collectPoint);
}

const std::vector<Donor> &Database::readDonorUsers()
{
    return Database::listDonorUsers;
}

const std::vector<Receiver> &Database::readReceiverUsers()
{
    return Database::listReceiverUsers;
}

const std::vector<Solid> &Database::readSolidResidues()
{
    return Database::listSolidResidues;
}

const std::vector<Liquid> &Database::readLiquidResidues()
{
    return Database::listLiquidResidues;
}

const std::vector<CollectPoint> &Database::readCollectPoints()
{
    return Database::listCollectPoint;
}

void Database::updateItem(const Donor &donor)
{
    int i = Database::searchItem(donor);
    Database::listDonorUsers[i] = donor;
}
void Database::updateItem(const Receiver &receiver)
{
    int i = Database::searchItem(receiver);
    Database::listReceiverUsers[i] = receiver;
}
void Database::updateItem(const Solid &solid)
{
    int i = Database::searchItem(solid);
    Database::listSolidResidues[i] = solid;
}

void Database::updateItem(const Liquid &liquid)
{
    int i = Database::searchItem(liquid);
    Database::listLiquidResidues[i] = liquid;
}

void Database::updateItem(const CollectPoint &collectPoint)
{
    int i = Database::searchItem(collectPoint);
    Database::listCollectPoint[i] = collectPoint;
}

Database::~Database()
{
}