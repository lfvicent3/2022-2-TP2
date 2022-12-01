#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "User/Donor.h"
#include "User/Receiver.h"
#include "User/User.h"
#include "Residue/Solid.h"
#include "Residue/Liquid.h"

// para compilar g++ **/**.cpp main.cpp

std::list<Donor> usuariosDoadores;
std::list<Receiver> usuariosReceptores;

User autenticatedUser;

void criarResiduo()
{
    std::vector<Solid> solidos;
    std::vector<Liquid> liquidos;
}

int menu()
{
    system("clear");
    std::string opSelect;
    std::cout << "\nAcesso ao sistema: \n1 - Acessar \n2 - Cadastrar\nInforme o numero:";
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
    std::cout << "\nInforme o tipo: \n1 - Doador\n2 - Receptor\nInforme o numero:";
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

    std::cout << "Informe o usuario: ";
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
                        throw std::invalid_argument("Nao foi possível autenticar. Verifique seu login e senha.");
                    }

                    autenticatedUser = donor;
                    return;
                }
            }

            throw std::invalid_argument("Usuario nao encontrado.");
        }
        else
        {
            for (Receiver receiver : usuariosReceptores)
            {
                if (receiver.getLogin() == login)
                {
                    if (!receiver.checkPassword(password))
                    {
                        throw std::invalid_argument("Nao foi possível autenticar. Verifique seu login e senha.");
                    }

                    autenticatedUser = receiver;
                    return;
                }
            }
            throw std::invalid_argument("Usuario nao encontrado.");
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
    std::string document;

    std::cout << "Informe o Nome: ";
    std::getline(std::cin, name);

    std::cout << "Informe o Login: ";
    std::getline(std::cin, login);

    std::cout << "Informe a Senha: ";
    std::getline(std::cin, password);

    std::cout << "Informe o Numero do seu documento CPF ou CNPJ (APENAS NUMEROS): ";
   std::getline(std::cin, document);

    // documento

    try
    {
        if (op == 1)
        {
            for (Donor donor : usuariosDoadores)
            {
                if (donor.getLogin() == login)
                {
                    throw std::invalid_argument("Usuario existente!");
                }
            }
        }
        else
        {
            for (Receiver receiver : usuariosReceptores)
            {
                if (receiver.getLogin() == login)
                {
                    throw std::invalid_argument("Usuario existente!");
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

    if (op == 1)
    {
        Donor donor(name, login, password, std::stoi(document));
        usuariosDoadores.push_back(donor);
    }
    else
    {
        Receiver receiver(name, login, password,std::stoi(document));
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

    std::cout << "\n Bem vindo(a), " << autenticatedUser.getName() << "!\nO que deseja fazer?\n\n";

    if (op2 == 1)
    {
        int resposta;
        // Se o usuario for receiver:
        std::cout << "1 - Cadastrar residuos \n 2 - Cadastrar ponto de coleta \n 3- Verificar agendamentos de coleta \n Escreva o numero da opcao: ";
        std::cin >> resposta;

        if (resposta == 1)
        {
            // cadastrar residuos
            int r2;
            std::cout << "===== CADASTRAR RESIDUOS ===== \n 1 - Residuo Solido \n 2 - Residuo Liquido";
            std::cin >> r2;

            if (r2 == 1)
            {
                // cadastrar residuos solidos
            }
            else if (r2 == 2)
            {
                // cadastrar residuos liquidos
            }
        }
        else if (resposta == 2)
        {
            // cadastrar ponto de coleta
            std::cout << "===== CADASTRAR PONTO DE COLETA ===== \n";
            
        }
        else if (resposta == 3)
        {
            // verificar agendamentos de coleta
            std::cout << "===== CADASTRAR PONTO DE COLETA ===== \n";
        }
    }

    // se resp for == 1 abre outro menu (solido ou liquido?)
    // cadastrar residuo solido
    //  vou cadastrar os residuos dentro de um vector;

    // Se o usuario for donor:
    std::cout << "1 - Cadastrar residuos \n 2 - Agendar horario de coleta";
    // se op2 == 2;

    // Doações
    // Perfil
    //
}
