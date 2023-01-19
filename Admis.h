#ifndef ADMIS_H_INCLUDED
#define ADMIS_H_INCLUDED
#include "Candidat.h"

class Admis : public Candidat
{
public :
    admis();

    void afficher_admis();
    void afficher();
    void mod(int);
    void sup(int);



    void pourcentage();


         //gestion admis moins de 20 ans
    void afficher_jeune();
    void supj(int);
    void modj(int);


        //gestion admis plus de 20 ans
        void afficher_attente(); //afficher
        void supa(int); //supprimer
        void moda(int); //modifier
};



#endif // ADMIS_H_INCLUDED
