#include "Donor.h"

Donor::Donor() : User(){}
Donor::Donor(std::string name, std::string login, std::string password, int document, std::string adress) : User(name, login, password, document, adress) {}
Donor::~Donor() {}