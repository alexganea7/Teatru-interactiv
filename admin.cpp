#include "admin.h"

admin::admin(){
    nume="Admin";
    email="admin@gmail.com";
    parola="admin";
}

void admin::creareCont(){
    std::cout<<"Nume: ";getline(std::cin,nume);
    std::cout<<"Email: ";getline(std::cin,email);
    std::cout<<"Parola: ";getline(std::cin,parola);
    std::cout<<std::endl<<"  Cont creat cu succes!"<<std::endl<<std::endl;
}

bool admin::login(std::string email, std::string parola){
    return this->email == email and this->parola == parola;}
