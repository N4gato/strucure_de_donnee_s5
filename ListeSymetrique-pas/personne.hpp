    #ifndef MDTYPES_H
    #define MDTYPES_H

    typedef char ch15 [16];
    typedef void Objet;
    // une personne
    typedef struct {
        ch15 nom;
        ch15 prenom;
    } Personne;

    Personne* creerPersonne (char* nom, char* prenom);
    Personne* creerPersonne ();
    void ecrirePersonne (Objet* objet);
    char* toStringPersonne (Objet* objet);
    int comparerPersonne (Objet* objet1, Objet* objet2);
    int menu ();

    #endif
