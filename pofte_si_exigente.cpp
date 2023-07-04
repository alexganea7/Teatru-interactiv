#include "pofte_si_exigente.h"

void pofte::citire(){
    std::string raspuns, s, context;
    std::cout<<"Raspundeti la urmatoarele intrebari..."<<std::endl;
    std::cout<<"Doriti un anumit tip? ";std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns=="da"){tip=1;std::cout<<"Ziceti tipul dorit: ";std::cin>>poftaTip;
        while(raspuns!="Circ" and raspuns!="Opera" and raspuns!="Teatru"){
        try{
            if(raspuns!="Circ" and raspuns!="Opera" and raspuns!="Teatru") throw exceptie7();}
                catch(exceptie7& ob){std::cout<<ob.what()<<std::endl;}
                std::cout<<"Tip: ";std::cin>>raspuns;}
    }
    else{tip=0;}
    std::cout<<"Doriti un anumit gen? ";std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns=="da"){gen=1;std::cout<<"Ziceti genul dorit: ";std::cin>>poftaGen;}
    else{gen=0;}
    std::cout<<"Doriti o durata minima? ";std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns=="da"){timp=1;context="Durata dorita";poftaTimp=f(s,context);}
    else{timp=0;}
}

pofte::pofte()
{
    gen=0;
    tip=0;
    timp=0;
}

///-------------------------------------------------------///


void exigente::citire(){
    std::string raspuns, s, context;
    std::cout<<"Raspundeti la urmatoarele intrebari..."<<std::endl;
    std::cout<<"Exista combinatie tip-gen pe care n-o doriti?"<<" ";
    std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns == "da"){tip_gen=1;
    std::cout<<"Dati combinatia tip-gen..."<<std::endl<<"Tip: ";std::cin>>_tip;
    while(raspuns!="Circ" and raspuns!="Opera" and raspuns!="Teatru"){
        try{
            if(raspuns!="Circ" and raspuns!="Opera" and raspuns!="Teatru") throw exceptie7();}
                catch(exceptie7& ob){std::cout<<ob.what()<<std::endl;}
                std::cout<<"Tip: ";std::cin>>raspuns;}
    std::cout<<"Gen: ";std::cin>>_gen;}
    else{tip_gen=0;}
    std::cout<<"Doriti o durata maxima?"<<" ";
    std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns == "da"){durata=1;
    std::cout<<"Ziceti durata maxima in minute: ";context = "Durata";ziDurata=f(s,context);}
    else{durata=0;}
    if(_tip!="circ"){
        std::cout<<"Daca alegeti circul, evitati animalele periculoase?"<<" ";
        std::cin>>raspuns;
        while(raspuns != "da" and raspuns != "nu"){
            std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
            std::cout<<std::endl<<"Raspuns: ";
            std::cin>>raspuns;}
        if(raspuns == "da"){animalePericuloase=1;}}
    std::cout<<"Aveti pretentii la numarul de spectatori?"<<" ";
    std::cin>>raspuns;
    while(raspuns != "da" and raspuns != "nu"){
        std::cout<<std::endl<<"Raspundeti doar cu da sau nu";
        std::cout<<std::endl<<"Raspuns: ";
        std::cin>>raspuns;}
    if(raspuns == "da"){maximSpectatori=1;
    std::cout<<"Ziceti limita spectatori: ";context="Limita spectatori";ziMaximSpectatori=f(s,context);}
    else{maximSpectatori=0;}
}


exigente::exigente(){
    tip_gen=0;
    durata=0;
    animalePericuloase=0;
    maximSpectatori=0;
    varstaLimita=0;
}

///-------------------------------------------------------///
