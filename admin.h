#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include "exceptii.h"
#include <vector>

class admin{
    std::string nume;
    std::string email;
    std::string parola;
public:
    admin();
    void creareCont();
    bool login(std::string email, std::string parola);
    ~admin(){};
    friend class meniu;
};

#endif // ADMIN_H
