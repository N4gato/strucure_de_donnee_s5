#include "graphmat.h"
#include <stdlib.h>
#include <string.h>

#define INFINI INT_MAX

static void razMarque (GrapheMat* graphe) {
    for (int i=0; i<graphe->n; i++) graphe->marque [i] = faux;
}

static int rang (GrapheMat* graphe, NomSom nom) {
int i = 0;
booleen trouve = faux;
while ( (i<graphe->n) && !trouve) {
trouve = strcmp (graphe->nomS [i], nom) == 0;
if (!trouve) i++;
}
return trouve ? i : -1;
}

GrapheMat* creerGrapheMat (int nMax, int value) {
// allocation de graphe
GrapheMat* graphe = (GrapheMat*) malloc (sizeof (GrapheMat));
graphe->n = 0;
graphe->nMax = nMax;
graphe->value = value;
graphe->nomS = (NomSom*) malloc (sizeof(NomSom) *nMax);
graphe->marque = (booleen*) malloc (sizeof(booleen) *nMax);
graphe->element = (int*) malloc (sizeof(int)*nMax*nMax);
graphe->valeur = (int*) malloc (sizeof(int)*nMax*nMax);
// initialisation par défaut
for (int i=0; i<nMax; i++) {
for (int j=0; j<nMax; j++) {
graphe->element [i*nMax+j] = faux;
graphe->valeur [i*nMax+j] = INFINI;
}
}
for (int i=0; i<nMax; i++) graphe->valeur [i*nMax+i] = 0;
razMarque (graphe);
return graphe;
}

// désallocation d'un graphe
void detruireGraphe (GrapheMat* graphe) {
free (graphe->nomS);
free (graphe->marque);
free (graphe->element);
free (graphe->valeur);
free (graphe);
}

void ajouterUnSommet (GrapheMat* graphe, NomSom nom) {
if (rang (graphe, nom) == -1) {if (graphe->n < graphe->nMax) {
strcpy (graphe->nomS [graphe->n++], nom);
} else {
printf ("\nNombre de sommets > %d\n", graphe->nMax);
}
} else {
printf ("\n%s déjà défini\n", nom);
}
}

void ecrireGraphe (GrapheMat* graphe) {
int nMax = graphe->nMax;
for (int i=0; i<graphe->n; i++) printf ("%s ", graphe->nomS[i]);
printf (";\n");
for (int i=0; i<graphe->n; i++) {
printf ("\n%s : ", graphe->nomS[i]);
for (int j=0; j<graphe->n; j++) {
if (graphe->element [i*nMax+j] == vrai) {
printf ("%s ", graphe->nomS[j]) ;
if (graphe->value) {
printf (" (%3d) ", graphe->valeur [i*nMax+j] );
}
}
}
printf (";");
}
}

static void profondeur (GrapheMat* graphe, int numSommet, int niveau) {
int nMax = graphe->nMax;
graphe->marque [numSommet] = vrai;
for (int i=1; i<niveau; i++) printf ("%5s", " ");
printf ("%s\n", graphe->nomS [numSommet]);
for (int i=0; i<graphe->n; i++) {
if ( (graphe->element [numSommet*nMax+i] == vrai)
&& !graphe->marque [i] ) {
profondeur (graphe, i, niveau+1);
}
}
}
// marque pourrait contenir le numéro d'ordre de visite du sommet;
// -1 si pas visité; numéro d'ordre sinon
void parcoursProfond (GrapheMat* graphe) {
razMarque (graphe);
for (int i=0; i<graphe->n; i++) {
if (!graphe->marque [i]) profondeur (graphe, i, 1);
}
}
void ajouterUnArc (GrapheMat* graphe, NomSom somD, NomSom somA, int cout) {
int nMax = graphe->nMax;
int rd = rang (graphe, somD);
int rg = rang (graphe, somA);
graphe->element [rd*nMax+rg] = vrai;
graphe->valeur [rd*nMax+rg] = cout;
}
