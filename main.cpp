#include <iostream>
#include <stdlib.h>
#include <string>
#include <exception>

#include "Database/Database.h"
#include "ConsoleText/ConsoleText.h"
#include "Autenticate/Autenticate.h"
#include "User/User.h"
#include "Residue/Solid.h"
#include "Residue/Liquid.h"

// para compilar: g++ **/**.cpp main.cpp

int main()
{
    User currentUser;
    Database db = Database();
    db.fakePopulate();

login:
    int accessoOuCadastro = ConsoleText::printMenuAcessoCadastro();
    int doadorOuReceptor = ConsoleText::printMenuSelectUserType();

    Autenticate *auth = new Autenticate();
    if (accessoOuCadastro == 1)
    {
        std::string login, password;

        while (true)
        {
            ConsoleText::printMenuAutenticaUsuario(login, password);
            try
            {
                currentUser = auth->login(login, password, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
                continue;
            }

            break;
        }
    }
    else
    {
        std::string name, login, password, adress;
        int document;

        while (true)
        {
            ConsoleText::printMenuCadastraUsuario(name, login, password, document, adress);
            try
            {
                auth->cadastro(name, login, password, document, adress, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
                continue;
            }

            break;
        }

        while (true)
        {
            ConsoleText::printMenuAutenticaUsuario(login, password);
            try
            {
                currentUser = auth->login(login, password, doadorOuReceptor);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
                std::cin.get();
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
        if (manageResidue == 1)
        {
            int idResiduo = ConsoleText::printSelectResiduo();
            if (doadorOuReceptor == 1)
            {
                db.setDonorInterest(currentUser, idResiduo);
            }
            else
            {
                db.setReceiverInterest(currentUser, idResiduo);
            }

            std::cout << "===== BUSCANDO MATCH ===== \n\n"
                      << std::flush;

            if (!db.deuMatch(currentUser, doadorOuReceptor))
            {
                int op = ConsoleText::printNaoHaMatch();
                if (op == 1)
                {
                    goto inicio;
                }
                else if (op == 2)
                {
                    goto login;
                }
            }
            else
            {
                std::string n;
                db.findMatch(currentUser, doadorOuReceptor);
                std::cout << "Digite o id do usuário: ";
                std::getline(std::cin, n);
                int b = std::stoi(n);

                std::string data, horario;
                int local;

                ConsoleText::printAgendamentoColeta(data, horario, local);
                Scheduling sched;
                if ((local == 1 && doadorOuReceptor == 1) || (local == 2 && doadorOuReceptor == 1))
                {
                    int x = currentUser.getId();
                    const std::vector<Receiver> aa = db.readReceiverUsers();
                    Receiver t = aa[b];
                    Donor d = db.readDonorUsers()[x];
                    ConsoleText::printEndereco(t, data, horario);
                    db.createItem(Scheduling(d, t, idResiduo, t.getAdress(), data, horario));
                }
                else
                {
                    int x = currentUser.getId();
                    Receiver t = db.readReceiverUsers()[x];
                    Donor d = db.readDonorUsers()[b];
                    ConsoleText::printEndereco(currentUser, data, horario);
                    db.createItem(Scheduling(d, t, idResiduo, currentUser.getAdress(), data, horario));
                }

                goto inicio;
            }
        }
        else if (manageResidue == 2)
        {
            // cadastrar um residuo

            int addResiduo = ConsoleText::printCadastroResiduos();
            std::string nome_residuo, descarte_residuo;
            if (addResiduo == 1)
            {
                ConsoleText::printCadastroResiduoSolido(nome_residuo, descarte_residuo);
                db.createItem(Solid(nome_residuo, descarte_residuo));
            }
            else
            {
                ConsoleText::printCadastroResiduoLiquido(nome_residuo, descarte_residuo);
                db.createItem(Liquid(nome_residuo, descarte_residuo));
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

        system("clear");
        std::cout << "Dados alterados com sucesso!!\n"
                  << std::flush;
        goto inicio;
    }
    else if (oQFazer == 3)
    {
        if (!ConsoleText::printAgendamentos(currentUser))
        {
            std::cout << "Nenhum agendamento encontrado. \n";
            std::cin.get();
            goto inicio;
        }

        int agnoq = ConsoleText::printAgendamentosOqueFazer();

        if (agnoq == 1)
        {
            int nAg = ConsoleText::getIdAgendamento();
            Scheduling sched = db.readSchedules()[nAg];

            std::string data, horario;
            int local;

            ConsoleText::printAgendamentoColeta(data, horario, local);

            sched.setData(data);
            sched.setHora(horario);
            if (local == 1 && doadorOuReceptor == 1)
            {
                User t = (User)sched.getReceiver();
                ConsoleText::printEndereco(t, data, horario);
                sched.setPontoColeta(t.getAdress());
            }
            else if (local == 2)
            {
                ConsoleText::printEndereco(currentUser, data, horario);
                sched.setPontoColeta(currentUser.getAdress());
            }
            db.updateItem(sched);
            goto inicio;
        }
        else if (agnoq == 2)
        {
            int nAg = ConsoleText::getIdAgendamento();
            Scheduling sched = db.readSchedules()[nAg];
            sched.setEffective(true);
            db.updateItem(sched);
            goto inicio;
        }
        else
        {
            goto inicio;
        }
    }
    else if (oQFazer == 4)
    {
        goto login;
    }
    else
    {
        return 0;
    }

    return 0;
}
