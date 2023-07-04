#ifndef MENIU_H
#define MENIU_H
#include <iostream>
#include <string>
#include "exceptii.h"
#include <vector>
#include "spectacol.h"
#include "tip_spectacol.h"
#include "spectator.h"
#include <cstdlib>
#include "logare.h"
#include "Teatru.h"
class meniu{
private:
    std::vector<Teatru> Teatre;
    std::vector<spectacol*> recomandate;
    std::vector<spectacol*> spectacole;
    spectator spect; admin adm; bool ok=0, teatruAles=0, lt=0, introdus=0, okfisier=0, afisat=0; Teatru t;
    std::vector<std::string> chitante;

    static meniu* instance;
    meniu(){}
    meniu(const meniu&) = delete;
    meniu& operator=(const meniu&) = delete;

public:
    static meniu* getInstance();
    void listaTeatre();         ///pentru prezentare
    void listaSpectacole();     ///pentru prezentare
    void alegeTeatru();
    void creare();
    int verificaOptiune(std::string);
    int verificaOptiuneAcasa(std::string);
    void afisareUser();
    void acasa();
    void optiuniUser();
    void optiuniAcasa();
    void afisareTotala();
    void recomanda();
    void dateSpectator();
    void alegeSpectacol();
    void actualizeazaRecomandari();
    void reseteazaDateUtilizator();
    std::string chitanta(std::string);
    int verificaOptiuneAdmin(std::string);
    void optiuniAdmin();
    void afisareAdmin();
    void introduceSpectacol();
    void stergeTeatru();
    void adaugaTeatru();
    void afiseazaTeatre();
    void afiseazaBilete();
};

#endif // MENIU_H
