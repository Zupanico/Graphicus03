/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Nicolas Garant
 * Date : 11 janvier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"

Couche::Couche()
{
}

Couche::~Couche()
{
}

bool Couche::ajout(Forme *val)
{
    if(val == nullptr){
      cout<< "Erreur ajout pointeur null : ";
      return false;
    }
    if (etat != 'A')
    {
        cout << "Erreur couche inactive : " << endl;
        return false;
    }

    v.append(val);
    return true;
}

Forme *Couche::retirer(int index)
{
    Forme *ptr;
    ptr = v.removeAt(index);
    if (ptr == nullptr) // Si ptr est null renvoie null ou si couche n'est pas active
    {   
        cout << "Erreur index invalide : " << endl;
        return nullptr;
    }
    if (etat != 'A')
    {
        cout << "Erreur couche inactive : " << endl;
        return nullptr;
    }
    return ptr;
}

Forme *Couche::getForme(int index)
{
    Forme *ptr;
    ptr = v.at(index);
    if (ptr == nullptr) // Si ptr est null renvoie null
    {   
        cout << "Erreur index invalide : " << endl;
        return nullptr;
    }
    return ptr;
}

double Couche::aireTotale()
{
    double aireTot = 0;

    if (etat == 'I') // Si la couche est initialisé alors aire = 0
    {
        return 0;
    }

    for (int i = 0; i < v.getSize(); i++) // Défile tous les éléments du vecteur
    {
        if (v.getSize() != 0) {
            aireTot += v.at(i)->aire();
        }
    }

    return aireTot;
}

string Couche::getEtat()
{
    if (etat == 'A')
    {
        return "active";
    }
    else if (etat == 'I')
    {
        return "initialise";
    }
    else if (etat == 'N')
    {
        return "inactive";
    }
    return "erreur";
}

bool Couche::ChangementEtat(char e)
{
    if(e == 'I'){

        cout << "Erreur ne peut pas changer l'état pour l'etat initialise" << endl;
        return false;
    }
    if (e != 'N' && e != 'A') // Vérifie si c'est un état possible
    {                         // Seul erreur possible
        cout << "Erreur changement d'etat : " << endl;
        return false;
    }
    etat = e;
    return true;
}

bool Couche::translater(int deltaX, int deltaY) // TODO catch erreurs // DONE
{
    try
    {
        if (etat != 'A')
        {
            cout << "Erreur couche inactive : " << endl;
            return false;
        }

        for (int i = 0; i < v.getSize(); i++) // Défile tous les éléments du vecteur
        {
            v.at(i)->translater(deltaX, deltaY);
        }
        return true;
    }
    catch (...)
    
    {   cout << "Erreur couche inactive : " << endl;
        return false;
    }
}

void Couche::afficher(ostream &s)
{

    for (int i = 0; i < v.getSize(); i++) // Défile tous les éléments du vecteur
    {
       v.at(i)->afficher(s);
    }
}

void Couche::viderCouche()
{
    v.clear();
    etat = 'I';
}