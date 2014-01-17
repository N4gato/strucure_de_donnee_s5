#include <iostream>
#include <stdio.h>
#include "liste.hpp"
#include "personne.hpp"

typedef Liste ListePersonnes; // un équivalent plus mnémonique

using namespace std;

int main () {
Liste* lp = creerListe (0, toStringPersonne, comparerPersonne);
booleen fini = faux;
while (!fini) {
switch (menu() ) {
case 0:
fini = vrai;
break;
case 1 : {
Personne* nouveau = creerPersonne();
insererEnTeteDeListe (lp, nouveau);

} break;
case 2 : {
Personne* nouveau = creerPersonne();
insererEnFinDeListe (lp, nouveau);
} break;
case 3 : {
Personne* extrait = (Personne*) extraireEnTeteDeListe (lp);
if (extrait != NULL) {
printf ("Élément %s %s extrait en tête de liste",
extrait->nom, extrait->prenom);
} else {
printf ("Liste vide");
}
} break;
case 4 : {
Personne* extrait = (Personne*) extraireEnFinDeListe (lp);
if (extrait != NULL) {
printf ("Élément %s %s extrait en fin de liste",
extrait->nom, extrait->prenom);
} else {
printf ("Liste vide");
}
} break;
case 5 : {
printf ("Nom de la personne à extraire ? ");
ch15 nom; scanf ("%s", nom);
Personne* cherche = creerPersonne (nom, "?");
Personne* pp = (Personne*) chercherUnObjet (lp, cherche);
booleen extrait = extraireUnObjet (lp, pp);
if (extrait) {
printf ("Élément %s %s extrait de la liste", pp->nom, pp->prenom);
}
} break;
case 6:
listerListe (lp);
break;
case 7 : {
printf ("Nom de la personne recherchée ? ");
ch15 nom; scanf ("%s", nom);
Personne* cherche = creerPersonne (nom, "?");
Personne* pp = (Personne*) chercherUnObjet (lp, cherche);
if (pp != NULL) {
printf ("%s %s trouvée dans la liste\n", pp->nom, pp->prenom);
} else {
printf ("%s inconnue dans la liste\n", nom);
}
} break;
case 8:{
printf ("1 - Insertion en ordre croissant\n");
printf ("2 - Insertion en ordre décroissant\n");
printf ("\nVotre choix ? ");
int cd; scanf ("%d", &cd);
FILE* fe = fopen ("noms.dat", "r");
if (fe==NULL) {
printf ("Erreur ouverture de noms.dat\n");
} else {
lp = creerListe (cd, toStringPersonne, comparerPersonne);
while ( !feof (fe) ) {
ch15 nom; ch15 prenom;
fscanf (fe, "%15s%15s", nom, prenom);
Personne* nouveau = creerPersonne (nom, prenom);
insererEnOrdre (lp, nouveau);
}
fclose (fe);
listerListe (lp);
}
} break;
case 9:
detruireListe (lp);
break;
} // switch
} // while
    return 0;
}
