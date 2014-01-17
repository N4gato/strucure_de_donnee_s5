#ifndef LISTES_H
#define LISTES_H
#include <stdio.h>

typedef int booleen;
#define faux 0
#define vrai 1
typedef void Objet;
typedef struct element* PElement;

typedef struct element {
    Objet* reference;
    PElement suivant;
    PElement precedent;
} Element;

typedef struct {
    Element* premier;
    Element* dernier;
    char* (*toString) (Objet*);
    int (*comparer) (Objet*, Objet*);
} ListeS;

    void initListeSym (ListeS* ls, char* (*toString) (Objet*),int (*comparer) (Objet*, Objet*));
    ListeS* creerListeSym (char* (*toString) (Objet*),int (*comparer) (Objet*, Objet*));
    ListeS* creerListeSym ();
    booleen listeVide (ListeS* ls);
    void insererEnFinDeListeSym (ListeS* ls, Objet* objet);
    Element* premier (ListeS* ls);
    Element* dernier (ListeS* ls);
    Element* suivant (Element* elt);
    Element* precedent (Element* elt);
    void parcoursListeSym (ListeS* ls, void (*f) (Objet*));
    void parcoursListeSymI (ListeS* ls, void (*f) (Objet*));
    Objet* chercherObjet (ListeS* ls, Objet* objet);
    void extraireListeSym (ListeS* ls, Objet* objet);

#endif
