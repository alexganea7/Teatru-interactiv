#include "tip_spectacol.h"

/// -------------------------------------------------------///

std::string circ::animalePericuloase[10]={"Sarpe","Leu","Tigru"};

circ::circ(const circ& ob) : spectacol(ob){
    auAnimale=ob.auAnimale;
    for (unsigned int p=0; p<ob.animale.size(); p++)
        animale.push_back(ob.animale[p]);
    nrprestatii=ob.nrprestatii;
    durataPrestatie=ob.durataPrestatie;
    pauza=ob.pauza;
}


void circ::citire(){
    spectacol::citire();
    std::string s;
    std::string context;
    std::cout<<"Exista animale? (da/nu) - ";
    std::string raspuns;
    std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Exista animale? - ";
        std::cin>>raspuns;
    }
    if(raspuns=="nu")
        auAnimale=0;
    else if(raspuns=="da")
    {
        auAnimale=1;
        context = "Numar animale";
        int nr = f(s,context);
        std::cout<<"Introduceti animalele: ";
        std::string animal;
        for (int p=0; p<nr; p++){
            std::cin>>animal;
            animale.push_back(animal);
        }
        for(auto p=animale.begin(); p!=animale.end(); p++){
        for(int q=0; q<4; q++)
            if(*p==animalePericuloase[q])
                set_areAnimalePericuloase();
    }
        std::cout<<std::endl;
    }

    context ="Numar prestatii";
    nrprestatii=f(s,context);
    context="Durata prestatie";
    durataPrestatie=f(s,context);
    set_durata((durataPrestatie+pauza)*nrprestatii);
    std::cout<<std::endl;


}
void circ::afisare(){
    spectacol::afisare();
    if(!auAnimale)
        std::cout<<"Acest spectacol nu are animale"<<std::endl;
    else{
        std::cout<<"Lista animale:";
        for(auto p=animale.begin(); p!=animale.end(); p++)
            std::cout<<*p<<" ";
        std::cout<<std::endl;
        }
    std::cout<<"Numar prestatii: "<<nrprestatii<<std::endl;
    std::cout<<"Pauza intre prestatii: "<<pauza<<std::endl;
    std::cout<<"Durata prestatie: "<<durataPrestatie<<std::endl;
    std::cout<<"Durata totala: "<<durata;
}

/// -------------------------------------------------------///

std::istream& operator>>(std::istream& in, actOpera& ob){
    std::cout<<"Nume solist: ";
    getline(in,ob.solistPrincipal);
    std::cout<<"Tipul solistului: ";in>>ob.tipSolist;
    while(ob.tipSolist!="Tenor" and ob.tipSolist!="Bass" and ob.tipSolist!="Bariton"){
        try{
            if(ob.tipSolist!="Tenor" and ob.tipSolist!="Bass" and ob.tipSolist!="Bariton") throw exceptie3();}
    catch(exceptie3& ob){std::cout<<ob.what()<<std::endl;}
    std::cout<<"Tipul solistului: ";in>>ob.tipSolist;;
    }
    std::string s;
    std::string context = "Durata act";
    ob.durataAct=f(s,context);
    std::cout<<std::endl;
    return in;
}
std::ostream& operator<<(std::ostream& out, actOpera& ob){
    out<<"Nume solist: "<<ob.solistPrincipal<<std::endl;
    out<<"Tipul solistului: "<<ob.tipSolist<<std::endl;
    out<<"Durata act: "<<ob.durataAct<<std::endl;
    return out;
}

actOpera::actOpera(){
    solistPrincipal = "";
    tipSolist = "";
    durataAct = 0;
}

actOpera::actOpera(const actOpera& ob){
    solistPrincipal=ob.solistPrincipal;
    tipSolist=ob.tipSolist;
    durataAct=ob.durataAct;
}

actOpera& actOpera::operator=(const actOpera& ob){
    if(this!=&ob){
        solistPrincipal=ob.solistPrincipal;
        tipSolist=ob.tipSolist;
        durataAct=ob.durataAct;
    }
    return *this;
}

/// -------------------------------------------------------///

opera::opera() : spectacol(){
    nrActe=0;
    pauza=0;
}

opera::opera(opera const& ob) : spectacol(ob){
    nrActe=ob.nrActe;
    pauza=ob.pauza;
    for (unsigned int p=0; p<ob.acte.size(); p++)
        acte.push_back(ob.acte[p]);

}

void opera::citire(){
    spectacol::citire();
    std::string s;
    std::string context;
    context = "Pauza intre acte";
    pauza=f(s,context);
    std::cout<<"Numar acte: ";std::cin>>s;
    while(1){
    try{
    stoi(s);
    while(stoi(s)<2 or stoi(s)>7){
        try{
            if(stoi(s)<2) throw exceptie1();
            if(stoi(s)>7) throw exceptie2();}
    catch(exceptie1& ob){std::cout<<ob.what()<<std::endl;}
    catch(exceptie2& ob){std::cout<<ob.what()<<std::endl;}
    std::cout<<"Numar acte: ";std::cin>>s;
    }
    break;
    }
    catch (...){
        std::cout<<"Numar acte poate fi doar un numar!!!"<<std::endl;
        std::cout<<"Numar acte: ";std::cin>>s;}
    }
    nrActe = stoi(s);
    actOpera act;
    int x=0;
    for (int i=0; i<nrActe; i++){
        std::cin.ignore();
        std::cout<<"Introdu actul... "<<std::endl;
        std::cin>>act;
        x=x+act.get_durataAct();
        acte.push_back(act);
    }
    x=x+pauza*nrActe;
    set_durata(x);
}

void opera::afisare(){
    spectacol::afisare();
    std::cout<<"Pauza intre acte: ";std::cout<<pauza<<std::endl;
    std::cout<<"Numar acte: "<<nrActe<<std::endl<<std::endl;
    for(auto p=acte.begin(); p!=acte.end(); p++)
        std::cout<<*p<<std::endl;
    std::cout<<"Durata totala: "<<durata<<std::endl;
}

/// -------------------------------------------------------///

teatruNeinteractiv::teatruNeinteractiv(teatruNeinteractiv const& ob) : spectacol(ob){
    durataFixa=ob.durataFixa;
    regizor=ob.regizor;
    nrActori=ob.nrActori;
    for (unsigned int p=0; p<ob.actori.size(); p++)
        actori.push_back(ob.actori[p]);
}

teatruNeinteractiv::teatruNeinteractiv() : spectacol()
{
    esteInteractiv=0;
    durataFixa=0;
    regizor="";
    nrActori=0;
}
void teatruNeinteractiv::citire(){
    spectacol::citire();
    std::string s;
    std::string context = "Durata piesa";
    durataFixa=f(s,context);
    set_durata(durataFixa);
    std::cin.ignore();
    std::cout<<"Regizorul piesei: ";getline(std::cin, regizor);
    context = "Numar actori";
    nrActori=f(s,context);
    std::string actor;
    std::cin.ignore();
    for(int i=0; i<nrActori; i++){
        std::cout<<"Introdu actor..."<<std::endl;
        std::cout<<"Actor: ";
        getline(std::cin,actor);
        actori.push_back(actor);

    }
}


void teatruNeinteractiv::afisare(){
    spectacol::afisare();
    std::cout<<"Durata piesa: "<<durata<<std::endl;
    std::cout<<"Regizor: "<<regizor<<std::endl;
    if(nrActori>0)
        std::cout<<"Actorii piesei sunt... "<<std::endl;
    for(auto p=actori.begin(); p!=actori.end(); p++)
        std::cout<<"Actor: "<<*p<<std::endl;
}

/// -------------------------------------------------------///


void teatruInteractiv::citire(){
    teatruNeinteractiv::citire();
}

void teatruInteractiv::afisare(){
    teatruNeinteractiv::afisare();
}
/// -------------------------------------------------------///
