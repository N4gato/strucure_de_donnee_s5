#include <iostream>
#include "arbre.h"
#include <stdio.h>
using namespace std;

int main()
{
    Arbre* arbre = creerArbreGene ();
    postfixe (arbre);

    printf("\n\n\n");

    listerFeuilles (arbre);
    printf("\n\n\n");
    enLargeurParEtage(arbre);
    return 0;
}
