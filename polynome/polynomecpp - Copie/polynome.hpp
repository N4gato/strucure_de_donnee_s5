#ifndef MDTYPES_H
#define MDTYPES_H
#include "liste.hpp"

    typedef struct {
        double coefficient;
        int exposant;
    } Monome;

    typedef Liste Polynome;
    Monome* creerMonome (double coefficient, int exposant);
    Monome* creerMonome ();
    Polynome* creerPolynome ();
    void insererEnOrdre (Polynome* po, Monome* nouveau);
    void listerPolynome (Polynome* po);
    double valeurPolynome (Polynome* po, double x);
    Monome* chercherUnMonome (Polynome* po, Monome* nouveau);
    booleen extraireMonome (Polynome* po, Monome* cherche);
    void detruirePolynome (Polynome* po);


#endif
