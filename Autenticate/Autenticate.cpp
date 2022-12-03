#include "Autenticate.h"

Autenticate::Autenticate()
{
    this->db = Database();
}

User Autenticate::login(std::string login, std::string password, int op)
{
    if (op == 1)
    {
        for (Donor donor : this->db.readDonorUsers())
        {
            if (donor.getLogin() == login)
            {
                if (!donor.checkPassword(password))
                {
                    throw std::invalid_argument("Nao foi possível autenticar. Verifique seu login e senha.");
                }

                return donor;
            }
        }

        throw std::invalid_argument("Usuario nao encontrado. Cadastre-se!");
    }
    else
    {
        for (Receiver receiver : this->db.readReceiverUsers())
        {
            if (receiver.getLogin() == login)
            {
                if (!receiver.checkPassword(password))
                {
                    throw std::invalid_argument("Nao foi possível autenticar. Verifique seu login e senha.");
                }

                return receiver;
            }
        }

        throw std::invalid_argument("Usuario nao encontrado. Cadastre-se!");
    }
}

void Autenticate::cadastro(std::string name, std::string login, std::string password, int document, int op)
{
    if (op == 1)
    {
        for (Donor donor : this->db.readDonorUsers())
        {
            if (donor.getLogin() == login)
            {
                throw std::invalid_argument("Usuario existente! Tente com um diferente.");
            }
        }

        this->db.createItem(Donor(name, login, password, document));
    }
    else
    {
        for (Receiver receiver : this->db.readReceiverUsers())
        {
            if (receiver.getLogin() == login)
            {
                throw std::invalid_argument("Usuario existente!");
            }
        }

        this->db.createItem(Receiver(name, login, password, document));
    }
}

Autenticate::~Autenticate()
{
}
