/********
 * Fichier: rectangle.cpp
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Implementation de la classe rectangle
 ********/

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int l, int h, int x, int y)
{
    largeur = l;
    hauteur = h;
    ancrage.x = x;
    ancrage.y = y;
}

Rectangle::~Rectangle()
{
}

int Rectangle::getHauteur()
{
    return hauteur;
}

int Rectangle::getLargeur()
{
    return largeur;
}

void Rectangle::setHauteur(int h)
{
    hauteur = h;
}

void Rectangle::setLargeur(int l)
{
    largeur = l;
}

void Rectangle::setDimension(int h, int l)
{
    hauteur = h;
    largeur = l;
}

double Rectangle::aire()
{
    return hauteur*largeur;
}

void Rectangle::afficher(ostream &s)
{
    s << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << std::endl;
}
