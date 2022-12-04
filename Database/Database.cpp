#include "Database.h"
#include <iostream>

std::vector<Donor> Database::listDonorUsers = std::vector<Donor>();
std::vector<Receiver> Database::listReceiverUsers = std::vector<Receiver>();
std::vector<Solid> Database::listSolidResidues = std::vector<Solid>();
std::vector<Liquid> Database::listLiquidResidues = std::vector<Liquid>();


Database::Database() {}

void Database::fakePopulate()
{
    // solidos
    this->createItem(Solid("Papel", "Para o descarte correto de papeis, jogue-os na lixeira azul ou de reciclaveis."));
    this->createItem(Solid("Metal", "Para o descarte correto de metais, jogue-os na lixeira amarela ou de reciclaveis."));
    this->createItem(Solid("Plastico", "Para o descarte correto de plasticos, jogue-os na lixeira vermelha ou de reciclaveis."));

    // liquidos

    this->createItem(Liquid("Oleo de cozinha", "Para o descarte correto de oleo de cozinha, deve-se armazenar em um recipiente e levar em um ponto de coleta para ser reciclado."));

    // pessoas fake

    this->createItem(Donor("Cleiton Baiano", "donor", "donor", 123456789, "rua dos passos, 112, vicosa mg"));
    this->createItem(Donor("Neymar Junior", "donor", "donor", 123456789, "rua dos passos, 112, vicosa mg"));
    this->createItem(Donor("Isabella Swan", "donor", "donor", 123456789, "rua dos passos, 112, vicosa mg"));
    this->createItem(Donor("Maria da Penha", "donor", "donor", 123456789, "rua dos passos, 112, vicosa mg"));

    this->createItem(Receiver("Katia Maria", "receiver", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Vitoria Ferreira", "receiver", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Luiz Felipe", "receiver", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Julio Cocorico", "receiver", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));

    // setando interesses
}

void Database::printItem()
{

    std::cout << "====== SOLIDOS ====== \n";
    for (int i = 0; i < Database::listSolidResidues.size(); i++)
    {
        std::cout << "ID: " << Database::listSolidResidues[i].getId() << " - " << Database::listSolidResidues[i].getName() << "\n";
        std::cout << Database::listSolidResidues[i].getHelp() << "\n";
        std::cout << std::endl;
    }
    std::cout << "====== LIQUIDOS ====== \n";
    for (int i = 0; i < Database::listLiquidResidues.size(); i++)
    {
        std::cout << "ID: " << Database::listLiquidResidues[i].getId() << " - " << Database::listLiquidResidues[i].getName() << std::endl;
        std::cout << Database::listLiquidResidues[i].getHelp() << std::endl;
        std::cout << std::endl;
    }
}

void Database::setDonorInterest(User user, int idResidue)
{

    int idInterest;

    for (int j = 0; j < Database::listDonorUsers.size(); j++)
    {
        if (Database::listDonorUsers[j].getId() == user.getId())
        {

            for (int i = 0; i < Database::listSolidResidues.size(); i++)
            {
                if (Database::listSolidResidues[i].getId() == idResidue)
                {
                    idInterest = Database::listSolidResidues[i].getId();
                    Database::listDonorUsers[j].setResiduesInterest(idInterest);

                    
                }
            }
            for (int i = 0; i < Database::listLiquidResidues.size(); i++)
            {
                if (Database::listLiquidResidues[i].getId() == idResidue)
                {
                    idInterest = Database::listLiquidResidues[i].getId();
                    Database::listDonorUsers[j].setResiduesInterest(idInterest);
                }
            }

            std::cout << listDonorUsers[j].getResiduesInterest();
        }
    }
}

void Database::setReceiverInterest(User user, int idResidue)
{
    int idInterest;

    for (int j = 0; j < Database::listReceiverUsers.size(); j++)
    {
        if (Database::listReceiverUsers[j].getId() == user.getId())
        {

            for (int i = 0; i < Database::listSolidResidues.size(); i++)
            {
                if (Database::listSolidResidues[i].getId() == idResidue)
                {
                    idInterest = Database::listSolidResidues[i].getId();
                    Database::listReceiverUsers[j].setResiduesInterest(idInterest);
                }
            }
            for (int i = 0; i < Database::listLiquidResidues.size(); i++)
            {
                if (Database::listLiquidResidues[i].getId() == idResidue)
                {
                    
                    idInterest = Database::listLiquidResidues[i].getId();
                    Database::listReceiverUsers[j].setResiduesInterest(idInterest);

                    
                }
            }
        }
    
    }

    
}

// procurando matchs 





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



Database::~Database()
{
}