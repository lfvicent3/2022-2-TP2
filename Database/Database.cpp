#include "Database.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

std::vector<Donor> Database::listDonorUsers = std::vector<Donor>();
std::vector<Receiver> Database::listReceiverUsers = std::vector<Receiver>();
std::vector<Solid> Database::listSolidResidues = std::vector<Solid>();
std::vector<Liquid> Database::listLiquidResidues = std::vector<Liquid>();
std::vector<Scheduling> Database::listScheduling = std::vector<Scheduling>();

Database::Database() {}

/**
 * @brief Responsável por criar dados ficticios no programa.
 * Exemplo:
 * - Residuos Papel, Metal e Oléo.
 * - Usuário receptor Login: receiver, password: receiver
 * - Usuário doador Login: doador, password:doador
 */
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
    this->createItem(Donor("Neymar Junior", "donor2", "donor", 123456789, "rua dos passos, 112, vicosa mg"));
    this->createItem(Donor("Isabella Swan", "donor3", "donor", 123456789, "rua dos passos, 112, vicosa mg"));
    this->createItem(Donor("Maria da Penha", "donor4", "donor", 123456789, "rua dos passos, 112, vicosa mg"));

    this->createItem(Receiver("Katia Maria", "receiver", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Vitoria Ferreira", "receiver1", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Luiz Felipe", "receiver2", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));
    this->createItem(Receiver("Julio Cocorico", "receiver3", "receiver", 1234567899, "rua dos passos, 112, vicosa mg"));

    // setando interesses,
    std::srand(std::time(nullptr));

    for (int i = 0; i < Database::listDonorUsers.size(); i++)
    {
        int num = (std::rand() % 10);
        Database::listDonorUsers[i].setResiduesInterest(num);
    }
    for (int j = 0; j < Database::listReceiverUsers.size(); j++)
    {
        int num = (std::rand() % 10);
        Database::listReceiverUsers[j].setResiduesInterest(num);
    }
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
bool Database::deuMatch(User user, int userType)
{
    if (userType == 1) // doador
    {
        for (int i = 0; i < Database::listReceiverUsers.size(); i++)
        {
            if (user.getResiduesInterest() == Database::listReceiverUsers[i].getResiduesInterest())
            {
                return true;
            }
        }
    }
    else
    { // receptor
        for (int i = 0; i < Database::listDonorUsers.size(); i++)
        {
            if (user.getResiduesInterest() == Database::listDonorUsers[i].getResiduesInterest())
            {
                return true;
            }
        }
    }

    return false;
}

void Database::findMatch(User user, int userType)
{
    int qntMatch = 0;

    if (userType == 1) // doador
    {

        for (int i = 0; i < Database::listReceiverUsers.size(); i++)
        {
            if (user.getResiduesInterest() == Database::listReceiverUsers[i].getResiduesInterest())
            {
                Receiver donor = Database::listReceiverUsers[i];
                std::cout << "\n\nID - " << donor.getId()
                          << "\nNOME: " << donor.getName();
                qntMatch++;
            }
        }
    }
    else
    { // receptor
        qntMatch = 0;
        for (int i = 0; i < Database::listDonorUsers.size(); i++)
        {
            if (user.getResiduesInterest() == Database::listDonorUsers[i].getResiduesInterest())
            {
                Donor donor = Database::listDonorUsers[i];
                std::cout << "ID - " << donor.getId()
                          << "\nNOME: " << donor.getName();
                qntMatch++;
            }
        }
    }

    if (qntMatch == 0)
    {

        std::cout << "\nDesculpe, nao ha pessoas doando esse residuo no momento :( \nTente novamente mais tarde. \n\n";
    }
    else
    {
        std::cout << "\nEba! Voce deu um Match com ao menos um usuário do sistema.";
        std::cout << "\nAgora basta agendar a coleta dos residuos e ir coletar!\n";
    }
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

int Database::searchItem(Scheduling scheduling)
{
    for (int i = 0; i < Database::listScheduling.size(); i++)
    {
        if (Database::listScheduling[i].getId() == scheduling.getId())
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

void Database::createItem(const Scheduling
                              &scheduling)
{
    Database::listScheduling.push_back(scheduling);
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

const std::vector<Scheduling> &Database::readSchedules()
{
    return Database::listScheduling;
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

void Database::updateItem(const Scheduling &scheduling)
{
    int i = Database::searchItem(scheduling);
    Database::listScheduling[i] = scheduling;
}

Database::~Database()
{
}