#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <iostream>

using namespace std; 


template <class T>

SimpleList<T>::SimpleList(){
    numElements = 0;
    elements = new T[CAPACITY];
    
}

template <class T>

SimpleList<T>::~SimpleList()
{
    delete[] elements;
}

template <class T>
T SimpleList<T> :: at(int index) const throw(InvalidIndexException){
    if (index > CAPACITY || index<0 || index >numElements-1){

        throw InvalidIndexException();

    }
    
        return elements[index];
    }


// why am I getting red 
template <class T>

bool SimpleList<T> :: empty() const{
    if (numElements == 0){
        return true;
    }
    return false;
}

template <class T>
T SimpleList<T> :: first() const throw(EmptyListException){
    if (empty()){
       throw EmptyListException ();
   
    }
    
        return elements[0];
    
}

template <class T>
T SimpleList<T> :: last() const throw (EmptyListException){
    if (empty()){
       
        throw EmptyListException();
    }
        return elements[numElements-1];
    }



template <class T>

int SimpleList<T> :: getNumElements() const{
    return numElements;
}

template <class T>

void SimpleList<T> ::insert(T item) throw(FullListException){
    if (getNumElements() == CAPACITY){
       
        throw FullListException();

    }
    elements[getNumElements()]=item;

}

template <class T>

void SimpleList<T> :: remove(int index) throw (InvalidIndexException, EmptyListException){
    if (empty ()){
        throw EmptyListException();
    }
    if (index > CAPACITY || index < 0|| index >numElements-1){

        throw InvalidIndexException();

    }

    for (int i = index; i<=getNumElements()-1; i--){
        elements[i] = elements[i+1];
    }
    numElements += -1;

}