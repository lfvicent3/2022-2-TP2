#include <string>
#include <exception>

#include "ConsoleText/ConsoleText.h"
#include "Autenticate/Autenticate.h"
#include "User/User.h"
#include "Residue/Solid.h"
#include "Residue/Liquid.h"
#include "CollectPoint/CollectPoint.h"


int main()
{
    User currentUser;
    Database *db = new Database();
    // Criar os dados fake nessa função. FEITO!
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
        std::string name, login, password,adress;
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

    ConsoleText::printBemVindo(currentUser);
    

    int oQFazer = ConsoleText::printMenuOqueFazer(doadorOuReceptor);
    if (oQFazer == 1)
    {

        int typeResiduo = ConsoleText::printCadastroResiduos();
        std::string nome_residuo, descarte_residuo;
        if (typeResiduo == 1)
        {
            ConsoleText::printCadastroResiduoSolido(nome_residuo, descarte_residuo);
            db->createItem(Solid(nome_residuo, descarte_residuo));
        }
        else
        {
            ConsoleText::printCadastroResiduoLiquido(nome_residuo, descarte_residuo);
            db->createItem(Liquid(nome_residuo, descarte_residuo));
        }

        

    }
    else if (oQFazer == 2)
    {
        
    }
    else if (oQFazer == 3 && doadorOuReceptor == 1)
    {
        std::string data, horario;
        int local;

        ConsoleText::printAgendamentoColeta(data, horario, local);
        if (local == 1)
        {
            
        }
        else if (local == 2)
        {
            ConsoleText::printEndereco(currentUser,data,horario);
        }
    }
    else
    {

        // Listar agendamentos de coleta;
    }

    delete db;

    return 0;
}
