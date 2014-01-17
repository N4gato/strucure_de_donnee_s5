#include "listeS.h"


/* listesym.cpp module des listes symétriques */
#include <stdio.h>
#include <string.h> // strcmp

// comparer deux chaînes de caractères
// fournit <0 si ch1 < ch2; 0 si ch1=ch2; >0 sinon
static int comparerCar (Objet* objet1, Objet* objet2) {
return strcmp ((char*)objet1, (char*)objet2);
}
static char* toChar (Objet* objet) {
return (char*) objet;
}
static Element* creerElement () {
return new Element();
}
// initialiser une liste symétrique
void initListeSym (ListeS* ls, char* (*toString) (Objet*),
int (*comparer) (Objet*, Objet*)) {
ls->premier = NULL;
ls->dernier = NULL;
ls->toString = toString;
ls->comparer = comparer;
}
// créer et initialiser une liste symétrique
ListeS* creerListeSym (char* (*toString) (Objet*),
int (*comparer) (Objet*, Objet*)) {
ListeS* ls = new ListeS();
initListeSym (ls, toString, comparer);
return ls;
}
ListeS* creerListeSym() {
return creerListeSym (toChar, comparerCar); // par défaut
}
// la liste est-elle vide ?
booleen listeVide (ListeS* ls) {
return ls->premier == NULL;
}
// insérer "objet" en fin de la liste symétrique ls
void insererEnFinDeListeSym (ListeS* ls, Objet* objet) {
Element* nouveau = creerElement();
nouveau->reference = objet;
nouveau->suivant = NULL;
if (listeVide(ls)) { // liste symétrique vide
nouveau->precedent = NULL;
ls->premier = nouveau;
} else {
nouveau->precedent = ls->dernier;
ls->dernier->suivant = nouveau;
}
ls->dernier = nouveau;
}
// fournir un pointeur sur le premier élément de la liste
Element* premier (ListeS* ls) {
return ls->premier;
}
// fournir un pointeur sur le dernier élément de la liste
Element* dernier (ListeS* ls) {
return ls->dernier;
}
// fournir un pointeur sur le suivant de "elt"
Element* suivant (Element* elt) {
return elt==NULL ? NULL : elt->suivant;
}
// fournir le précédent de "elt"
Element* precedent (Element* elt) {
return elt==NULL ? NULL : elt->precedent;
}
// parcourir du premier vers le dernier
void parcoursListeSym (ListeS* ls, void (*f) (Objet*)) {
if (listeVide(ls)) {
printf ("Liste symétrique vide\n");
} else {
Element* ptc = premier (ls);
while (ptc != NULL) {
f (ptc->reference);
ptc = suivant (ptc);
}
}
}
// parcours inverse : du dernier vers le premier
void parcoursListeSymI (ListeS* ls, void (*f) (Objet*)) {
if (listeVide(ls)) {
printf ("Liste symétrique vide\n");
} else {
Element* ptc = dernier (ls);
while (ptc != NULL) {
f (ptc->reference);
ptc = precedent (ptc);
}
}
}
// chercher un pointeur sur l'élément contenant "objet" de la liste ls
static Element* chercherElement (ListeS* ls, Objet* objet) {
booleen trouve = faux;
Element* ptc = premier (ls);
while ( (ptc != NULL) && !trouve ) {
trouve = ls->comparer (objet, ptc->reference) == 0;
if (!trouve) ptc = suivant (ptc);
}
return trouve ? ptc : NULL;
}
// chercher un pointeur sur l'objet "objet" de la liste ls
Objet* chercherObjet (ListeS* ls, Objet* objet) {
Element* ptc = chercherElement (ls, objet);
return ptc==NULL ? NULL : ptc->reference;
}

// retirer l'élément "extrait" de la liste symétrique ls;
// plus besoin d'avoir un pointeur sur le précédent
static void extraireListeSym (ListeS* ls, Element* extrait) {
if ( (ls->premier==extrait) && (ls->dernier==extrait) ) {
// suppression de l'unique élément de ls
ls->premier = NULL;
ls->dernier = NULL;
} else if (ls->premier == extrait) {
// suppression du premier de la liste ls
ls->premier->suivant->precedent = NULL;
ls->premier = ls->premier->suivant;
} else if (ls->dernier == extrait) {
// suppression du dernier de la liste ls
ls->dernier->precedent->suivant = NULL;
ls->dernier = ls->dernier->precedent;
} else {
// suppression de extrait entre 2 éléments non nuls
extrait->suivant->precedent = extrait->precedent;
extrait->precedent->suivant = extrait->suivant;
}
}
void extraireListeSym (ListeS* ls, Objet* objet) {
Element* element = chercherElement (ls, objet);
if (element != NULL) extraireListeSym (ls, element);
}
