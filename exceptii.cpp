#include "exceptii.h"
#include <iostream>


const char* exceptie1::what () const throw(){
        return "Nu pot exista mai putin de 2 acte";}


const char* exceptie2::what () const throw(){
        return "Nu pot exista mai mult de 7 acte";}


const char* exceptie3::what () const throw(){
        return "Tipul solistului poate fi doar Tenor, Bass sau Bariton";}

const char* exceptie4::what () const throw(){
        return "Valoarea nu poate fi negativa!!! Va rog sa reintroduceti valoare";}


const char* exceptie5::what () const throw(){
        return "Spectacolul introdus poate fi doar Circ, Opera sau Teatru";}


const char* exceptie6::what () const throw(){
        return "Nu exista optiunea aleasa";}


const char* exceptie7::what () const throw(){
        return "Tipul poate sa fie doar Circ, Opera, TeatruInteractiv sau TeatruNeinteractiv";}

int f(std::string x, std::string context){
    std::cout<<context<<": ";std::cin>>x;
    while(1){
    try{
    stoi(x);
    while(stoi(x)<0){
        try
    {   if(stoi(x)<0) throw exceptie4();

    }
    catch(exceptie4& ob){std::cout<<ob.what()<<std::endl;}
    std::cout<<context<<": ";std::cin>>x;
    }
    break;
    }
    catch (...){
        std::cout<<context<<" poate fi doar un numar!!!"<<std::endl;
        std::cout<<context<<": ";std::cin>>x;
    }
    }
    return stoi(x);
}
