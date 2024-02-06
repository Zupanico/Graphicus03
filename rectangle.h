/********
 * Fichier: rectangle.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe rectangle
 ********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"

using namespace std;

class Rectangle: public Forme {
public:
    // Constructeur
    Rectangle(int l=1, int h=1, int x=0, int y=0);

    // Destructeur
    ~Rectangle();
    
    // Getteurs
    int getHauteur();
    int getLargeur();

    // Setteurs
    void setHauteur(int h);
    void setLargeur(int l);
    void setDimension(int h, int l);

    // Methodes
    double aire() override;
    void afficher(ostream &s) override;
    
protected:
    int largeur;
    int hauteur;
};

#endif