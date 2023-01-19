#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include "Candidat.h"
#include "Admis.h"

using namespace std;

//constructeur par defaut de la classe
 Candidat::Candidat()
 {

 }

Candidat::~Candidat()
{

}


    //implementation des fonctions

    void Candidat::ajouter()//ajouter un candidat
    {
        int num; int to;
        cout << "entrer les informations de l'etudiant" << endl;
        cout << "cni" << endl;

        while (!( cin >> to ) || to < 0 )
    {
        if (cin.eof())
        {
            cout << "une erreur est survenue" << endl;
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
     num = to ;

        while(chercher(num)==1) //on verifie si le candidat n'existe pas deja
        {
            cout << "le candidat existe deja" <<endl;
            cout << "entrer nouvelle valeur" <<endl;
             cin >>num;
        }
        cni = num;

        //----recupere les infos du candidat--------

        cout << "nom" << endl;
        cin.ignore();
        cin.getline(nom,19);
        cout << "prenom" << endl;
        cin.getline(prenom,19);
        cout << "age" << endl;

 while (!( cin >> age ) || age < 0 )
    {
        if (cin.eof())
        {
            cout << "une erreur est survenue" << endl;
        }
        else if(cin.fail())
        {
            cout << "Saisie incorrecte, recommencez : " << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "L'AGE doit etre un nombre positif, recommencez : " << endl;
        }
    }

        cout << "entrer les notes" << endl;
        cout << "maths" << endl;

         while (!( cin >> note[0] ) || note[0] < 0 || note[0] > 20  )
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
            cout << "La NOTE doit etre comprise entre 0 et 20, recommencez : " << endl;
        }
    }
        cout << "physique" << endl;

         while (!( cin >> note[1] ) || note[1] < 0 || note[1] > 20  )
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
            cout << "La NOTE doit etre comprise entre 0 et 20, recommencez : " << endl;
        }
    }
        cout << "anglais" << endl;

         while (!( cin >> note[2] ) || note[2] < 0 || note[2] > 20  )
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
            cout << "La NOTE doit etre comprise entre 0 et 20, recommencez : " << endl;
        }
    }
        cout << "culture" << endl;
         while (!( cin >> note[3] ) || note[3] < 0 || note[3] > 20  )
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
            cout << "La NOTE doit etre comprise entre 0 et 20, recommencez : " << endl;
        }
    }

    //--------ecris dans le fichier notes.txt--------------
     ofstream fout("Note.txt",ios::app);
   if(fout)
   {
       fout << "cni" << ";" << "code matiere" << ";" << "note" << endl;

       for(int i=0;i<4;i++)
       {

           fout << cni << ";" << i << ";" << note[i] << endl;
       }

    }

    //--------calcule de la moyenne a partir des notes-------
        moyenne = note[0]*5 + note[1]*5 + note[2]*3 + note[3]*2;
        moyenne /= 15;

        if(moyenne>=10&&note[0]>=10&&note[1]>=10&&note[2]>=10&&note[3]>=10)
        {
            decision = 1;
        }
        else if (moyenne<10)
        {
           decision = -1;
        }
        else
        {
            decision = 0;
        }


   if(decision==1) // si la decision vaut 1 le candidat est admis et on ecrit ses infos dans le fichier admis.txt
        {
            ofstream admis("Admis.txt",ios::app);
            if(admis)
            {
                admis << "cni" << ";" << "nom" << ";" << "prenom" << ";" << "age"  << ";" << "moyenne" << endl;
                cout <<endl;
                admis << cni << ";" << nom << ";" << prenom << ";" << age  << ";" << moyenne << endl;

            }
                 ofstream fout;
     fout.open("objet/Admis.txt",ios::app);
     fout.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     fout.close();
        }

    if(decision==-1)
     {
          ofstream fout;
     fout.open("objet/Refus.txt",ios::app);
     fout.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     fout.close();
     }

    if(decision==0)
     {
          ofstream fout;
     fout.open("objet/Ajourne.txt",ios::app);
     fout.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     fout.close();
     }



        //enregistrement des admis plus de 20 ans, on le classes dans le fichier attente
        if(decision==1 && age>=20)
        {
             ofstream attente("Attente.txt",ios::app);
            if(attente)
            {
                attente << "cni" << ";" << "nom" << ";" << "prenom"  << ";" << "moyenne" << endl;
                cout <<endl;
                attente << cni << ";" << nom << ";" << prenom <<  ";" << moyenne << endl;

            }
                 ofstream fout;
     fout.open("objet/Attente.txt",ios::app);
     fout.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     fout.close();
        }

        //enregistrement des admis moins de 20 ans
        if(decision==1 && age<20)
        {
                 ofstream jeune;
     jeune.open("objet/Jeune.txt",ios::app);
     jeune.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     jeune.close();
        }


   //------------------------------------

    string a;
    if(decision==1)
    {
        a = "admis";
    }
    else if(decision==0)
    {
        a = "ajourne";
    }
    else
    {
        a = "refuse";
    }

    cout  << endl;
    cout << "sa moyenne est de " << moyenne  << " et la decision est " << a << endl;



    //-----ecris dans le fichier candidat.txt------
    ofstream file("Candidat.txt",ios::app);
    if(file)
    {
        file << "cni" << ";" << "nom" << ";" << "prenom" << ";" << "age" << ";" << "moyenne" << ";" << "decision" <<endl;
        cout <<endl;
        file << cni << ";" << nom << ";" << prenom << ";" << age << ";" << moyenne << ";" << decision <<endl;
    }
    //-----------------------------------------

}



//----------------------

//---fonction afficher --------------

    void Candidat::afficher()
    {
        cout << endl;
        cout << "cni : " << cni << endl;
        cout << "nom : "  << nom << endl;
        cout << "prenom : " << prenom << endl;
        cout << "age : " << age << endl;
        cout << "moyenne : " << moyenne << endl;

    string a;
    if(decision==1)
    {
        a = "ADMIS";
    }
    else if(decision==0)
    {
        a = "AJOURNEE";
    }
    else
    {
        a = "REFUS";
    }
        cout << "decision : " << a <<endl;
    }

    void Candidat::afficher_notes()
    {
         cout << endl;
        cout << "cni numero " << cni << endl;

       cout << "mathematiques : " << " " << note[0] << endl;
       cout << "physique : " << " " << note[1] << endl;
       cout << "anglais : " << " " << note[2] << endl;
       cout << "culture general : " << " " << note[3] << endl;
       cout << "sa moyenne est : " << " " << moyenne << endl;


    }

  //--------------------------

    //-------------fonction ajouter dans le fichier----------
    void Candidat::ajouterf()
    {
      ofstream fout;
     fout.open("objet/Candidat.txt",ios::app);
     fout.write((char*)this,sizeof(*this)); //this est une reference sur candidat
     fout.close();
    }

    //---------------------------------------------


  //------------fonction afficher_tout les candidats----------------------
    void Candidat::afficher_tout()
    {
        cout << endl;
        cout << "--------------------------" <<endl;
        ifstream fin;
        fin.open("objet/Candidat.txt",ios::in);
        if(!fin)
        {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                afficher();
                cout  << endl;
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }

    void Candidat::afficher_tout_notes()
    {
        cout << endl;
        cout << "--------------------------" <<endl;
        ifstream fin;
        fin.open("objet/Candidat.txt",ios::in);
        if(!fin)
        {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                afficher_notes();
                cout  << endl;
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }


  //--------------------------------------------------


    //fonction de recherche renvoie 1 si la cni est dans le fichier 0 sinon, permet de verifier l'ajout et la suppression
    int Candidat::chercher(int t)
    {
        int count = 0;
        ifstream  fin;
        fin.open("objet/Candidat.txt",ios::in);
        if(!fin)
        {
            cout << "impossible d'ouvrir le fichier" <<endl;
        }
        else
        {
            //le fichier c'est bien ouvert
            //je lis tout son contenu
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()) //jusqu'a ce qu'on atteind la fin du fichier
            {
                if(t==this->cni)
                {
                    return 1;
                    count++;

                }
                fin.read((char*)this,sizeof(*this));
            }
            if(count==0)
            {

             return 0;
            }
            fin.close();
        }
    }

    //----------------------------------------------



   //-------------fonction rechercher candidat-------------

     void Candidat::rechercher()
    {
        int count = 0; int t;
        cout << "entrer la cni du candidat a rechercher" << endl;

         while (!( cin >> t ) || t < 0  )
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
        ifstream  fin;
        fin.open("objet/Candidat.txt",ios::in);
        if(!fin)
        {
            cout << "impossible d'ouvrir le fichier" <<endl;
        }
        else
        {
            //le fichier c'est bien ouvert
            //je lis tout son contenu
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()) //jusqu'a ce qu'on atteind la fin
            {
                if(t==this->cni)
                {
                    afficher();
                    count++;

                }
                fin.read((char*)this,sizeof(*this));
            }
            if(count==0)
            {

             cout << "le candidat n'existe pas ou cni invalide" << endl;
            }
            fin.close();
        }
    }
      //----------fonction rechercher les notes d'un candidat-----------------

    void Candidat::rechercher_notes()
    {
         int count = 0; int t;
        cout << "entrer la cni du candidat" << endl;

         while (!( cin >> t ) || t < 0)
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
        ifstream  fin;
        fin.open("objet/Candidat.txt",ios::in);
        if(!fin)
        {
            cout << "impossible d'ouvrir le fichier" <<endl;
        }
        else
        {
            //le fichier c'est bien ouvert
            //je lis tout son contenu
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()) //jusqu'a ce qu'on atteind la fin
            {
                if(t==this->cni)
                {
                    afficher_notes();
                    count++;

                }
                fin.read((char*)this,sizeof(*this));
            }
            if(count==0)
            {

             cout << "le candidat n'existe pas ou cni invalide" << endl;
            }
            fin.close();
        }
    }

//---------------------------------------------------




    //---------------------fonction suppression candidat------------------
    void Candidat::supprimer(int t)
    {

        if(chercher(t)==0)
        {
            cout << "cni introuvable" <<endl;

        }
        else
        {
        ifstream fin;
        ofstream fout;
        fin.open("objet/Candidat.txt",ios::app);
        if(!fin)
        {
            cout  << "impossible d'ouvrir le fichier"  << endl;
        }
        else
        {
            fout.open("objet/tempon.txt",ios::out);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(t!=cni)
                {

                    fout.write((char*)this,sizeof(*this));
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("objet/Candidat.txt");
            rename("objet/tempon.txt","objet/Candidat.txt");
          cout << "supprimer avec succes" << endl;
        }

        }
    }

   //-------------------------------------------- ------------


    //--------------fonction modifier---------------

      void Candidat::modifier(int cni)
      {
          cout <<  "pour modifier un candidat veuillez le supprimer et le rajouter a nouveau" << endl;
          supprimer(cni);
          cout << endl;
          cout << "ajout des nouvelles valeurs" << endl;
          ajouter();
          ajouterf();
          cout << endl;
          cout << "candidat supprimer et ajouter" << endl;
      }



//---------------------fonction afficher les admis par ordre de merite---------------------
     void Candidat::afficher_merite()
    {
vector<double> tab; vector<int> tup; vector<string> tip; double c; int ok = 1;int taille;
        ifstream fin;
        fin.open("objet/Candidat.txt",ios::in);
if(!fin)
  {
   cout << "impossible d'ouvrir le fichier" << endl;
  }
else
  {

    fin.read((char*)this,sizeof(*this));

             while(!fin.eof())
            {


                    tab.push_back(moyenne);
                    tup.push_back(cni);
                    tip.push_back(nom);


        fin.read((char*)this,sizeof(*this));
        }

        fin.close();

        }
      while(ok != 0)
    {

          for(int i=0;i<tab.size();i++)
          {
             if(tab[i]<tab[i+1])
             {
               c = tab[i+1];
               tab[i+1]=tab[i];
               tab[i]=c;
               i = tab.size()+1 ;
               ok = 1 ;
             }
            else
            {
            ok = 0;
            }
         }

    }
    //*****************************************************

for(int j =0;j<tab.size();j++)
{
    cout << "Numero : " << j+1 <<endl;
    cout << "cni : " << tup[j] <<endl;
    cout << "nom : " << tip[j] <<endl;
    cout << "moyenne : " << tab[j] <<endl;
    cout << endl;
}

    }


