#include <iostream>
#include "polynome.hpp"
#include "utility.h"
#include <windows.h>
#include "liste.hpp"
#include <stdio.h>
using namespace std;

int menu () {
printf ("\n\nGESTION DE POLYNOMES\n\n");
printf ("0 - Fin\n");
printf ("1 - Insertion d'un monôme\n");
printf ("2 - Écriture du polynôme\n");
printf ("3 - Valeur du pôlynome pour un x donné\n");
printf ("4 - Retrait d'un monôme à partir de son exposant\n");
printf ("5 - Destruction de la liste\n");
printf ("\nVotre choix ? ");
int cod; scanf ("%d", &cod);
printf ("\n");
return cod;
}



int main()
{
    system("mode con LINES=50 COLS=110");
    welcomemsg();
    color(13,0);

Polynome* po = creerPolynome();
booleen fini = faux;
while (!fini) {
switch ( menu() ) {
case 0:
fini = vrai;
break;
case 1 : {
Monome* nouveau = creerMonome();
insererEnOrdre (po, nouveau);
} break;
case 2 : {
listerPolynome (po);
} break;
case 3 : {
printf ("A(x) = "); listerPolynome (po);
printf ("\nValeur de x ? ");
double x; scanf ("%lf", &x);
printf ("A (%.2f) = %.2f\n", x, valeurPolynome (po, x));
} break;
case 4 : {
printf ("Exposant du monôme à extraire ? ");
int exposant; scanf ("%d", &exposant);
Monome* cherche = creerMonome (0, exposant);
Monome* ptc = chercherUnMonome (po, cherche);
booleen extrait = extraireMonome (po, ptc);
if (extrait) {
printf ("extrait le monôme%.2f x** %d\n",
ptc->coefficient, ptc->exposant);
} else {
printf ("pas de monôme ayant cet exposant\n");
}
} break;
case 5 :
detruirePolynome (po);
break;
} // switch
} // while
    gotoxy(10,30);
    return 0;
}
