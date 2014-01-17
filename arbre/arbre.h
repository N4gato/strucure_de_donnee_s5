#ifndef ARBRE_H
#define ARBRE_H


    typedef void Objet;
    typedef int booleen;

    typedef struct noeud {
        Objet* reference;
        struct noeud* gauche;
        struct noeud* droite;
        int factEq; // facteur d'équilibre : si l'arbre est équilibré
    } Noeud;

    typedef struct {
        Noeud* racine;
        char* (*toString) (Objet*);
        int (*comparer) (Objet*, Objet*);
    } Arbre;

    Noeud* getracine (Arbre* arbre);
    Objet* getobjet (Noeud* racine);
    void setracine (Arbre* arbre, Noeud* racine);
    void settoString (Arbre* arbre, char* (*toString) (Objet*));
    void setcomparer (Arbre* arbre,int (*comparer) (Objet*, Objet*));
    Arbre* creerArbreGene ();
    void indentationPrefixee (Arbre* arbre);
    void postfixe (Arbre* arbre);
    void enLargeurParEtage (Arbre* arbre);
    int taille (Noeud* racine);
    int taille (Arbre* arbre);
    booleen estFeuille (Noeud* racine);
    static int nbFeuilles (Noeud* racine);
    int nbFeuilles (Arbre* arbre);
    void listerFeuilles (Arbre* arbre);
    int hauteur (Arbre* arbre);
    booleen egaliteArbre (Arbre* arbre1, Arbre* arbre2);





#endif // ARBRE_H
