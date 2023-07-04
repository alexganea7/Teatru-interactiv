#include "meniu.h"

meniu *meniu::instance = NULL;

meniu *meniu::getInstance(){
    if(!instance){
        instance = new meniu();
    }
    return instance;
}


void meniu::creare(){
    spect.creareCont();
    acasa();
}

std::string meniu::chitanta(std::string numeSpectacol){
    std::string mesaj;
    mesaj=" Biletul nr ";
    mesaj+=std::to_string(chitante.size()+1);
    mesaj+="\n Nume spectator: ";
    mesaj+=spect.nume;
    mesaj+="\n Locatie teatru: ";
    mesaj+=t.nume;
    mesaj+="\n Nume spectacol: ";
    mesaj+=numeSpectacol;
    return mesaj;
}


void meniu::listaTeatre(){
    listaSpectacole();
    std::vector<Teatru> lista;
    Teatru_builder b;
    lista.push_back(b.nume("Teatru1").site("Teatru1.ro").adresa("Bucuresti").telefon("0712345678").program("nonstop").Spectacol(spectacole).build());
    lista.push_back(b.nume("Teatru2").site("Teatru2.ro").adresa("Cluj").telefon("0712398765").program("Luni-Vineri").Spectacol(spectacole).build());
    lista.push_back(b.nume("Teatru3").site("Teatru3.ro").adresa("Iasi").telefon("0712543565").program("Luni-Sambata").Spectacol(spectacole).build());
    lista.push_back(b.nume("Teatru4").site("Teatru4.ro").adresa("Timisoara").telefon("0714343565").program("nonstop").Spectacol(spectacole).build());
    Teatre=lista;
    lt=1;
}
void meniu::optiuniAcasa(){
    std::cout<<std::endl<<"        Teatru interactiv";
    std::cout<<std::endl<<std::endl;
    std::cout<<"  1. Creare cont user "<<std::endl;
    std::cout<<"  2. Conectare user "<<std::endl;
    std::cout<<"  3. Conectare admin "<<std::endl;
    std::cout<<"  0. Iesire "<<std::endl<<std::endl<<std::endl;
}
void meniu::acasa(){
    if(!afisat){
        std::cout<<"###################################\n";
        std::cout<<"#                                 #\n";
        std::cout<<"#     ~~~TEATRU INTERACTIV~~~     #\n";
        std::cout<<"#                                 #\n";
        std::cout<<"###################################\n\n\n";
        afisat=1;}
    if(!lt)
        listaTeatre();
    optiuniAcasa();
    int x;
    std::string raspuns;
    std::cout<<"  Introduceti numar: ";
    std::cin>>raspuns;std::cout<<std::endl;
    x=verificaOptiuneAcasa(raspuns);
    while(x>=0 and x<=3){

    switch(x){

    case 1:
    {
        creare();
        break;
    }
    case 2:
    {
        bool ok = 0;
        std::string s;
        while(ok==0){
        logare<spectator> logare(spect);
        ok=logare.login();
        if(ok==0){
            std::cout<<"Apasati orice pentru a continua sau 0 pentru a iesi: ";
            std::cin.ignore();
            getline(std::cin,s);
            if(s=="0"){
                break;
            }
        }
        }
        if(ok){
        system("cls");
        afisareUser();}
        break;
    }
    case 3:
    {
        bool ok = 0;
        std::string s;
        while(ok==0){
        logare<admin> logare(adm);
        ok=logare.login();
        if(ok==0){
            std::cout<<"Apasati orice pentru a continua sau 0 pentru a iesi: ";
            std::cin.ignore();
            getline(std::cin,s);
            if(s=="0"){
                system("cls");
                break;
            }
        }
        }
        if(ok){
        system("cls");
        afisareAdmin();}
        break;
    }
    case 0:
    {
        system("cls");
        std::cout<<"\n\n\t\t\t~~~ LA REVEDERE! ~~~ \n\n";
        std::cout<<"\n";
        std::exit(0);
    }
    }
    std::cout<<std::endl;
    optiuniAcasa();
    std::cout<<"  Introduceti numar: ";
    std::cin>>raspuns;std::cout<<std::endl;
    x=verificaOptiuneAcasa(raspuns);
    }
}
int meniu::verificaOptiuneAcasa(std::string raspuns){
    while(1){
        try{
            stoi(raspuns);
            while(stoi(raspuns)<0 or stoi(raspuns)>3){
            try{
                if(stoi(raspuns)<0 or stoi(raspuns)>3) throw exceptie6();
            }
            catch(exceptie6& ob){std::cout<<std::endl<<ob.what()<<std::endl;}
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;
            }
        return stoi(raspuns);
        }
        catch(...){
            std::cout<<std::endl<<"Va rog introduceti un numar intre 0 si 3 nu un text!"<<std::endl;
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;}
        }
        return stoi(raspuns);
}


int meniu::verificaOptiune(std::string raspuns){
    while(1){
        try{
            stoi(raspuns);
            while(stoi(raspuns)<0 or stoi(raspuns)>5){
            try{
                if(stoi(raspuns)<0 or stoi(raspuns)>5) throw exceptie6();
            }
            catch(exceptie6& ob){std::cout<<std::endl<<ob.what()<<std::endl;}
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;
            }
        return stoi(raspuns);
        }
        catch(...){
            std::cout<<std::endl<<"Va rog introduceti un numar intre 0 si 5 nu un text!"<<std::endl;
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;}
        }
        return stoi(raspuns);
}

int meniu::verificaOptiuneAdmin(std::string raspuns){
    while(1){
        try{
            stoi(raspuns);
            while(stoi(raspuns)<0 or stoi(raspuns)>5){
            try{
                if(stoi(raspuns)<0 or stoi(raspuns)>5) throw exceptie6();
            }
            catch(exceptie6& ob){std::cout<<std::endl<<ob.what()<<std::endl;}
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;
            }
        return stoi(raspuns);
        }
        catch(...){
            std::cout<<std::endl<<"Va rog introduceti un numar intre 0 si 5 nu un text!"<<std::endl;
            std::cout<<"Introduceti optiunea...";
            std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;}
        }
        return stoi(raspuns);
}

void meniu::actualizeazaRecomandari(){
    if(ok==1)
        recomandate.clear();
    for(auto p=t.spectacole.begin(); p!=t.spectacole.end(); p++){
        if((spect.gen == 1 and spect.poftaGen==dynamic_cast<spectacol*>(*p)->gen)
            or (spect.tip == 1 and spect.poftaTip==dynamic_cast<spectacol*>(*p)->tip)
            or (spect.timp == 1 and (spect.poftaTimp <= dynamic_cast<spectacol*>(*p)->durata))
            or(spect.gen==0 and spect.tip==0 and spect.timp == 0)
            )
            recomandate.push_back(*p);
            ok=1;
            }

    for(auto p=recomandate.begin(); p!=recomandate.end(); p++){
        if((spect.tip_gen == 1 and spect._gen == dynamic_cast<spectacol*>(*p)->gen and spect._tip == dynamic_cast<spectacol*>(*p)->tip)
            or (spect.durata == 1 and (spect.ziDurata <= dynamic_cast<spectacol*>(*p)->durata))
            or (spect.animalePericuloase == 1 and dynamic_cast<circ*>(*p)->areAnimalePericuloase == 1)
            or (spect.maximSpectatori == 1 and (spect.ziMaximSpectatori <= dynamic_cast<spectacol*>(*p)->nrLocuri))
            or (dynamic_cast<spectacol*>(*p)->nrLocuri==dynamic_cast<spectacol*>(*p)->nrSpectatori)
          )
           {p=recomandate.erase(p);
            --p;}

    }
}
void meniu::alegeSpectacol(){
    std::string raspuns;
    bool exist=0;
    actualizeazaRecomandari();
    std::cout<<std::endl<<"Introduceti numele spectacolului la care doriti sa mergeti: "<<std::endl;
    std::cout<<"Nume: ";std::cin>>raspuns;
    do{
        for(auto p=recomandate.begin(); p!=recomandate.end(); p++)
            if(raspuns==dynamic_cast<spectacol*>(*p)->nume){
                exist=1;
                dynamic_cast<spectacol*>(*p)->set_nrSpectatori();
                if("Teatru"==dynamic_cast<spectacol*>(*p)->tip){
                    if(dynamic_cast<spectacol*>(*p)->esteInteractiv==1)
                        {
                            if(spect.varsta<16)
                            dynamic_cast<teatruInteractiv*>(*p)->set_durata(2);
                            else
                            dynamic_cast<teatruInteractiv*>(*p)->set_durata(1);
                        }
                }
                std::cout<<std::endl<<"Ati ales spectacolul "<<"'"<<dynamic_cast<spectacol*>(*p)->nume<<"'"<<std::endl;
                std::cout<<"Vizionare placuta!!!"<<std::endl<<std::endl;
                chitante.push_back(chitanta(dynamic_cast<spectacol*>(*p)->nume));

                introdus=0;
                std::string s;
                std::cout<<"\n \n   ~~ APASATI ORICE PENTRU A VA INTOARCE IN MENIU ~~";
                std::cin.ignore();
                getline(std::cin,s);
                system("cls");
                break;
            }
        if(exist==0){
            std::cout<<std::endl<<"Introduceti spectacol existent!!!(sau scrieti 'inapoi' pentru a va intoarce in meniu)"<<std::endl;
            std::cout<<"Nume: ";std::cin>>raspuns;std::cout<<std::endl;}
            if(raspuns=="inapoi")
                break;
    }while(exist==0);
}

void meniu::dateSpectator(){
    std::cout<<std::endl;
    std::cin>>spect;
    introdus=1;
    actualizeazaRecomandari();
    std::cout<<std::endl;
}

void meniu::reseteazaDateUtilizator(){
    std::cout<<std::endl<<std::endl<<"Date utilizator resetate, pentru a va reintroduce datele, scrieti '3'"<<std::endl<<std::endl;
    actualizeazaRecomandari();
    introdus=0;
}


void meniu::afisareTotala(){
    std::cout<<"Alegeti teatrul la care doriti sa mergeti:"<<std::endl<<std::endl;
    for(unsigned int j=0; j<Teatre.size();j++){
        std::cout<<j+1<<": "<<Teatre[j].nume<<", adresa: "<<Teatre[j].adresa<<std::endl;
        }

    std::string raspuns;
    std::cout<<"Se asteapta raspuns: ";
    std::cin >> raspuns;
    bool ebn=0;
    unsigned int poz;
    Exceptii<int> ex;
    while(!ebn)
    {
        poz=ex.verificaTipInput(raspuns);
        if(poz<1 or poz>Teatre.size()){
            std::cout<<"Introduceti o valoare intre 1 si "<<Teatre.size()<<std::endl;
            std::cout<<"Se asteapta raspuns: ";
            std::cin >> raspuns;
        }
        else
            ebn=1;
    }
    poz--;

    t=Teatre[poz];
    t.sorteazaSpectacoleDupaNumePrinLambda();

    std::cout<<std::endl;
    std::cout<<"Spectacole: "<<std::endl<<std::endl;
    if(!t.spectacole.size())
        std::cout<<"Nu exista spectacole introduse"<<std::endl<<std::endl;
    int i = 1;
    for(auto p=t.spectacole.begin(); p!=t.spectacole.end(); p++){
        std::cout<<"-------------------"<<i<<"------------------- \n";
        std::cout<<(**p)<<std::endl<<"----------------------------------------"<<std::endl<<std::endl;
        i++;}

}

void meniu::recomanda(){

    std::cout<<std::endl<<std::endl;
    if(introdus==0)
        std::cout<<"Nu ti-ai introdus inca datele!"<<std::endl<<std::endl;
    else{

        std::cout<<"Alegeti teatrul la care doriti sa mergeti:"<<std::endl<<std::endl;
        for(unsigned int j=0; j<Teatre.size();j++){
            std::cout<<j+1<<": "<<Teatre[j].nume<<", adresa: "<<Teatre[j].adresa<<std::endl;
            }
        std::string raspuns;
        std::cout<<"Se asteapta raspuns: ";
        std::cin >> raspuns;
        bool ebn=0;
        unsigned int poz;
        Exceptii<int> ex;
        while(!ebn)
        {
            poz=ex.verificaTipInput(raspuns);
            if(poz<1 or poz>Teatre.size()){
                std::cout<<"Introduceti o valoare intre 1 si "<<Teatre.size()<<std::endl;
                std::cout<<"Se asteapta raspuns: ";
                std::cin >> raspuns;
            }
            else
                ebn=1;
        }
        poz--;

        t=Teatre[poz];
        t.sorteazaSpectacoleDupaNumePrinLambda();
        int j = 0;
        actualizeazaRecomandari();
        std::cout<<"\n Lista spectacole: \n";
        for(auto p=recomandate.begin(); p!=recomandate.end(); p++)
        {
            std::cout<<" "<<j+1<<": "<<dynamic_cast<spectacol*>(*p)->nume<<std::endl;
            j++;
        }
        std::cout<<std::endl<<"Doriti detalii complete despre vreun spectacol? ";
            bool exista=0;
            std::cout<<"Raspuns: ";std::cin>>raspuns;
            while(raspuns != "da" and raspuns != "nu"){
                std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
                std::cout<<std::endl<<"Raspuns: ";
                std::cin>>raspuns;
            }
            while(raspuns == "da")
                {
                    std::cout<<"Introduceti numele spectacolului: ";
                    do{
                        std::cout<<"Nume: ";std::cin>>raspuns;
                        for(auto p=recomandate.begin(); p!=recomandate.end(); p++){
                            if(raspuns==dynamic_cast<spectacol*>(*p)->nume){
                                exista=1;
                                std::cout<<std::endl<<**p;
                            }
                        }
                        if(exista==0){
                            std::cout<<std::endl<<"Introduceti nume corect!"<<std::endl;
                        }

                    }
                    while(exista==0);
                    std::cout<<std::endl<<std::endl<<"Doriti informatii despre alt spectacol? ";
                    std::cout<<"Raspuns: ";
                    std::cin>>raspuns;
                    while(raspuns != "da" and raspuns != "nu"){
                        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
                        std::cout<<std::endl<<"Raspuns: ";
                        std::cin>>raspuns;
                        }
                    exista = 0;std::cout<<std::endl<<std::endl;}
            std::cout<<std::endl;
                }

    }


void meniu::optiuniUser(){
    std::cout<<std::endl<<"        Optiuni spectator";
    std::cout<<std::endl<<std::endl;
    std::cout<<"1. Afiseaza toate spectacolele"<<std::endl;
    std::cout<<"2. Afiseaza recomandari"<<std::endl;
    std::cout<<"3. Date utilizator"<<std::endl;
    std::cout<<"4. Alege spectacol"<<std::endl;
    std::cout<<"5. Resetati date utilizator"<<std::endl;
    std::cout<<"0. Deconectare";
}

void meniu::afisareUser(){

    optiuniUser();
    int x;
    std::string raspuns;
    std::cout<<std::endl<<std::endl<<"Introduceti optiunea...";
    std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;
    x=verificaOptiune(raspuns);

    while(x>=0 and x<=6)
    {
        switch(x)
        {
        case 0:
        {
            system("cls");
            afisat=0;
            acasa();
        }
        case 1:
        {
            afisareTotala();
            break;

        }
        case 2:
        {
            recomanda();
            break;
        }
        case 3:
        {   if(introdus==0)
                dateSpectator();
            else
                std::cout<<"Deja ti-ai introdus datele!"<<std::endl<<std::endl;
            break;
        }
        case 4:
        {   if(introdus==0)
                std::cout<<std::endl<<"Nu ti-ai introdus inca datele!"<<std::endl<<std::endl;
            else
                alegeSpectacol();
            break;
        }
         case 5:
        {   if(introdus==1)
                reseteazaDateUtilizator();
            else
                std::cout<<std::endl<<"Nu exista date deja introduse!!!"<<std::endl<<std::endl;
            break;
        }

        }
        std::cout<<std::endl;
        optiuniUser();
        std::cout<<std::endl;
        std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;
        x=verificaOptiune(raspuns);

    }
}


/// /// /// ADMIN JOS /// /// ///

void meniu::introduceSpectacol(){
    if(Teatre.size()){
    std::cout<<"Alegeti teatrul caruia doriti sa ii adaugati un spectacol:"<<std::endl<<std::endl;
    for(unsigned int j=0; j<Teatre.size();j++){
        std::cout<<j+1<<": "<<Teatre[j].nume<<std::endl;
    }
    std::string raspuns;
    std::cout<<"Se asteapta raspuns: ";
    std::cin >> raspuns;
    bool ebn=0;
    unsigned int poz;
    Exceptii<int> ex;
    while(!ebn)
    {
        poz=ex.verificaTipInput(raspuns);
        if(poz<1 or poz>Teatre.size()){
            std::cout<<"Introduceti o valoare intre 1 si "<<Teatre.size()<<std::endl;
            std::cout<<"Se asteapta raspuns: ";
            std::cin >> raspuns;
        }
        else
            ebn=1;
    }
    poz--;

    std::cout<<std::endl;
    std::cout<<"Introdu tip(Circ/Opera/TeatruInteractiv/TeatruNeinteractiv)..."<<std::endl;

    std::cout<<"Tip: ";std::cin>>raspuns;std::cout<<std::endl;
    while(raspuns!="Circ" and raspuns!="Opera" and raspuns!="TeatruInteractiv" and raspuns!="TeatruNeinteractiv"){
        try{
            if(raspuns!="Circ" and raspuns!="Opera" and raspuns!="TeatruInteractiv" and raspuns!="TeatruNeinteractiv") throw exceptie5();}
    catch(exceptie5& ob){std::cout<<ob.what()<<std::endl;}
    std::cout<<"Tip: ";std::cin>>raspuns;
    }
    if (raspuns == "Circ")
    {
        typedef circ SpectacolType;
        Teatre[poz].adaugaSpectacol<SpectacolType>();
    }
    else if (raspuns == "Opera")
    {
        typedef opera SpectacolType;
        Teatre[poz].adaugaSpectacol<SpectacolType>();
    }
    else if (raspuns == "TeatruInteractiv")
    {
        typedef teatruInteractiv SpectacolType;
        Teatre[poz].adaugaSpectacol<SpectacolType>();
    }
    else if (raspuns == "TeatruNeinteractiv")
    {
        typedef teatruNeinteractiv SpectacolType;
        Teatre[poz].adaugaSpectacol<SpectacolType>();
    }
    t=Teatre[poz];
    t.sorteazaSpectacoleDupaNumePrinLambda();
    }
            system("cls");

}

void meniu::stergeTeatru(){
    std::string s;
    std::cout<<"\n \n   Introduceti numele teatrului pe care doriti sa il stergeti: \n";
    std::cout<<"Lista nume teatre... \n \n";
    for(unsigned int j=0; j<Teatre.size();j++){
        std::cout<<"    "<<j+1<<": "<<Teatre[j].nume<<std::endl;
    }
    std::cout<<"\n Se asteapta raspuns: ";
    std::cin>>s;
    bool exista = 0;
    while(!exista){
        for(unsigned int j=0; j<Teatre.size(); j++)
            if(Teatre[j].nume==s)
                exista=1;
        if(!exista){
            std::cout<<"\n Nu exista teatru cu numele "<<s<<std::endl;
            std::cout<<" Introduceti alt nume(sau scrieti inapoi pentru a va intoarce inapoi)";
            std::cout<<"\n Se asteapta raspuns: ";
            std::cin>>s;
            if(s=="inapoi")
                break;
        }
    }
    if(exista)
        for(unsigned int j=0; j<Teatre.size();j++){
            if(Teatre[j].nume==s){
                Teatre.erase(Teatre.begin()+j);
                break;}
        }
    system("cls");
}

void meniu::adaugaTeatru(){
    bool ok = 0;
    std::cout<<"Introduceti datele despre noul Teatru... \n";
    std::string _nume, _site, _adresa, _telefon, _program; Teatru_builder b;
    std::cout<<"Nume: ";std::cin>>_nume;
    std::cout<<"Site: ";std::cin>>_site;
    std::cout<<"Adresa: ";std::cin>>_adresa;
    std::cout<<"Telefon: ";std::cin>>_telefon;
    while(!ok){
        ok=1;
        if(_telefon[0]!='0')
        {
            std::cout<<"Numarul de telefon trebuie sa inceapa cu 0 \n";
            std::cout<<"Telefon: ";std::cin>>_telefon;
            ok=0;
        }
        if(_telefon.size()!=10)
        {
            std::cout<<"Numarul de telefon trebuie sa aiba 10 cifre \n";
            std::cout<<"Telefon: ";std::cin>>_telefon;
            ok=0;
        }
        for(unsigned int j=0; j<_telefon.size(); j++)
            if(_telefon[j]<'0' or _telefon[j]>'9')
            {
                std::cout<<"Numarul de telefon trebuie sa contina doar cifre \n";
                std::cout<<"Telefon: ";std::cin>>_telefon;
                ok=0;
                break;
            }

    }
    std::cout<<"Program: ";std::cin>>_program;
    Teatre.push_back(b.nume(_nume).site(_site).adresa(_adresa).telefon(_telefon).program(_program).build());
    system("cls");
}

void meniu::afiseazaTeatre(){
    std::cout<<"Lista teatre cu detalii complete... \n \n";
    for(unsigned int j=0; j<Teatre.size();j++){
    std::cout<<"     "<<j+1<<":   Nume: "<<Teatre[j].nume<<", site: "<<Teatre[j].site;
    std::cout<<", adresa: "<<Teatre[j].adresa<<", telefon: "<<Teatre[j].telefon<<", program: "<<Teatre[j].program;;
    std::cout<<std::endl;
    }
    std::string s;
    std::cout<<std::endl;
    std::cout<<"Apasati orice pentru a va intoarce in meniu: ";
    std::cin.ignore();
    getline(std::cin,s);
    system("cls");
}

void meniu::afiseazaBilete(){
    if(chitante.size()){
        std::cout<<"   Lista biletelor... \n";
        std::cout<<"----------------------\n\n";
        for(unsigned int j=0; j<chitante.size(); j++)
        {
            std::cout<<chitante[j];
            std::cout<<"\n----------------------\n";
        }
        std::cout<<std::endl;

    }
    else
        std::cout<<"\n Nu exista bilete oferite\n ";
}

void meniu::optiuniAdmin(){
    std::cout<<std::endl<<"        Optiuni Admin";
    std::cout<<std::endl<<std::endl;
    std::cout<<"1. Introduceti spectacol"<<std::endl;
    std::cout<<"2. Eliminati teatru"<<std::endl;
    std::cout<<"3. Adauga teatru"<<std::endl;
    std::cout<<"4. Afiseaza detalii teatre"<<std::endl;
    std::cout<<"5. Afiseza bilete"<<std::endl;
    std::cout<<"0. Deconectare";
}

void meniu::afisareAdmin(){

    optiuniAdmin();
    int x;
    std::string raspuns;
    std::cout<<std::endl<<std::endl<<"Introduceti optiunea...";
    std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;
    x=verificaOptiuneAdmin(raspuns);

    while(x>=0 and x<=5)
    {
        switch(x)
        {

        case 1:
        {
            introduceSpectacol();
            break;
        }
        case 2:
        {
            stergeTeatru();
            break;
        }
        case 3:
        {
            adaugaTeatru();
            break;
        }
        case 4:
        {
            afiseazaTeatre();
            break;
        }
        case 5:
        {
            afiseazaBilete();
            break;
        }
        case 0:
        {
            system("cls");
            afisat=0;
            acasa();
        }

        }
        std::cout<<std::endl;
        optiuniAdmin();
        std::cout<<std::endl;
        std::cout<<std::endl<<"Optiune:";std::cin>>raspuns;std::cout<<std::endl;
        x=verificaOptiuneAdmin(raspuns);

    }
}






/// chestii pentru prezentare

void meniu::listaSpectacole(){
    circ *c = new circ();
    c->nume="Circ1";
    c->tip="Circ";
    c->data="1 octombrie";
    c->ora="11:11";
    c->durata=50;
    c->nrLocuri=50;
    c->nrprestatii = 1;
    c->pauza = 3;
    c->animale.push_back("Tigru");
    c->animale.push_back("Pinguin");
    c->animale.push_back("Elefant");
    c->durataPrestatie = 3;
    c->set_areAnimalePericuloase();

    opera *o = new opera();
    o->nume="Opera1";
    o->tip="Opera";
    o->nrLocuri=50;
    o->gen="Dramatica";
    o->data="2 octombrie";
    o->ora="22:22";
    o->durata=(50);
    o->pauza = 20;
    o->nrActe = 2;

    actOpera act1;
    act1.solistPrincipal="Teodorian";
    act1.tipSolist="Tenor";
    act1.durataAct=30;
    o->acte.push_back(act1);

    actOpera act2;
    act2.solistPrincipal="Coliban";
    act2.tipSolist="Bass";
    act2.durataAct=50;
    o->acte.push_back(act2);

    teatruNeinteractiv *t = new teatruNeinteractiv();
    t->nume="Teatru1";
    t->tip="Teatru";
    t->gen="Dramatic";
    t->data="3 octombrie";
    t->ora="20:02";
    t->nrLocuri=50;
    t->durata=120;
    t->durataFixa = 30;
    t->regizor = "Berechet";
    t->nrActori = 2;
    t->actori.push_back("Caragiu");
    t->actori.push_back("Crotesu");

    teatruInteractiv *ti = new teatruInteractiv();
    ti->nume="ATeatru2";
    ti->tip="Teatru";
    ti->gen="Dramatic";
    ti->data="4 octombrie";
    ti->ora="00:00";
    ti->durata=150;
    ti->nrLocuri=50;
    ti->durataFixa = 30;
    ti->regizor = "Cernescu";
    ti->nrActori = 3;
    ti->actori.push_back("Vasilescu");
    ti->actori.push_back("Vraca");
    ti->actori.push_back("Papaiani");

    spectacole.push_back(c);
    spectacole.push_back(o);
    spectacole.push_back(t);
    spectacole.push_back(ti);
}
