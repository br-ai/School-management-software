#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include "Candidat.h"
#include "Admis.h"

using namespace std;
/*

*/

int menu()
{
    int choix;
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "=======================================" << endl;
    cout << "1. Afficher tous les candidats" << endl;
    cout << "2. Ajouter un candidat"  << endl;
    cout << "3. Modifier un candidat" << endl;
    cout << "4. Supprimer un candidat" << endl;
    cout << endl;
    cout << "5. Afficher les admis" << endl;
    cout << "6. Afficher les admis plus de 20ans" << endl;
     cout << "7. Afficher les admis moins de 20ans" << endl;
     cout << endl;
    cout << "8. Rechercher un candidat" << endl;
    cout << "9. Afficher les notes d'un candidat"<< endl;
       cout << endl;
     cout << "10. Afficher les candidats par ordre de merite" << endl;
      cout << "11. Afficher les pourcentages" << endl;
      cout << "12. Afficher toutes les notes"<< endl;
      cout << endl;
       cout << "13. Sortir"<< endl;
    cout << endl;
    cout << "entrer votre choix" << endl;

     while (!( cin >> choix )  )
    {
        if (cin.eof())
        {
            cout << "Une erreur est survenue" << endl;
        }
        else if(cin.fail())
        {
            cout << "Saisie incorrecte, recommencez : " << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "le choix doit etre un nombre entre 1 et 13 , recommencez : " << endl;
        }
    }
    cout  << endl;
    return choix;

}

int main()
{

Candidat candidat;
Admis admis;
int cni;

while (1)
{
    system("cls");
      switch(menu())
      {
    case 1 :
        candidat.afficher_tout();
        break;
    case 2 :
        candidat.ajouter();
        candidat.ajouterf();
        break;
    case 3 :
        cout << "entrer la cni du candidat a modifier" << endl;

         while (!( cin >> cni ) || cni < 0   )
    {
        if (cin.eof())
        {
            cout << "Une erreur est survenue" << endl;
        }
        else if(cin.fail())
        {
            cout << "Saisie incorrecte, recommencez : " << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "La CNI doit etre un nombre positif, recommencez : " << endl;
        }
    }
        admis.mod(cni);
        candidat.modifier(cni);
        break;
    case 4 :
        cout << "entrer la cni du candidat a supprimer" << endl;


         while (!( cin >> cni ) || cni < 0   )
    {
        if (cin.eof())
        {
            cout << "Une erreur est survenue" << endl;
        }
        else if(cin.fail())
        {
            cout << "Saisie incorrecte, recommencez : " << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "La CNI doit etre un nombre positif, recommencez : " << endl;
        }
    }
        candidat.supprimer(cni);
        admis.sup(cni);
        admis.supa(cni);
        admis.supj(cni);
        break;
    case 5 :
        admis.afficher_admis();
        break;
    case 6 :
        admis.afficher_attente();
        break;
    case 7 :
        admis.afficher_jeune();
        break;
    case 8 :
        candidat.rechercher();
        break;
    case 9:
        candidat.rechercher_notes();
        break;
    case 10:
        candidat.afficher_merite();
        break;
    case 11:
        admis.pourcentage();
        break;
    case 12:
        candidat.afficher_tout_notes();
        break;
    case 13:
        cout << "GOOD BYE" << endl;
        exit(0);
    default :
        cout << "choix invalide" <<endl;
        }
        cout  << endl;
        system("pause");

}



    return 0;


}
