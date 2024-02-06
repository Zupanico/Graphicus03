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
   couches.append(new Couche());
   couches.at(0)->ChangementEtat('A');
   coucheActive = 0;
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
   for (int i = 0; i < couches.getSize(); i++)
   {
      couches.at(i)->viderCouche();
   }
   couches.at(coucheActive)->ChangementEtat('A');
   coucheActive = 0;
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   if (index > couches.getSize() || index < 0)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   couches.at(index)->viderCouche();
   couches.at(coucheActive)->ChangementEtat('A');
   
   return true;
}

bool Canevas::activerCouche(int index)
{
   if (index >= couches.getSize() || index < 0)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   desactiverCouche(coucheActive);
   couches.at(index)->ChangementEtat('A');
   coucheActive = index;
   formeActive = 0;
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   if (index >= couches.getSize() || index < 0)
   {
      cout << "Erreur index invalide : s" << endl;
      return false;
   }
   couches.at(index)->ChangementEtat('N');
   formeActive = 0;
   return true;
}

bool Canevas::activerCoucheDerniere()
{
    return activerCouche(couches.getSize()-1);
}

bool Canevas::ajouterForme(Forme *p_forme)
{  
   
   if (!couches.at(coucheActive)->ajout(p_forme))
   {  
      return false;
   }
   formeActive = couches.at(coucheActive)->getSize() - 1;
   return true;
}

bool Canevas::retirerForme(int index)
{
   if (couches.at(coucheActive)->retirer(index) == nullptr)
   {
      cout << "Erreur index invalide : " << endl;
      return false;
   }
   return true;
}

bool Canevas::retirerFormeActive()
{
    return retirerForme(formeActive);
}

double Canevas::aire()
{
   double aireTot = 0;
   for (int i = 0; i < couches.getSize(); i++)
   {
      aireTot += couches.at(i)->aireTotale();
   }
   return aireTot;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   if (!couches.at(coucheActive)->translater(deltaX, deltaY))
   {
      return false;
   }
   return true;
}

void Canevas::afficher(ostream &s)
{
   for (int i = 0; i < couches.getSize(); i++)
   {
      s << "L ";
      s << couches.at(i)->getEtat() << endl; // \u00E9 pour é si la console le permet
      if (couches.at(i)->getEtat() != "i")
      {
          couches.at(i)->afficher(s);
      }
   }
}

void Canevas::ajouterCouche(string status)
{
    couches.append(new Couche());
    if (status == "a") {
        activerCouche(couches.getSize() - 1);
    }
    else if (status == "x") {
        desactiverCouche(couches.getSize() - 1);
    }
}

void Canevas::ajouterCouche()
{
    couches.append(new Couche());
    activerCouche(couches.getSize()-1);
}

void Canevas::supprimerCouche(int index)
{
    couches.removeAt(index);
}

void Canevas::supprimerCoucheActive()
{
    supprimerCouche(coucheActive);
    activerCouche(0);
}

int Canevas::getFormeActive()
{
    return formeActive;
}

int Canevas::getCoucheActive()
{
    return coucheActive;
}
