#include <iostream>
#include "listeS.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personne.hpp"

using namespace std;



int menu () {
printf ("\n\nLISTES SYMETRIQUES\n\n");
printf ("0 - Fin\n");
printf ("1 - Initialisation\n");
printf ("2 - Insertion en fin de liste\n");
printf ("3 - Parcours de liste\n");
printf ("4 - Parcours inverse de liste\n");
printf ("5 - Suppression d'un élément\n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod);
printf ("\n");
return cod;
}

int main () {
ListeS* ls = creerListeSym();
booleen fini = faux;
while (!fini) {
switch (menu()) {
case 0:
fini = vrai;
break;
case 1: // initialisation de ls
initListeSym (ls, toStringPersonne, comparerPersonne);
break;
case 2 : { // insertion d'un élément
Personne* pers = creerPersonne();
insererEnFinDeListeSym (ls, pers);
} break;
case 3: // parcours de liste
parcoursListeSym (ls, ecrirePersonne);
break;
case 4: // parcours du dernier vers le premier
parcoursListeSymI (ls, ecrirePersonne);
break;
case 5 : { // extraction d'un objet à partir de son nom
printf ("Nom à extraire ? ");
ch15 nom; scanf ("%s", nom);
Personne* cherche = creerPersonne (nom, "?");
Personne* ptc = (Personne*) chercherObjet (ls, cherche);
if (ptc == NULL) {
printf ("%s inconnu\n", nom);
} else {
ecrirePersonne (ptc); // toutes les caractéristiques (nom, prénom)
extraireListeSym (ls, ptc);
}
} break;
} // switch
}
return 0;
}
