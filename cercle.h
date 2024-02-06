/********
 * Fichier: cercle.h
 * Auteurs: Louis Dumas
 * Date: 10 janvier 2024 (creation)
 * Description: Declaration de la classe cercle
 ********/
#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

class Cercle : public Forme {
public:
    // Constructeur 
    Cercle(int r=1, int x=0, int y=0);
    // Destructeur
    ~Cercle();

    // Getteur
    int getRayon();

    // Setteur
    void setRayon(int r);

    // Methodes
    double aire()  override;
    void afficher(ostream & s)  override;

protected:
    int rayon;
};

#endif