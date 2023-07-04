#include "spectator.h"
spectator::spectator(){
    nume="";
    varsta=0;
}

std::istream& operator>>(std::istream& in, spectator& ob){
    std::string s, context;
    std::cin.ignore();
    std::cout<<"Nume: ";getline(in,ob.nume);
    context = "Varsta";
    ob.varsta=f(s,context);
    ob.exigente::citire();
    std::cout<<std::endl;
    ob.pofte::citire();
    return in;
}

void spectator::creareCont(){
    Exceptii<std::string> ex;
    std::cin.ignore();
    std::cout<<"Nume: ";getline(std::cin,nume);
    std::cout<<"Email: ";getline(std::cin,email);
    while(!ex.verificaEmailInput(email)){
        std::cout<<"Email: ";getline(std::cin,email);
    }
    std::cout<<"Parola: ";
    char ch;
    while(1)
    {
        ch=getch();
        if(ch=='\r'){
            std::cout<<std::endl;
            if(parola.size()>4)
            break;
            else
                std::cout<<"Parola nu poate fi mai mica de 4 caractere, reintroduceti parola: ";
                std::cout<<"\nParola: ";
                parola="";
            }
         else if (ch == '\b') {
            if (!parola.empty()) {
                putch('\b');
                putch(' ');
                putch('\b');
                parola.pop_back();
            }
           } else{
            parola+=ch;
            putch('*');
        }
    }
    std::cout<<std::endl<<"  Cont creat cu succes!"<<std::endl<<std::endl;
}

bool spectator::login(std::string email, std::string parola){
    return this->email == email and this->parola == parola;}
