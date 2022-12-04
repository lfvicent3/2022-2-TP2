#include <iostream>
#include <stdlib.h>
#include <string>
#include <exception>

#include "ConsoleText/ConsoleText.h"
#include "Autenticate/Autenticate.h"
#include "User/User.h"
#include "Residue/Solid.h"
#include "Residue/Liquid.h"
#include "CollectPoint/CollectPoint.h"

// para compilar: g++ **/**.cpp main.cpp

int main()
{
    User currentUser;
    Database *db = new Database();
    db->fakePopulate();

    int accessoOuCadastro = ConsoleText::printMenuAcessoCadastro();
    int doadorOuReceptor = ConsoleText::printMenuSelectUserType();

    Autenticate *auth = new Autenticate();
    if (accessoOuCadastro == 1)
    {
        std::string login, password;
        ConsoleText::printMenuAutenticaUsuario(login, password);

        while (true)
        {
            try
            {
                currentUser = auth->login(login, password, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }

            break;
        }
    }
    else
    {
        std::string name, login, password, adress;
        int document;
        ConsoleText::printMenuCadastraUsuario(name, login, password, document, adress);
        // tratar excessao

        while (true)
        {
            try
            {
                auth->cadastro(name, login, password, document, adress, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }

            break;
        }

        ConsoleText::printMenuAutenticaUsuario(login, password);
        // tratar excessao

        while (true)
        {
            try
            {
                currentUser = auth->login(login, password, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }

            break;
        }
    }
    delete auth;

inicio:

    ConsoleText::printBemVindo(currentUser);

    int oQFazer = ConsoleText::printMenuOqueFazer(doadorOuReceptor);
    if (oQFazer == 1)
    {

        int manageResidue = ConsoleText::printGerenciarResiduos(doadorOuReceptor);
        if (manageResidue == 1 && doadorOuReceptor == 1)
        {
            
            int idResiduo;
            // doador
            system("CLS");
            std::cout << "===== RESIDUOS DISPONIVEIS PARA DOACAO ===== \n\n"
                      << std::flush;
            db->printItem();
            std::cout << "\nDigite o id do residuo escolhido: ";
            std::cin >> idResiduo;

            db->setDonorInterest(currentUser, idResiduo);

            system("CLS");

            std::cout << "===== BUSCANDO MATCH ===== \n\n"
                      << std::flush;

            int match = db->deuMatch(currentUser, doadorOuReceptor);

            if (match == -1)
            {
                int op = ConsoleText::printNaoHaMatch();
                if (op == 1)
                {
                    goto inicio;
                }
                else if (op == 2)
                {
                    return 0;
                }
            }
            else
            {
                db->findMatch(currentUser, doadorOuReceptor);
            }
        }
        else if (manageResidue == 1 && doadorOuReceptor == 2)
        {
            // receptor
            int idResiduo;

            system("CLS");
            std::cout << "===== RESIDUOS DISPONIVEIS PARA COLETA ===== \n\n"
                      << std::flush;
            db->printItem();
            std::cout << "\nDigite o id do residuo escolhido: ";
            std::cin >> idResiduo;

            db->setReceiverInterest(currentUser, idResiduo);

            system("CLS");

            std::cout << "===== BUSCANDO MATCH ===== \n\n"
                      << std::flush;

            db->findMatch(currentUser, doadorOuReceptor);
        }
        else if (manageResidue == 2)
        {
            // cadastrar um residuo

            int addResiduo = ConsoleText::printCadastroResiduos();
            std::string nome_residuo, descarte_residuo;
            if (addResiduo == 1)
            {
                ConsoleText::printCadastroResiduoSolido(nome_residuo, descarte_residuo);
                db->createItem(Solid(nome_residuo, descarte_residuo));
            }
            else
            {
                ConsoleText::printCadastroResiduoLiquido(nome_residuo, descarte_residuo);
                db->createItem(Liquid(nome_residuo, descarte_residuo));
            }

            std::cout << "\nResiduo cadastrado com sucesso!";

            goto inicio;
        }
    }
    else if (oQFazer == 2)
    {
        // editar o perfil
        int editProfile = ConsoleText::printEditProfile();
        if (editProfile == 1)
        {
            // editar o endereco
            std::string novoEndereco;
            std::cout << "==== EDITAR ENDERECO ==== \n Escreva o novo endereço: ";
            std::getline(std::cin, novoEndereco);
            currentUser.setAdress(novoEndereco);
        }
        else if (editProfile == 2)
        {
            // editar o nome
            std::string novoNome;
            std::cout << "==== EDITAR NOME ==== \n Escreva o novo nome: ";
            std::getline(std::cin, novoNome);
            currentUser.setName(novoNome);
        }

        system("CLS");
        std::cout << "Dados alterados com sucesso!!\n"
                  << std::flush;
        goto inicio;
    }
    else if (oQFazer == 3 && doadorOuReceptor == 1)
    {
        ConsoleText::printMenuAgendamento(doadorOuReceptor);
        std::string data, horario;
        int local;

        ConsoleText::printAgendamentoColeta(data, horario, local);
        if (local == 1)
        {
        }
        else if (local == 2)
        {
            ConsoleText::printEndereco(currentUser, data, horario);
        }
    }
    else
    {

        // Listar agendamentos de coleta;
    }

    delete db;

    return 0;
}
