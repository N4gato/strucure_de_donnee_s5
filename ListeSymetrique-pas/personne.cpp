    #include <stdio.h>
    #include <string.h> // strcpy, strcmp
    #include "personne.hpp"
    #include <stdlib.h>
    // constructeur de Personne
    Personne* creerPersonne (char* nom, char* prenom) {
    Personne* p = new Personne();
    strcpy (p->nom, nom);
    strcpy (p->prenom, prenom);
    return p;
    }
    // lecture du nom et pr�nom
    Personne* creerPersonne () {
    printf ("Nom de la personne � cr�er ? ");
    ch15 nom; scanf ("%s", nom);
    printf ("Pr�nom de la personne � cr�er ? ");
    ch15 prenom; scanf ("%s", prenom);
    Personne* nouveau = creerPersonne (nom, prenom);
    return nouveau;
    }
    // �crire les caract�ristiques d'une personne
    void ecrirePersonne (Personne* p) {
    printf ("%s %s\n", p->nom, p->prenom);
    }
    // fournir les caract�ristiques d'une personne
    char* toStringPersonne (Personne* p) {
    char* message = (char*) malloc (30); // test � faire
    sprintf (message, "%s %s", p->nom, p->prenom);
    return message;
    }
    // comparer deux personnes
    // fournir <0 si p1 < p2; 0 si p1=p2; >0 sinon
    int comparerPersonne (Personne* p1, Personne* p2) {
    return strcmp (p1->nom, p2->nom);
    }
    void ecrirePersonne (Objet* objet) {
    ecrirePersonne ( (Personne*) objet);
    }
    char* toStringPersonne (Objet* objet) {
    return toStringPersonne ( (Personne*) objet);
    }
    int comparerPersonne (Objet* objet1, Objet* objet2) {
    return comparerPersonne ( (Personne*)objet1, (Personne*)objet2);
    }

