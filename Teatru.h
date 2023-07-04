#ifndef TEATRU_H
#define TEATRU_H
#include "spectacol.h"
#include <string>
#include <vector>
#include "exceptii.h"
#include "tip_spectacol.h"
class Teatru
{
private:
   std::string nume;
   std::string site;
   std::string adresa;
   std::string telefon;
   std::string program;
   std::vector<spectacol*> spectacole;
   friend class Teatru_builder;
   friend class meniu;
public:
    template <typename T>
    void adaugaSpectacol();
    friend std::ostream &operator<<(std::ostream &out, const Teatru &ob);
    void sorteazaSpectacoleDupaNumePrinLambda();
    Teatru()=default;
};

class Teatru_builder
{
private:
    Teatru t;
public:
    Teatru_builder() = default;
    Teatru_builder& nume(const std::string& nume);
    Teatru_builder& site(const std::string& site);
    Teatru_builder& adresa(const std::string& adresa);
    Teatru_builder& telefon(const std::string& telefon);
    Teatru_builder& program(const std::string& program);
    Teatru_builder& Spectacol(const std::vector<spectacol*> spectacole);
    Teatru build();
};


template <typename T>
void Teatru::adaugaSpectacol(){
    spectacol *s = new T();
    std::cin >> *s;
    spectacole.push_back(s);
}

#endif // TEATRU_H
