/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"
#include "cercle.h"
#include "carre.h"
#include "rectangle.h"

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool reinitialiser();
   bool reinitialiserCouche(int index);
   
   bool activerCouche(int index);
   bool desactiverCouche(int index);
   bool activerCoucheDerniere();

   bool activerForme(int index);
   bool activerFormeDerniere();

   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   bool retirerFormeActive();

   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);

   void ajouterCouche(string);
   void ajouterCouche();
   void supprimerCouche(int);
   void supprimerCoucheActive();
 

   int getFormeActive();
   int getCoucheActive();
   int getNbCouches();
   int getNbFormes();
   int getNbFormesCoucheActive();
   double getAireCouche();
   int getCoordXForme();
   int getCoordYForme();
   double getAireFormeActive();

private:
     Vecteur<Couche*> couches;
     int coucheActive = 0;
     int formeActive = 0;
};

#endif
