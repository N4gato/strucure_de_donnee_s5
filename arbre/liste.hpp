
#ifndef LISTE_H
#define LISTE_H
#define faux 0
#define vrai 1
typedef int booleen;
typedef void Objet;
#define NONORDONNE 0
#define CROISSANT 1
#define DECROISSANT 2

        typedef struct element {
            Objet* reference; // r�f�rence un objet (de l'application)
            struct element* suivant; // �l�ment suivant de la liste
        } Element;

        typedef struct {
            Element* premier; // premier �l�ment de la liste
            Element* dernier; // dernier �l�ment de la liste
            Element* courant; // �l�ment en cours de traitement (parcours de liste)
            int nbElt; // nombre d'�l�ments dans la liste
            int type; // 0:simple, 1:croissant, 2:d�croissant
            int (*comparer) (Objet*, Objet*);
            char* (*toString) (Objet*);
        } Liste;

        void initListe (Liste* li, int type,char* (*toString) (Objet*),int (*comparer) (Objet*, Objet*) );
        void initListe (Liste* li);
        Liste* creerListe (int type, char* (*toString) (Objet*),int (*comparer) (Objet*, Objet*) );
        Liste* creerListe (int type);
        Liste* creerListe ();
        booleen listeVide (Liste* li);
        int nbElement (Liste* li);
        void insererEnTeteDeListe (Liste* li, Objet* objet);
        void insererEnFinDeListe (Liste* li, Objet* objet);
        // parcours de liste
        void ouvrirListe (Liste* li);
        booleen finListe (Liste* li);
        Objet* objetCourant (Liste* li);
        void listerListe (Liste* li);
        void listerListe (Liste* li, void (*f) (Objet*));
        Objet* chercherUnObjet (Liste* li, Objet* objetCherche);
        Objet* extraireEnTeteDeListe (Liste* li);
        Objet* extraireEnFinDeListe (Liste* li);
        booleen extraireUnObjet (Liste* li, Objet* objet);
        void detruireListe (Liste* li);
        void recopierListe (Liste* l1, Liste* l2);
        // LISTE ORDONNEE
        void insererEnOrdre (Liste* li, Objet* objet);
        void recopierListe (Liste* l1, Liste* l2);
#endif
