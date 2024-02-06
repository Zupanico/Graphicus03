/********
 * Fichier: carre.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe carre
 ********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"

using namespace std;

class Carre : public Rectangle
{
public:
    // Constructeur
    Carre(int c=1, int x=0, int y=0);

    // Destructeur
    ~Carre();

    // Getteurs
    int getCote();

    // Setteurs
    void setCote(int c);

    // Methodes
    void afficher(ostream &s) override;

protected:
    int cote;
};

#endif