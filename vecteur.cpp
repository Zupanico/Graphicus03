/********
 * Fichier: vecteur.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Implementation de la classe vecteur
 ********/
#ifndef VECTEUR_CPP
#define VECTEUR_CPP
#include "vecteur.h"
#include <stdexcept>

using namespace std;

template <class T>
Vecteur<T>::Vecteur() : head(nullptr), size(0) {}

template <class T>
Vecteur<T>::~Vecteur() {
    clear();
}


template <class T>
T& Vecteur<T>::at(int index) {
    if (index >= size || head == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index; i++) {
        if (current == nullptr) {
            throw std::out_of_range("Index out of bounds");
        }
        current = current->next;
    }

    return current->data;

}

template <class T>
int Vecteur<T>::getSize() const {
    return size;
}

template <class T>
bool Vecteur<T>::isEmpty() const {
    return size == 0;
}

template <class T>
void Vecteur<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <class T>
T& Vecteur<T>::removeAt(int index) {
    if (index >= size || head == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }

    if (index == 0) {
        Node<T>* temp = head;
        head = head->next;
        size--;
        return temp->data;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = temp->next;
        size--;
        return temp->data;
    }


}

template <class T>
void Vecteur<T>::append(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    size++;
}

// implémentation de l'opérateur << en ostream
template <typename U>
std::ostream &operator<<(std::ostream &out, const Vecteur<U> &v)
{
    Node<U> *current = v.head;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}

// implémentation de l'opérateur << en ofstream
template <typename U>
std::ofstream &operator<<(std::ofstream &ofs, const Vecteur<U> &v)
{
    Node<U> *current = v.head;
    while (current != nullptr)
    {
        ofs << current->data << " ";
        current = current->next;
    }
    return ofs;
}

template <typename U>
std::ostringstream &operator<<(std::ostringstream &oss, const Vecteur<U> &v)
{
    Node<U> *current = v.head;
    while (current != nullptr)
    {
        oss << current->data << " ";
        current = current->next;
    }
    return oss;
}

// implémentation de l'opérateur >> en istream
template <typename T>
std::istream &operator>>(std::istream &is, Vecteur<T> &v)
{
    T value;
    while (is >> value)
    {
        v.append(value);
    }
    return is;
}

template <typename U>
std::ifstream &operator>>(std::ifstream &ifs, Vecteur<U> &v)
{
    U value;
    while (ifs >> value)
    {
        v.append(value);
    }
    return ifs;
}

template <typename U>
std::istringstream &operator>>(std::istringstream &iss, Vecteur<U> &v)
{
    U value;
    while (iss >> value)
    {
        v.append(value);
    }
    return iss;
}

template <class T>
void Vecteur<T>::operator++()
{   // Augmente l'index courant de 1
    ++currentIndex;
}

template <class T>
void Vecteur<T>::operator--()
{   // Decremente l'index courant de 1
    --currentIndex;
}

template <typename T>
void Vecteur<T>::operator+=(const T& value)
{
    this->append(value);
}

template <typename T>
T &Vecteur<T>::operator[](int index)
{
    return this->at(index);
}

#endif

