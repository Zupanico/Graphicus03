/********
 * Fichier: vecteur.h
 * Auteurs: Nicolas Garant
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe vecteur
 ********/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <iostream>
#include <fstream>
#include <sstream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // opérateur pour << ostream
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Node<U> &n);

    // opérateur pour << ofstream
    template <typename U>
    friend std::ofstream &operator<<(std::ofstream &ofs, const Node<U> &v);

    // opérateur pour << ostringstream
    template <typename U>
    friend std::ostringstream &operator<<(std::ostringstream &oss, const Node<U> &v);
 
    // opérateur pour >> istream
    template <typename U>
    friend std::istream &operator>>(std::istream &is, Node<U> &n);

    // opérateur pour >> ifstream
    template <typename U>
    friend std::ifstream &operator>>(std::ifstream &ifs, Node<U> &n);

    // opérateur pour >> ostringstream
    template <typename U>
    friend std::istringstream &operator>>(std::istringstream &iss, Node<U> &n);
    

    Node(const T& newData) : data(newData), next(nullptr) {}
};

// opérateur pour << ostream
template <typename U>
inline std::ostream &operator<<(std::ostream &os, const Node<U> &n)
{
    os << n.data;
    return os;
}

// opérateur pour << ofstream
template <typename U>
inline std::ofstream &operator<<(std::ofstream &ofs, const Node<U> &n)
{
    ofs << n.data;
    return ofs;
}

// opérateur pour << ostringstream
template <typename U>
inline std::ostringstream &operator<<(std::ostringstream &oss, const Node<U> &n){
    oss << n.data;
    return oss;
}

// opérateur pour >> istream
template <typename U>
inline std::istream &operator>>(std::istream &is, Node<U> &n)
{
    is >> n.data;
    return is;
}

template <typename U>
inline std::ifstream &operator>>(std::ifstream &ifs, Node<U> &n)
{
    ifs >> n.data;
    return ifs;
}

template <typename U>
inline std::istringstream &operator>>(std::istringstream &iss, Node<U> &n)
{
    iss >> n.data;
    return iss;
}

template <typename T>
class Vecteur {
private:
    Node<T>* head;
    int size;
    int currentIndex = 0;

public:
    Vecteur();

    ~Vecteur();

    T& at(int index);

    int getSize() const;

    bool isEmpty() const;

    void clear();

    T& removeAt(int index);

    void append(const T& value);

    //Opérateurs

    // <<
    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Vecteur<U> &v);

    template <typename U>
    friend std::ofstream &operator<<(std::ofstream &ofs, const Vecteur<U> &v);

    template <typename U>
    friend std::ostringstream &operator<<(std::ostringstream &oss, const Vecteur<U> &v);

    // >>
    template <typename U>
    friend std::istream &operator>>(std::istream &is, Vecteur<U> &v);

    template <typename U>
    friend std::ifstream &operator>>(std::ifstream &ifs, Vecteur<U> &v);

    template <typename U>
    friend std::istringstream &operator>>(std::istringstream &iss, Vecteur<U> &v);


    // ++
    void operator++();

    // --
    void operator--();

    // +=
    void operator+=(const T& value);

    // []
    T& operator[](int index);
};

#include "vecteur.cpp"

#endif // _VECTOR_H
