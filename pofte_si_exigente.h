#ifndef POFTE_SI_EXIGENTE_H
#define POFTE_SI_EXIGENTE_H
#include <iostream>
#include <string>
#include "exceptii.h"
#include <vector>

class pofte{
    bool gen;
    std::string poftaGen;
    bool tip;
    std::string poftaTip;
    bool timp;
    int poftaTimp;

public:
    friend class meniu;
    void citire();
    pofte();
    friend std::istream& operator>>(std::istream& in, pofte& ob){ob.citire(); return in;};
    ~pofte(){}

};

class exigente{
    bool tip_gen;
    std::string _tip;
    std::string _gen;
    bool durata;
    int ziDurata;
    bool animalePericuloase;
    bool maximSpectatori;
    int ziMaximSpectatori;
    bool varstaLimita;
public:
    friend class meniu;
    void citire();
    exigente();
    friend std::istream& operator>>(std::istream& in , exigente& ob){ob.citire(); return in;}
    ~exigente(){};

};


#endif // POFTE_SI_EXIGENTE_H
