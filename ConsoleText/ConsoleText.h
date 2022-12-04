#ifndef CONSOLETEXT_H
#define CONSOLETEXT_H

#include <iostream>
#include <string>
#include "../User/User.h"

class ConsoleText
{
private:
    static int getIntOption(bool(validateEntrada)(int), const std::string &erroMessage);
    static bool validateOpInt(int op);
    static bool validateOpInt2(int op);
    static bool notValidate(int op);

public:
    static int printMenuAcessoCadastro();
    static int printMenuSelectUserType();
    static int printMenuAgendamento(int userType);
    static void printMenuAutenticaUsuario(std::string &login, std::string &password);
    static void printMenuCadastraUsuario(std::string &name, std::string &login, std::string &password, int &document, std::string &adress);
    static void printBemVindo(User &user);
    static int printMenuOqueFazer(int userType);
    static int printCadastroResiduos();
    static void printCadastroResiduoSolido(std::string &name, std::string &help);
    static void printCadastroResiduoLiquido(std::string &name, std::string &help);
    static void printCadastroPontoColeta(std::string &nameRua, std::string &nameBairro, std::string &cep, std::string &referencia);
    static void printAgendamentoColeta(std::string &data, std::string &horario, int &local);

    static void printEndereco(User &user,std::string &data, std::string &horario);

    static int printGerenciarResiduos (int userType);
    static int printEditProfile ();

    
};

#endif