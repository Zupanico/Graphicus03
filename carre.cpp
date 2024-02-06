/********
 * Fichier: carre.cpp
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Implementation de la classe carre
 ********/
#include "carre.h"

Carre::Carre(int c, int x, int y)
{
    hauteur = c;
    largeur = c;
    cote    = c;
    ancrage.x = x;
    ancrage.y = y;
}

Carre::~Carre()
{
}

int Carre::getCote()
{
    return cote;
}

void Carre::setCote(int c)
{
    cote = c;
}

void Carre::afficher(ostream &s)
{
    s << "K " << ancrage.x << " " << ancrage.y << " " << cote << std::endl;
}
