#include <iostream>
#include "liste.hpp"
#include "pile.h"
#include <stdio.h>
#include "utility.h"
#include <windows.h>

using namespace std;

int main()
{
    system("mode con LINES=50 COLS=110");
    welcomemsg();
    Pile* p = creerPile();
    int x=15;
    int y=16;
    int z=170;
    Entier* entier1 = creerEntier(x);
    Entier* entier2 = creerEntier(y);
    Entier* entier3 = creerEntier(z);

    empiler(p,entier1);
    empiler(p,entier2);
    empiler(p,entier3);
    Entier* v1;
    Entier* v2;
    Entier* v3;
    v1 = (Entier*) depiler (p);
    v2 = (Entier*) depiler (p);
    v3 = (Entier*) depiler (p);
    printf("Le premier element\n");
    ecrireEntier (v1);
    printf("Le deusieme element\n");
    ecrireEntier (v2);
    printf("Le 3eme element\n");
    ecrireEntier (v3);
    printf("somting");
    return 0;
}
