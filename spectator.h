#ifndef SPECTATOR_H
#define SPECTATOR_H
#include <iostream>
#include <string>
#include "exceptii.h"
#include <vector>
#include "pofte_si_exigente.h"
#include <conio.h>

class spectator : public exigente, public pofte{
    std::string nume;
    std::string email;
    std::string parola;
    int varsta;
public:
    spectator();
    void creareCont();
    friend std::istream& operator>>(std::istream&, spectator&);
    void afisare(){std::cout<<nume;}
//    void get_parola();
//    void get_email();
    bool login(std::string email, std::string parola);
    ~spectator(){};
    friend class meniu;
};


#endif // SPECTATOR_H
