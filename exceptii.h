#ifndef EXCEPTII_H_INCLUDED
#define EXCEPTII_H_INCLUDED
#include <iostream>
#include <typeinfo>
#include <regex>


template<typename T>
class Exceptii{

public:
    T verificaTipInput(std::string s);
    bool verificaEmailInput(std::string s);
    bool verificaOraInput(std::string s);
    bool verificaDataInput(std::string s);
};

template<typename T>
T Exceptii<T>::verificaTipInput(std::string s){
    int x;
    if(typeid(T)==typeid(x)){
        while(true){
            try{
                if(stoi(s)==stof(s))
                    return stoi(s);
                 else
                {
                    std::cout<<"Introduceti un int nu un float: ";
                    std::cin>>s;
                    continue;
                }
                }
        catch(...){
            std::cout<<"Valoarea eronata, intrduceti o valoare corecta: ";
            std::cin>>s;
        }

        }
        }
    else
        return 0;

}

template<typename T>
bool Exceptii<T>::verificaEmailInput(std::string s){
    std::regex emailRegex("^([a-zA-Z0-9]+)@([a-zA-Z0-9]+)\\.([a-zA-Z]{2,5})$");
    if(std::regex_match(s, emailRegex))
        return 1;
    else{
        std::cout<<"Emailul trebuie sa fie de forma: 'exemplu@ceva.com' \n";
        return 0;
        }
}


template<typename T>
bool Exceptii<T>::verificaOraInput(std::string s){
    std::regex oraRegex("^([01]?[0-9]|2[0-3]):[0-5][0-9]$");
    if(std::regex_match(s, oraRegex))
        return 1;
    else{
        std::cout<<"Ora trebuie sa fie de forma: '22:22' \n";
        return 0;
        }
}




template<typename T>
bool Exceptii<T>::verificaDataInput(std::string s){
    std::regex oraRegex("^(0?[1-9]|1[012])/(0?[1-9]|[12][0-9]|3[01])/[0-9]{4}$");
    if(std::regex_match(s, oraRegex))
        return 1;
    else{
        std::cout<<"Data trebuie sa fie de forma: 'Luna/Zi/An' \n";
        return 0;
        }
}









/// CELELALTE EXCEPTII


class exceptie1: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie2: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie3: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie4: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie5: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie6: public std::exception{
public:
    const char* what () const throw();
 };
class exceptie7: public std::exception{
public:
    const char* what () const throw();
 };


int f(std::string x, std::string context);

#endif // EXCEPTII_H_INCLUDED
