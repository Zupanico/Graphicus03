/********
 * Fichier: cercle.h
 * Auteurs: Louis Dumas
 * Date: 10 janvier 2024 (creation)
 * Description: Implementation de la classe cercle
 ********/
#include "cercle.h"

using namespace std;


Cercle::Cercle(int r, int x, int y)
{
    rayon = r;
    ancrage.x = x;
    ancrage.y = y;
}

Cercle::~Cercle()
{
}

int Cercle::getRayon()
{
    return rayon;
}

void Cercle::setRayon(int r)
{
    rayon = r;
}

double Cercle::aire()
{
    return 3.1416 * rayon * rayon; // pi r^2
}

void Cercle::afficher(ostream &s)
{
    s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon <<", aire=" << aire() << ")" << std::endl;
}