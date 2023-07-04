#ifndef LOGARE_H
#define LOGARE_H
#include "spectator.h"
#include "admin.h"
#include <conio.h>
template<typename T>
class logare
{
private:
    T log;
public:
    logare(T log);
    bool login();
};

template <typename T>
logare<T>::logare(T log){
    this->log=log;
}

template <typename T>
bool logare<T>::login(){
    Exceptii<int> ex;
    std::string email;
    std::string parola;
    std::cout<<"Introdu email: ";
    std::cin>>email;
    while(!ex.verificaEmailInput(email)){
        std::cout<<"Email: ";std::cin>>email;
    }
    std::cout<<"Introdu parola: ";
    char ch;
    while(1)
    {
        ch=getch();
        if(ch=='\r'){
            std::cout<<std::endl;
            break;}
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
    if(log.login(email, parola)){
        std::cout<<"Conectare reusita"<<std::endl<<std::endl<<std::endl;;
        return true;
    }
    else{
        std::cout<<"Email sau parola gresite"<<std::endl;
        return false;
    }
}

#endif // LOGARE_H
