#include "Receiver.h"

Receiver::Receiver() : User() {}
Receiver::Receiver(std::string name, std::string login, std::string password, int document,std::string adress) : User(name, login, password, document,adress) {}
Receiver::~Receiver() {}