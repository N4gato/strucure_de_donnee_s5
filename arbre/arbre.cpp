#include "arbre.h"
#include "liste.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Noeud* cNd (Objet* objet, Noeud* gauche, Noeud* droite) {
Noeud* nouveau = new Noeud();
nouveau->reference = objet;
nouveau->gauche = gauche;
nouveau->droite = droite;
return nouveau;
}

Noeud* cNd (Objet* objet) {
return cNd (objet, NULL, NULL);
}

Noeud* cF (Objet* objet) {
return cNd (objet, NULL, NULL);
}

void initArbre (Arbre* arbre, Noeud* racine,
char* (*toString) (Objet*), int (*comparer) (Objet*, Objet*)) {
arbre->racine = racine;
arbre->toString = toString;
arbre->comparer = comparer;
}
Arbre* creerArbre (Noeud* racine, char* (*toString) (Objet*),
int (*comparer) (Objet*, Objet*)) {
Arbre* arbre = new Arbre();
initArbre (arbre, racine, toString, comparer);
return arbre;
}
static int comparerCar (Objet* objet1, Objet* objet2) {
    return strcmp ((char*) objet1, (char*) objet1);
}

static char* toChar (Objet* objet) {
    return (char*) objet;
}

Arbre* creerArbre (Noeud* racine) {
return creerArbre (racine, toChar, comparerCar);
}

Arbre* creerArbre () {
return creerArbre (NULL, toChar, comparerCar);
}
Noeud* cF (char* message) {
return cF ( (Objet*) message);
}
Noeud* cNd (char* message, Noeud* gauche, Noeud* droite) {
return cNd ( (Objet*) message, gauche, droite);
}

Arbre* creerArbreGene () {
Noeud* racine =cNd ( "Mouha",cNd ( "Bouchaib",cNd ( "Moukhtar",NULL,cNd ( "Soulika", NULL, cF ("Samir") )),cNd ( "JAlal", cF ("Nagato"), NULL)),NULL);
return creerArbre (racine);
}


Arbre* creerArbreExp () {
    Noeud* racine =cNd ( "-",cNd ( "*",cNd ("+", cF ("a"), cF ("b") ),cNd ("-", cF ("c"), cF ("d") )),cF ("e"));
    return creerArbre (racine);
}


static void prefixe (Noeud* racine, char* (*toString) (Objet*)) {
if (racine != NULL) {
printf ("%s ", toString (racine->reference));
prefixe (racine->gauche, toString);
prefixe (racine->droite, toString);
}
}

void prefixe (Arbre* arbre) {
prefixe (arbre->racine, arbre->toString);
}


static void infixe (Noeud* racine, char* (*toString) (Objet*)) {
if (racine != NULL) {
infixe (racine->gauche, toString);
printf ("%s ", toString (racine->reference));
infixe (racine->droite, toString);
}
}

void infixe (Arbre* arbre) {
infixe (arbre->racine, arbre->toString);
}


static void postfixe (Noeud* racine, char* (*toString) (Objet*)) {
if (racine != NULL) {
postfixe (racine->gauche, toString);
postfixe (racine->droite, toString);
printf ("%s ", toString (racine->reference));
}
}

void postfixe (Arbre* arbre) {
postfixe (arbre->racine, arbre->toString);
}


static void indentationPrefixee (Noeud* racine,
char* (*toString) (Objet*), int niveau) {
if (racine != NULL) {
printf ("\n");
for (int i=1; i<niveau; i++) printf ("%5s", " ");
printf ("%s ", toString (racine->reference));
indentationPrefixee (racine->gauche, toString, niveau+1);
indentationPrefixee (racine->droite, toString, niveau+1);
}
}

void indentationPrefixee (Arbre* arbre) {
indentationPrefixee (arbre->racine, arbre->toString, 1);
}

/////333333

static Noeud* trouverNoeud (Noeud* racine, Objet* objet,
    int (*comparer) (Objet*, Objet*)) {
    Noeud* pNom;
    if (racine == NULL) {
    pNom = NULL;
    } else if (comparer (racine->reference, objet) == 0) {
    pNom = racine;
    } else {
    pNom = trouverNoeud (racine->gauche, objet, comparer);
    if (pNom == NULL) pNom = trouverNoeud (racine->droite, objet,
    comparer);
    }
    return pNom;
}

Noeud* trouverNoeud (Arbre* arbre, Objet* objet) {
return trouverNoeud (arbre->racine, objet, arbre->comparer);
}

static void enLargeur (Noeud* racine, char* (*toString) (Objet*)) {
        Liste* li = creerListe();
        insererEnFinDeListe (li, racine);
    while (!listeVide (li) ) {
        Noeud* extrait = (Noeud*) extraireEnTeteDeListe (li);
        printf ("%s ", toString (extrait->reference));
    if (extrait->gauche != NULL) insererEnFinDeListe (li,extrait->gauche);
    if (extrait->droite != NULL) insererEnFinDeListe (li,extrait->droite);
    }
}



void enLargeur (Arbre* arbre) {
enLargeur (arbre->racine, arbre->toString);
}

static void enLargeurParEtage (Noeud* racine, char* (*toString) (Objet*)) {
    Liste* lc = creerListe();
    Liste* ls = creerListe();
    insererEnFinDeListe (lc, racine);
    while (!listeVide (lc)) {
        while (!listeVide (lc) ) {
                Noeud* extrait = (Noeud*) extraireEnTeteDeListe (lc);
                printf ("%s ", toString (extrait->reference));
            if (extrait->gauche != NULL) insererEnFinDeListe (ls,
                extrait->gauche);
            if (extrait->droite != NULL) insererEnFinDeListe (ls,
                extrait->droite);
        }
    printf ("\n");
    recopierListe (lc, ls);
    }
}

void enLargeurParEtage (Arbre* arbre) {
enLargeurParEtage (arbre->racine, arbre->toString);
}

int taille (Noeud* racine) {
    if (racine == NULL) {
        return 0;
    } else {
        return 1 + taille (racine->gauche) + taille (racine->droite);
    }
}

int taille (Arbre* arbre) {
    return taille (arbre->racine);
}


booleen estFeuille (Noeud* racine) {
return (racine->gauche==NULL) && (racine->droite==NULL);
}

static int nbFeuilles (Noeud* racine) {
    if (racine == NULL) {
        return 0;
    } else if ( estFeuille (racine) ) {
        return 1;
    } else {
        return nbFeuilles (racine->gauche) + nbFeuilles (racine->droite);
    }
}


int nbFeuilles (Arbre* arbre) {
    return nbFeuilles (arbre->racine);
}

static void listerFeuilles (Noeud* racine, char* (*toString) (Objet*)) {
    if (racine != NULL) {
        if (estFeuille (racine)) {
            printf ("%s ", toString (racine->reference));
        } else {
            listerFeuilles (racine->gauche, toString);
            listerFeuilles (racine->droite, toString);
        }
    }
}

void listerFeuilles (Arbre* arbre) {
listerFeuilles (arbre->racine, arbre->toString);
}

static int maxi(int a,int b){
    return a>b ? a : b;

}

static int hauteur (Noeud* racine) {
    if (racine == NULL) {
        return 0;
    } else {
        return 1 + maxi (hauteur (racine->gauche),hauteur (racine->droite) );
    }
}

int hauteur (Arbre* arbre) {
return hauteur (arbre->racine);
}


static booleen egaliteArbre (Noeud* racine1, Noeud* racine2,int (*comparer) (Objet*, Objet*)) {

    booleen resu = faux;
    if ( (racine1==NULL) && (racine2==NULL) ) {
        resu = vrai;
    } else if ( (racine1!=NULL) && (racine2!=NULL) ) {
        if (comparer (racine1->reference, racine2->reference) == 0) {
            if (egaliteArbre (racine1->gauche, racine2->gauche, comparer) ) {
            resu = egaliteArbre (racine1->droite, racine2->droite, comparer);
            }
        }
    }
    return resu;
}

booleen egaliteArbre (Arbre* arbre1, Arbre* arbre2) {
return egaliteArbre (arbre1->racine, arbre2->racine, arbre1->comparer);
}



















/*// dessin de l'arbre
// message et position d'un noeud de l'arbre
typedef struct {
char* message; // message à afficher pour ce noeud
int position; // position (n° de colonne) du noeud
} NomPos;

int posNdC = 0; // position du noeud courant : variable globale
// dupliquer l'arbre en remplaçant l'objet référencé par un objet NomPos
// contenant la chaîne de caractère à écrire et sa position.
static Noeud* dupArb (Noeud* racine, char* (*toString) (Objet*) ) {
if (racine == NULL) {
return NULL;
} else {
Noeud* nouveau = new Noeud();
NomPos* objet = new NomPos();
nouveau->reference = objet;
objet->message = toString (racine->reference);
nouveau->gauche = dupArb (racine->gauche, toString);
int lg = strlen (toString(racine->reference));
objet->position = posNdC + lg/2;
posNdC += lg;
nouveau->droite = dupArb (racine->droite, toString);
return nouveau;
}
}

static Arbre* dupArb (Arbre* arbre) {
posNdC = 0; // globale pour dupArb
Noeud* nrac = dupArb (arbre->racine, arbre->toString);
return creerArbre (nrac, arbre->toString, NULL);
}
*/
