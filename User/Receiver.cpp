#include "Receiver.h"

Receiver::Receiver() : User() {}
Receiver::Receiver(std::string name, std::string login, std::string password, int document) : User(name, login, password, document) {}
Receiver::~Receiver() {}