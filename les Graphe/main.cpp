#include <stdio.h>
#include <stdlib.h>
#include "graphmat.h"
int main(){

    GrapheMat* p = creerGrapheMat(4,0);

    NomSom s0,s1,s2,s3;
    s0="s0";
    s1="s1";
    s2="s2";
    s3="s3";

    ajouterUnSommet(p,s0);
    ajouterUnSommet(p,s1);
    ajouterUnSommet(p,s2);
    ajouterUnSommet(p,s3);

    ajouterUnArc(p,s1,s0,11);
    ajouterUnArc(p,s2,s1,116);
    ajouterUnArc(p,s1,s3,1);
    ajouterUnArc(p,s0,s2,40);







    return 0;
}
