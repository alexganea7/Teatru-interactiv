#include "Teatru.h"


std::ostream &operator<<(std::ostream &out, const Teatru &ob) {
    out<<"Nume: "<<ob.nume<<std::endl;
    out<<"Site: "<<ob.site<<std::endl;
    out<<"Adresa: "<<ob.adresa<<std::endl;
    out<<"Telefon: "<<ob.telefon<<std::endl;
    out<<"Program: "<<ob.program<<std::endl;
    if(ob.spectacole.size())
    out<<"Spectacole... "<<std::endl<<std::endl;
    int i = 1;
    for(auto p=ob.spectacole.begin(); p!=ob.spectacole.end(); p++){
        out<<"-------------------"<<i<<"------------------- \n";
        out<<(**p)<<std::endl<<"----------------------------------------"<<std::endl<<std::endl;
        i++;}
    return out;
}

void Teatru::sorteazaSpectacoleDupaNumePrinLambda(){
    std::sort(spectacole.begin(), spectacole.end(), [](const spectacol *a, const spectacol*b){
              return a->nume < b->nume;

    });
}

Teatru_builder& Teatru_builder:: nume(const std::string& nume){
    t.nume=nume;
    return *this;
}
Teatru_builder& Teatru_builder:: site(const std::string& site){
    t.site=site;
    return *this;
}
Teatru_builder& Teatru_builder:: adresa(const std::string& adresa){
    t.adresa=adresa;
    return *this;
}
Teatru_builder& Teatru_builder:: telefon(const std::string& telefon){
    t.telefon=telefon;
    return *this;
}
Teatru_builder& Teatru_builder:: program(const std::string& program){
    t.program=program;
    return *this;
}
Teatru_builder& Teatru_builder:: Spectacol(const std::vector<spectacol*> spectacole){
    t.spectacole=spectacole;
    return *this;
}

Teatru Teatru_builder::build(){
    return t;
}
