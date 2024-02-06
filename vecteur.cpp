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

template <typename T>
Vecteur<T>::Vecteur() : head(nullptr), size(0) {}

template <typename T>
Vecteur<T>::~Vecteur() {
    clear();
}

template <typename T>
void Vecteur<T>::push_back(const T& value) {
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

template <typename T>
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

template <typename T>
int Vecteur<T>::getSize() const {
    return size;
}

template <typename T>
bool Vecteur<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void Vecteur<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
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

template <typename T>
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

#endif