/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "canevas.h"

Canevas::Canevas()
{
   couches[0].ChangementEtat('A');
   coucheActive = 0;
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      couches[i].viderCouche();
   }
   couches[coucheActive].ChangementEtat('A');
   coucheActive = 0;
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   if (index > MAX_COUCHES || index < 0)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   couches[index].viderCouche();
   couches[coucheActive].ChangementEtat('A');
   
   return true;
}

bool Canevas::activerCouche(int index)
{
   if (index >= MAX_COUCHES || index < 0)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   desactiverCouche(coucheActive);
   couches[index].ChangementEtat('A');
   coucheActive = index;
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   if (index >= MAX_COUCHES || index < 0)
   {
      cout << "Erreur index invalide : s" << endl;
      return false;
   }
   couches[index].ChangementEtat('N');
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{  
   
   if (!couches[coucheActive].ajout(p_forme))
   {  
      return false;
   }
   return true;
}

bool Canevas::retirerForme(int index)
{
   if (couches[coucheActive].retirer(index) == nullptr)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   return true;
}

double Canevas::aire()
{
   double aireTot = 0;
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      aireTot += couches[i].aireTotale();
   }
   return aireTot;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   if (!couches[coucheActive].translater(deltaX, deltaY))
   {
      return false;
   }
   return true;
}

void Canevas::afficher(ostream &s)
{
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      s << "----- Couche " << i << " -----" << endl;
      s << "Etat: " << couches[i].getEtat() << endl; // \u00E9 pour é si la console le permet
      if (couches[i].getEtat() == "initialise")
      {
         s << "Couche: vide"<<endl;
      }
      else
      {
         couches[i].afficher(s);
      }
   }
}
