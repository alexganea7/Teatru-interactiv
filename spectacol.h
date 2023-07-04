#ifndef SPECTACOL_H
#define SPECTACOL_H
#include <iostream>
#include <string>

class spectacol{
protected:
    std::string nume;
    std::string tip;
    std::string gen;
    std::string data;
    std::string ora;
    int nrLocuri;
    int nrSpectatori;
    int durata;
    bool estePentruAdulti;
    bool esteInteractiv=0;
public:
    friend class meniu;
    friend class Teatru;
    virtual void citire();
    virtual void afisare();
    spectacol(std::string nume="",std::string tip="",std::string gen="", std::string data="", std::string ora="", int durata=0, int nrLocuri=0, bool estePentruAdulti=0, bool esteInteractiv=0);
    spectacol(const spectacol&);
    spectacol& operator=(const spectacol&);
    friend std::istream& operator>>(std::istream& in, spectacol& ob){ob.citire(); return in;}
    friend std::ostream& operator<<(std::ostream& out, spectacol& ob){ob.afisare(); return out;}
    void set_esteInteractiv(){esteInteractiv=1;}
    virtual void set_durata(int x){durata=x;}
    void set_nrSpectatori(){nrSpectatori++;}
    virtual ~spectacol(){};

};
#endif // SPECTACOL_H
