#include "pile.h"
#include "liste.hpp"
#include <stdlib.h>
#include <stdio.h>


    Entier* creerEntier (int valeur) {
        Entier* entier = new Entier();
        entier->valeur = valeur;
        return entier;
    }

    void ecrireEntier (Objet* objet) {
    Entier* entier = (Entier*) objet;
    printf ("Element: %d\n", entier->valeur);
    }

    Pile* creerPile(){
        return creerListe();
    }

    booleen pilevide(Pile* p){
        return listeVide(p);
    }

    void empiler(Pile* p,objet* objet){
        insererEnTeteDeListe(p,objet);
    }

    objet* depiler(Pile* p){
        if(pilevide(p)){
            return NULL;
        }else{
            return extraireEnTeteDeListe(p);
        }
    }

    void listerPile(Pile* p,void (*f)(objet*)){
        listerListe(p,f);
    }

    void detruirePile(Pile* p){
    detruireListe(p);
    }

