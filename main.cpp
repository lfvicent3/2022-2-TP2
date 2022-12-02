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
    std::cout << "==== GERENCIAMENTO DE RESIDUOS ====";
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

    std::cout << "================\n\nBem vindo(a), " << autenticatedUser.getName() << "!\nO que deseja fazer?\n\n";

    if (op2 == 1)
    {
        int resposta;
        // Se o usuario for receiver:
        std::cout << " 1 - Cadastrar residuos \n 2 - Cadastrar ponto de coleta \n 3- Verificar agendamentos de coleta \n Escreva o numero da opcao: ";
        std::cin >> resposta;

        if (resposta == 1)
        {
            // cadastrar residuos
            int r2;
            std::cout << "===== CADASTRAR RESIDUOS ===== \n 1 - Residuo Solido \n 2 - Residuo Liquido \n Escreva o numero da opcao: ";
            std::cin >> r2;

            if (r2 == 1)
            {
                std::string nome_residuo;
                std::string descarte_residuo;
                // cadastrar residuos solidos

                std::cout << "===== RESIDUOS SOLIDOS ===== \n";

                std::cout << "Nome do residuo: \n";
                std::getline(std::cin, nome_residuo);

                std::cout << "Descreva a forma correta de descarte do residuo " << nome_residuo << ": ";
                std::getline(std::cin, descarte_residuo);




            }
            else if (r2 == 2)
            {
                // cadastrar residuos liquidos
                std::string nome_residuo;
                std::string descarte_residuo;
                // cadastrar residuos solidos

                std::cout << "===== RESIDUOS LIQUIDOS ===== \n";
                std::cout << "Nome do residuo: ";
                std::getline(std::cin, nome_residuo);
                std::cout << "Descreva a forma correta de descarte do residuo " << nome_residuo << ": ";
                std::getline(std::cin, descarte_residuo);
            }
        }
        else if (resposta == 2)
        {
            std::string nome_rua;
            std::string nome_bairro;
            std::string cep;
            std::string referencia;
            // cadastrar ponto de coleta
            std::cout << "===== CADASTRAR PONTO DE COLETA ===== \n";
            std::cout << "Insira os dados de localizaçao: \n Rua: ";
            std::getline(std::cin, nome_rua);
            std::cout << "\nBairro: ";
            std::getline(std::cin, nome_bairro);
            std::cout << "\nCEP: ";
            std::getline(std::cin, cep);
            std::cout << "\nPonto de referencia: ";
            std::getline(std::cin, referencia);

            
        }
        else if (resposta == 3)
        {
            std::string data;
            std::string horario;
            // verificar agendamentos de coleta
            std::cout << "===== AGENDAMENTO DE COLETA ===== \n";
            std::cout << "Insira o dia e o horario ideal para voce realizar essa coleta: \n";
            std::cout << "Dia (DD/MM/AAAA): ";
            std::getline (std::cin, data);
            std::cout<< "\n Horario (HH:MM): ";
            std::getline (std::cin, horario);

        }
    }

// DOADOR 

    if (op2==2) {
        int resposta;
        // Se o usuario for donor:
        std::cout << "1 - Cadastrar residuos \n 2 - Cadastrar ponto de coleta \n 3- Agendar coleta \n Escreva o numero da opcao: ";
        std::cin >> resposta;

        if (resposta == 1)
        {
            // cadastrar residuos
            int r2;
            std::cout << "===== CADASTRAR RESIDUOS ===== \n 1 - Residuo Solido \n 2 - Residuo Liquido";
            std::cin >> r2;

            if (r2 == 1)
            {
                std::string nome_residuo;
                std::string descarte_residuo;
                // cadastrar residuos solidos

                std::cout << "===== RESIDUOS SOLIDOS ===== \n";
                std::cout << "Nome do residuo: ";
                std::getline(std::cin, nome_residuo);
                std::cout << "Descreva a forma correta de descarte do residuo " << nome_residuo << ": ";
                std::getline(std::cin, descarte_residuo);



            }
            else if (r2 == 2)
            {
                // cadastrar residuos liquidos
                std::string nome_residuo;
                std::string descarte_residuo;

                std::cout << "===== RESIDUOS LIQUIDOS ===== \n";
                std::cout << "Nome do residuo: ";
                std::getline(std::cin, nome_residuo);
                std::cout << "Descreva a forma correta de descarte do residuo " << nome_residuo << ": ";
                std::getline(std::cin, descarte_residuo);
            }
        }
        else if (resposta == 2)
        {
            std::string nome_rua;
            std::string nome_bairro;
            std::string cep;
            std::string referencia;
            // cadastrar ponto de coleta
            std::cout << "===== CADASTRAR PONTO DE COLETA ===== \n";
            std::cout << "Insira os dados de localizaçao: \n Rua: ";
            std::getline(std::cin, nome_rua);
            std::cout << "\nBairro: ";
            std::getline(std::cin, nome_bairro);
            std::cout << "\nCEP: ";
            std::getline(std::cin, cep);
            std::cout << "\nPonto de referencia: ";
            std::getline(std::cin, referencia);

            
        }
        else if (resposta == 3)
        {
            std::string data;
            std::string horario;
            int resp;

            // agendar coleta
            std::cout << "===== AGENDAR COLETA ===== \n";
            std::cout << "Insira o dia e o horario ideal para voce realizar essa coleta: \n";
            std::cout << "Dia (DD/MM/AAAA): ";
            std::getline (std::cin, data);
            std::cout<< "\n Horario (HH:MM): ";
            std::getline (std::cin, horario);

            std::cout << "\n== LOCAL == \n 1- Levar no local do receptor \n2- Entregar no meu local de coleta \n Escreva o numero da opcao: ";
            std::cin >> resp;
                if (resp==1) {
                    // o local de coleta é o local do receiver
                } 
                else if (resp==2) {
                    // o local de coleta é o local do donor
                }
        }
    }


}
