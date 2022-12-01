#include "Donor.h"

Donor::Donor() : User(){}
Donor::Donor(std::string name, std::string login, std::string password, int document) : User(name, login, password, document) {}
Donor::~Donor() {}