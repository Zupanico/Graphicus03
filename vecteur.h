/********
 * Fichier: vecteur.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe vecteur
 ********/

#ifndef VECTEUR_H
#define VECTEUR_H


#include "iostream"

using namespace std;
template <typename T> class Vecteur {
    // addresse du pointeur
    T* tab;

    // Capacite du vecteur
    int capacite;

    // Taille du vecteur
    int taille;

public:
    // Constructeur
    Vecteur();

    // Destructeur
    ~Vecteur();

    // Inserer
    int inserer(T valeur);
    int inserer(T valeur, int index);
    int doublerCapacite();

    // Retrait
    T retrait(int i);

    // Getteur
    T getValeur(int i);
    bool estVide();
    int getTaille();
    int getCapacite();

    // Afficher
    void afficher(ostream &s);

    // Vider
    void vider();
};

#include "vecteur.cpp"
#endif