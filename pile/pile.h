#ifndef PILE_H
#define PILE_H
#include "liste.hpp"


#define faux   0
#define vrai   1
typedef int    booleen;

typedef void objet;


#define NONORDONNE  0
#define CROISSANT   1
#define DECROISSANT 2

typedef Liste Pile;

typedef struct {
int valeur;
} Entier;

Entier* creerEntier (int valeur);
void ecrireEntier (Objet* objet);


Pile* creerPile();
booleen pilevide(Pile* p);
void empiler(Pile* p, objet* objet);
objet* depiler(Pile* p);
void listerPile(Pile* p,void (*f) (objet*));
void detruirePile(Pile* p);


#endif // PILE_H
