#include <string>

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

    int accessoOuCadastro = ConsoleText::printMenuAcessoCadastro();
    int doadorOuReceptor = ConsoleText::printMenuSelectUserType();

    Autenticate *auth = new Autenticate();
    if (accessoOuCadastro == 1)
    {
        std::string login, password;
        ConsoleText::printMenuAutenticaUsuario(login, password);
        currentUser = auth->login(login, password, doadorOuReceptor);
    }
    else
    {
        std::string name, login, password;
        int document;
        ConsoleText::printMenuCadastraUsuario(name, login, password, document);
        auth->cadastro(name, login, password, document, doadorOuReceptor);

        ConsoleText::printMenuAutenticaUsuario(login, password);
        currentUser = auth->login(login, password, doadorOuReceptor);
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
        std::string nome_rua, nome_bairro, cep, referencia;
        ConsoleText::printCadastroPontoColeta(nome_rua, nome_bairro, cep, referencia);
        // Adicionar o usuario que criou a CollectPoint
        // Criar a sobrecarga em Database;
        db->createItem(CollectPoint(nome_rua, nome_bairro, cep, referencia));
    }
    else if (oQFazer == 3 && doadorOuReceptor == 1)
    {
        std::string data, horario;
        int local;
        ConsoleText::printAgendamentoColeta(data, horario, local);
        if (local == 1)
        {
            // o local de coleta é o local do receiver
        }
        else if (local == 2)
        {
            // o local de coleta é o local do donor
        }
    }
    else
    {
    }

    return 0;
}