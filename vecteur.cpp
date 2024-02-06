/********
 * Fichier: vecteur.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Implementation de la classe vecteur
 ********/
#ifndef VECTEUR_CPP
#define VECTEUR_CPP
// #include "vecteur.h"

template <typename T>
inline Vecteur<T>::Vecteur()
{
    tab = new T[1];
    capacite = 2;
    taille = 0;
}

template <typename T>
Vecteur<T>::~Vecteur()
{
    delete[] tab;
}

template <typename T>
int Vecteur<T>::inserer(T valeur)
{
 
    
    try
    {
        // regarde si taille == capacite
        if (taille == capacite)
        {
            doublerCapacite();
        }

        // insere la valeur
        tab[taille] = valeur;
        

        // augemente la taille
        taille++;
    }

    catch (...)
    {
       
        // retourne un code d'erreur 1
        return 1;
    }
    
    // Sans erreur, retourne 0
    return 0;
}

template <typename T>
int Vecteur<T>::inserer(T valeur, int index)
{
    
    try
    {
        if (index == capacite)
        {
            inserer(valeur);
        }
        else
        {
            tab[index] = valeur;
        }
    }

    catch (...)
    {
        // retourne un code d'erreur 1
        return 1;
    }

    // Sans erreur, retourne 0
    return 0;
}

template <typename T>
int Vecteur<T>::doublerCapacite()
{
    try
    {
        // tableau temporaire avec double capacite
        T *temp = new T[2 * capacite];

        // copie des elements dans le nouveau tableau
        for (int i = 0; i < capacite; i++)
        {
            temp[i] = tab[i];
        }

        // supprime le tableau
        delete[] tab;

        // double la capacite APRES avoir copie les valeurs
        capacite *= 2;

        // remets les valeurs originales
        tab = temp;
    }

    catch (...)
    {
        // retourne un code d'erreur 1
        return 1;
    }

    // Sans erreur, retourne 0
    return 0;
}

template <typename T>
T Vecteur<T>::retrait(int index)
{
    
    T ptrRetrait;
    try
    {
        // conserve le prt qui est retrait

        ptrRetrait = tab[index];
        
        
        // copie les éléments
        for (int i = index; i < taille; i++)
        {
            // copie le prochain element pour deplacer le tableau
            tab[i] = tab[i + 1];
        }

        // reduit la taille
        taille--;
    }
    catch (...)
    {
        // retourne un code d'erreur 1
        //return 1;
    }

    // Sans erreur, retourne le pointeur
   
    return ptrRetrait;
}

template <typename T>
T Vecteur<T>::getValeur(int i)
{   
    try
    { // retourne la valeur à l'index
        return tab[i];
    }
    catch (...)
    {
        cout << "Erreur ne peut pas prendre la valeur : ";
        return 0;
    }
}

template <typename T>
bool Vecteur<T>::estVide()
{
    if (taille == 0)
    { // si la taille est egale a 0 -> il est vide, retourne vrai
        return true;
    }
    else
    { // si le vecteur n'est pas vide, retourne faux
        return false;
    }
}

template <typename T>
int Vecteur<T>::getTaille()
{
    return taille;
}

template <typename T>
int Vecteur<T>::getCapacite()
{
    return capacite;
}

template <typename T>
void Vecteur<T>::afficher(ostream &s)
{
    for (int i = 0; i < taille; i++)
    {
        // affiche chaque element du vecteur
        s << tab[i] << endl;
    }
}

template <typename T>
void Vecteur<T>::vider()
{   
    // supprime le tableau
    delete[] tab;
    // remets les valeurs par defaut
    capacite = 2;
    taille = 0;
    // création du taleau vide
    tab = new T[capacite];
    
}

#endif