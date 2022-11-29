#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <cstdlib>
#include <fstream>

#include "User/Donor.h"
#include "User/Receiver.h"
#include "User/User.h"

std::list<Donor> usuariosDoadores;
std::list<Receiver> usuariosReceptores;

User autenticatedUser;

int menu()
{
    system("clear");
    std::string opSelect;
    std::cout << "\nAcesso ao sistema: \n1 - Acessar \n2 - Cadastrar\nInforme o número:";
    std::getline(std::cin, opSelect);

    try
    {
        int op = std::stoi(opSelect);
        if (op < 1 || op > 2)
        {
            throw std::invalid_argument("O valor deve ser 1 ou 2.");
        }

        return op;
    }
    catch (const std::invalid_argument &e)
    {
        if (std::string(e.what()) == "stoi")
        {
            std::cerr << "Informe apenas o digito.";
        }
        else
        {
            std::cerr << e.what();
        }
        std::cin.get();
        return menu();
    }
}

int menu1()
{
    system("clear");
    std::string opSelect;
    std::cout << "\nInforme o tipo: \n1 - Doador\n2 - Receptor\nInforme o número:";
    std::getline(std::cin, opSelect);

    try
    {
        int op = std::stoi(opSelect);
        if (op < 1 || op > 2)
        {
            throw std::invalid_argument("O valor deve ser 1 ou 2.");
        }

        return op;
    }
    catch (const std::invalid_argument &e)
    {
        if (std::string(e.what()) == "stoi")
        {
            std::cerr << "Informe apenas o digito.";
        }
        else
        {
            std::cerr << e.what();
        }

        std::cin.get();
        return menu1();
    }
}

void autentica(int op)
{
    system("clear");
    std::cout << "Logue no sistema: \n";

    std::string login;
    std::string password;

    std::cout << "Informe o usuário: ";
    std::getline(std::cin, login);

    std::cout << "Informe a senha: ";
    std::getline(std::cin, password);

    try
    {
        if (op == 1)
        {
            for (Donor donor : usuariosDoadores)
            {
                if (donor.getLogin() == login)
                {
                    if (!donor.checkPassword(password))
                    {
                        throw std::invalid_argument("Não foi possível autenticar. Verifique seu login e senha.");
                    }

                    autenticatedUser = donor;
                    return;
                }
            }

            throw std::invalid_argument("Usuário não encontrado.");
        }
        else
        {
            for (Receiver receiver : usuariosReceptores)
            {
                if (receiver.getLogin() == login)
                {
                    if (!receiver.checkPassword(password))
                    {
                        throw std::invalid_argument("Não foi possível autenticar. Verifique seu login e senha.");
                    }

                    autenticatedUser = receiver;
                    return;
                }
            }
            throw std::invalid_argument("Usuário não encontrado.");
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
        std::cin.get();
        return autentica(op);
    }
}

void cadastra(int op)
{
    system("clear");
    std::string name, login, password;

    std::cout << "Informe o Nome: ";
    std::getline(std::cin, name);

    std::cout << "Informe o Login: ";
    std::getline(std::cin, login);

    try
    {
        if (op == 1)
        {
            for (Donor donor : usuariosDoadores)
            {
                if (donor.getLogin() == login)
                {
                    throw std::invalid_argument("Usuário existente!");
                }
            }
        }
        else
        {
            for (Receiver receiver : usuariosReceptores)
            {
                if (receiver.getLogin() == login)
                {
                    throw std::invalid_argument("Usuário existente!");
                }
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
        std::cin.get();
        return cadastra(op);
    }

    std::cout << "Informe o Senha: ";
    std::getline(std::cin, password);

    if (op == 1)
    {
        Donor donor(name, login, password);
        usuariosDoadores.push_back(donor);
    }
    else
    {
        Receiver receiver(name, login, password);
        usuariosReceptores.push_back(receiver);
    }
}

int main()
{
    std::cout << "GERENCIAMENTO DE RESIDUOS";
    int op = menu();
    int op2 = menu1();

    if (op == 1)
    {
        autentica(op2);
    }
    else
    {
        cadastra(op2);
        autentica(op2);
    }

    std::cout << "Bem vindo(a), " << autenticatedUser.getName() << "!\nO que deseja fazer?\n";
    // Doações
    // Perfil
    //
}
