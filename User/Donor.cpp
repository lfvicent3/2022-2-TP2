#include "Donor.h"

Donor::Donor() : User(){}
Donor::Donor(std::string name, std::string login, std::string password) : User(name, login, password) {}
Donor::~Donor() {}