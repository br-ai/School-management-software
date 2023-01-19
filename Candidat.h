#ifndef CANDIDAT_H_INCLUDED
#define CANDIDAT_H_INCLUDED
#include <vector>

//creation de la classe candidat
    class Candidat
    {

    protected:

        //variable membre
        int cni;
        char nom[20];
        char prenom[20];
        int age;
        double moyenne;
        int decision;
        double note[4]; //gestion des notes


   public:

        Candidat(); //constructeur
        ~Candidat(); //destructeur

        //gestion des notes
        void afficher_notes();
        void afficher_tout_notes();
        void rechercher_notes();

      void afficher_merite();

       //
        void ajouter();
        void afficher();

        //fonction pour la manipulation des fichiers
        void ajouterf();

        //gestion des candidats
        void afficher_tout();
        int chercher(int);
        void supprimer(int);
        void modifier(int);
        void rechercher();


    };



#endif // CANDIDAT_H_INCLUDED
