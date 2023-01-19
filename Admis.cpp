#include "Admis.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

Admis::admis()
{

}


    void Admis::afficher()
    {
        cout << endl;
        cout << "cni : " << cni << endl;
        cout << "nom : "  << nom << endl;
        cout << "prenom : " << prenom << endl;
        cout << "age : " << age << endl;
        cout << "moyenne : " << moyenne << endl;

    }



 //------------fonction afficher_tout les admis----------------------
    void Admis::afficher_admis()
    {
        cout << endl;
        cout << "--------------------------" <<endl;
        ifstream fin;
        fin.open("objet/Admis.txt",ios::in);
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


    void Admis::afficher_attente()
    {
        cout << endl;
        cout << "--------------------------" <<endl;
        ifstream fin;
        fin.open("objet/Attente.txt",ios::in);
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


    void Admis::afficher_jeune()
    {
        cout << endl;
        cout << "--------------------------" <<endl;
        ifstream fin;
        fin.open("objet/Jeune.txt",ios::in);
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




    //----------------calculer le pourcentage des admis-----------------
    void Admis::pourcentage()
    {
        double pourcentage, pourcentager,pourcentagea ; double i=0,  j=0; int k=0; int l=0;
        vector<int> tab;  vector<int> teb; vector<int> tob; vector<int> tub;


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

                    tab.push_back(cni);


        fin.read((char*)this,sizeof(*this));
            }
            i = tab.size();
            fin.close();
        }


         ifstream fan;
        fan.open("objet/Admis.txt",ios::in);
        if(!fan)
        {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
        else
        {
            fan.read((char*)this,sizeof(*this));

             while(!fan.eof())
            {

                   teb.push_back(cni);
        fan.read((char*)this,sizeof(*this));
            }
            j = teb.size();
            fan.close();
        }


         ifstream fon;
        fon.open("objet/Refus.txt",ios::in);
        if(!fon)
        {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
        else
        {
            fon.read((char*)this,sizeof(*this));

             while(!fon.eof())
            {

                   tob.push_back(cni);
        fon.read((char*)this,sizeof(*this));
            }
            k = tob.size();
            fon.close();
        }


         ifstream fun;
        fun.open("objet/Ajourne.txt",ios::in);
        if(!fun)
        {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
        else
        {
            fun.read((char*)this,sizeof(*this));

             while(!fun.eof())
            {

                   tub.push_back(cni);
        fun.read((char*)this,sizeof(*this));
            }
            l = tub.size();
            fun.close();
        }



        pourcentage = j/i;
        pourcentager = k/i;
        pourcentagea = l/i;
        pourcentage *= 100;
        pourcentager *=100;
        pourcentagea *= 100;
          cout << "TOTAL DE CANDIDATS : " << i << endl;
          cout  << endl;
        cout << "nombre d'admis est : " << j <<" equivaut a : " << pourcentage <<"%" << endl;
        cout << "nombre d'echoues est : " << k <<" equivaut a : " << pourcentager <<"%" << endl;
        cout << "nombre d'ajournes est : " << l <<" equivaut a : " << pourcentagea <<"%" << endl;

        }

          //----------------supprimer les admis--------------
        void Admis::sup(int t)
        {

        ifstream fin;
        ofstream fout;
        fin.open("objet/Admis.txt",ios::app);
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
            remove("objet/Admis.txt");
            rename("objet/tempon.txt","objet/Admis.txt");

        }
        //suppression dans les echoues et ajournes
            ifstream fen;
        ofstream feut;
        fen.open("objet/Refus.txt",ios::app);
        if(!fen)
        {
            cout  << "impossible d'ouvrir le fichier"  << endl;
        }
        else
        {
            feut.open("objet/tempon.txt",ios::out);
            fen.read((char*)this,sizeof(*this));
            while(!fen.eof())
            {
                if(t!=cni)
                {

                    feut.write((char*)this,sizeof(*this));
                }
                fen.read((char*)this,sizeof(*this));
            }
            fen.close();
            feut.close();
            remove("objet/Refus.txt");
            rename("objet/tempon.txt","objet/Refus.txt");

        }
        //suppression dans les ajournes
            ifstream fan;
        ofstream faut;
        fan.open("objet/Ajourne.txt",ios::app);
        if(!fan)
        {
            cout  << "impossible d'ouvrir le fichier"  << endl;
        }
        else
        {
            faut.open("objet/tempon.txt",ios::out);
            fan.read((char*)this,sizeof(*this));
            while(!fan.eof())
            {
                if(t!=cni)
                {

                    faut.write((char*)this,sizeof(*this));
                }
                fan.read((char*)this,sizeof(*this));
            }
            fan.close();
            faut.close();
            remove("objet/Ajourne.txt");
            rename("objet/tempon.txt","objet/Ajourne.txt");

        }

        }


      void Admis::mod(int cni)
      {

          sup(cni);
          supa(cni);
          supj(cni);

      }

       //---------supprimer dans les admis plus de 20 ans-------------
      void Admis::supa(int t)
      {

        ifstream fin;
        ofstream fout;
        fin.open("objet/Attente.txt",ios::app);
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
            remove("objet/Attente.txt");
            rename("objet/tempon.txt","objet/Attente.txt");
      }

      }
        //---------------supprimer dans les admis moins de 20 ans---------------
      void Admis::supj(int t)
      {

        ifstream fin;
        ofstream fout;
        fin.open("objet/Jeune.txt",ios::app);
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
            remove("objet/Jeune.txt");
            rename("objet/tempon.txt","objet/Jeune.txt");
      }
}

