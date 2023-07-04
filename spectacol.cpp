#include "spectacol.h"
#include "exceptii.h"

void spectacol::citire(){
    Exceptii<int> ex;
    std::cout<<"Nume: ";std::cin>>nume;
    std::cout<<"Tip: ";std::cin>>tip;
    if(gen==""){
        std::cout<<"Gen: ";std::cin>>gen;}
    std::cout<<"Data: ";std::cin>>data;
     while(!ex.verificaDataInput(data)){
        std::cout<<"Data: ";std::cin>>data;
    }
    std::cout<<"Ora: ";std::cin>>ora;
    while(!ex.verificaOraInput(ora)){
        std::cout<<"Ora: ";std::cin>>ora;
    }
    std::string s;
    std::string context = "Numar locuri";
    nrLocuri=f(s,context);
}


void spectacol::afisare(){
    std::cout<<"Nume: "<<nume<<std::endl;
    std::cout<<"Tip: "<<tip<<std::endl;
    std::cout<<"Gen: "<<gen<<std::endl;
    std::cout<<"Data: "<<data<<std::endl;
    std::cout<<"Ora: "<<ora<<std::endl;
    std::cout<<"Numar locuri: "<<nrLocuri<<std::endl;
    std::cout<<"Numar spectatori la momentul actual: "<<nrSpectatori<<std::endl;
}


spectacol::spectacol(std::string nume, std::string tip, std::string gen, std::string data, std::string ora, int durata, int nrLocuri, bool estePentruAdulti, bool esteInteractiv){
    this->nume=nume;
    this->tip=tip;
    this->gen=gen;
    this->data=data;
    this->ora=ora;
    this->durata=durata;
    this->nrLocuri=nrLocuri;
    this->estePentruAdulti=estePentruAdulti;
    this->esteInteractiv=esteInteractiv;
    nrSpectatori=0;
}

spectacol::spectacol(const spectacol& ob){
    nume=ob.nume;
    tip=ob.tip;
    gen=ob.gen;
    data=ob.data;
    ora=ob.ora;
    durata=ob.durata;
    nrLocuri=ob.nrLocuri;
    estePentruAdulti=ob.estePentruAdulti;
    esteInteractiv=ob.esteInteractiv;
}

spectacol& spectacol::operator=(const spectacol& ob){
    if(this!=&ob){
        nume=ob.nume;
        tip=ob.tip;
        gen=ob.gen;
        data=ob.data;
        ora=ob.ora;
        durata=ob.durata;
        nrLocuri=ob.nrLocuri;
        estePentruAdulti=ob.estePentruAdulti;
        esteInteractiv=ob.esteInteractiv;
    }
    return *this;
}

