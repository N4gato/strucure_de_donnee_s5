#include "polynome.hpp"
#include <stdio.h>
#include <math.h>
#include "utility.h"
#include <string.h>
#include <stdlib.h>

    Monome* creerMonome (double coefficient, int exposant) {
        Monome* nouveau = new Monome();
        nouveau->coefficient = coefficient;
        nouveau->exposant = exposant;
        return nouveau;
    }
    // cr�er un mon�me par lecture du coefficient et de l'exposant
    Monome* creerMonome () {
        double coefficient;
        int exposant;
        printf ("Coefficient ? "); scanf ("%lf", &coefficient);
        printf ("Puissance ? "); scanf ("%d", &exposant);
        return creerMonome (coefficient, exposant);
    }
    // �crire un mon�me : +3.00 x**5 par exemple
    static void ecrireMonome (Monome* monome) {
        printf (" %+.2f x**%d ", monome->coefficient, monome->exposant);
    }
        // comparer deux mon�mes m1 et m2
    static int comparerMonome (Monome* m1, Monome* m2) {
        if (m1->exposant < m2->exposant) {
        return -1;
        } else if (m1->exposant == m2->exposant) {
        return 0;
        } else {
        return 1;
        }
    }
    // �crire un objet mon�me, pour listerPolynoome()
    static void ecrireMonome (Objet* objet) {
        ecrireMonome ( (Monome*) objet);
    }

    static int comparerMonome (Objet* objet1, Objet* objet2) {
        return comparerMonome ((Monome*)objet1, (Monome*)objet2);
    }

    Polynome* creerPolynome () {
        return creerListe (DECROISSANT, NULL, comparerMonome);
    }

    void insererEnOrdre (Polynome* po, Monome* nouveau) {
    // sans (Objet*), le compilateur consid�re un appel r�cursif
        insererEnOrdre (po, (Objet*) nouveau); // du module liste
    }
    // puissance ni�me d'un nombre r�el x (n entier >=0)
    // voir en 1.2.5 page 10
    static double puissance (double x, int n) {
        double resu;
        if (n==0) {
        resu = 1.0;
        } else {
        resu = puissance (x, n/2);
        if (n%2 == 0) {
        resu = resu*resu; // n pair
        } else {
        resu = resu*resu*x; // n impair
        }
        }
        return resu;
    }
    // LES POLYNOMES
    // lister le polyn�me po
    void listerPolynome (Polynome* po) {
        listerListe (po, ecrireMonome);
    }
    // valeur du polyn�me po pour un x donn�
    double valeurPolynome (Polynome* po, double x) {
        Liste* li = po;
        double resu = 0;
        if (listeVide (li) ) {
            printf ("Polyn�me nul\n"); exit (1);
        } else {
            ouvrirListe (li);
            while (!finListe (li)) {
                Monome* ptc = (Monome*) objetCourant (li);
                resu += ptc->coefficient*puissance(x, ptc->exposant);
            }
        }
        return resu;
    }
    Monome* chercherUnMonome (Polynome* po, Monome* nouveau) {
    return (Monome*) chercherUnObjet (po, nouveau);
    }
    booleen extraireMonome (Polynome* po, Monome* objet) {
    return extraireUnObjet (po, objet);
    }
    void detruirePolynome (Polynome* po) {
    detruireListe (po);
    }
