#ifndef TIP_SPECTACOL_H
#define TIP_SPECTACOL_H
#include <iostream>
#include <string>
#include "exceptii.h"
#include <vector>
#include "spectacol.h"

class circ : public spectacol{
    bool auAnimale;
    std::vector<std::string> animale;
    int nrprestatii;
    int durataPrestatie;
    int pauza;
    static std::string animalePericuloase[10];
    bool areAnimalePericuloase=0;
public:

    friend class meniu;
    circ():spectacol(){gen="Comedie",auAnimale=0, nrprestatii=0, durata=0, pauza=0, durataPrestatie=0;}
    circ(const circ& ob);
    void afisare();
    void citire();
    void set_areAnimalePericuloase(){areAnimalePericuloase=1;}
    ~circ(){}

};

class actOpera{
    std::string solistPrincipal;
    std::string tipSolist;
    int durataAct;
    friend class meniu;
public:
    int get_durataAct(){return durataAct;}
    void set_solistPrincipal(std::string x){solistPrincipal=x;}
    void set_tipSolist(std::string x){tipSolist=x;}
    void set_durataAct(int x){durataAct=x;}
    actOpera();
    actOpera(const actOpera&);
    actOpera& operator=(const actOpera&);
    friend std::istream& operator>>(std::istream&, actOpera&);
    friend std::ostream& operator<<(std::ostream&, actOpera&);
    ~actOpera(){};

};

class opera : public spectacol{
    int nrActe;
    int pauza;
    std::vector<actOpera> acte;
public:
    friend class meniu;
    void citire();
    void afisare();
    opera();
    opera(opera const&);
    ~opera(){};

};

class teatruNeinteractiv : virtual public spectacol{
    int durataFixa;
    std::string regizor;
    int nrActori;
    std::vector<std::string> actori;
public:
    friend class meniu;
    virtual void citire();
    virtual void afisare();
    teatruNeinteractiv();
    teatruNeinteractiv(teatruNeinteractiv const&);
    virtual ~teatruNeinteractiv(){};
};


class teatruInteractiv : public teatruNeinteractiv, virtual public spectacol{
public:
    friend class meniu;
    void citire();
    void afisare();
    teatruInteractiv() : teatruNeinteractiv(){esteInteractiv=1;}
    teatruInteractiv(teatruInteractiv const& ob) : teatruNeinteractiv(ob){}
    void set_durata(int x){durata=durata+x;}
    ~teatruInteractiv(){}
};

#endif // TIP_SPECTACOL_H
