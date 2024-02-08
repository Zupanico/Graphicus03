/********
 * Fichier: vecteur.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe vecteur
 ********/

#ifndef _VECTEUR_H
#define _VECTEUR_H

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};

template <typename T>
class Vecteur {
private:
    Node<T>* head;
    int size;

public:
    Vecteur();

    ~Vecteur();

    T& at(int index);

    int getSize() const;

    bool isEmpty() const;

    void clear();

    T& removeAt(int index);

    void append(const T& value);
};

#endif // _VECTOR_H
