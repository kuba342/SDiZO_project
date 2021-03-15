#include <iostream>
#include "Array.h"
#include <string>

/*KONSTRUKTORY*/
Array::Array(){
    this->size = 0;
    this->table = nullptr;
}

Array::Array(int Size){
    this->size = Size;
    this->table = new int[Size];
}

/*DESTRUKTOR*/
Array::~Array()
{
    delete [] table;
}



/*METODY POMOCNICZE*/
std::string Array::toString(){
    std::string bufor;
    bufor = "Zawartosc tablicy: [";
    for(int i=0; i<this->size; i++){
        bufor += " ";
        bufor += this->table[i];
        bufor += " ";
    }
    bufor+= "]";
    return bufor;
}


/*SETTERY I GETTERY*/
int Array::getSize(){
    return this->size;
}

int* Array::getTable(){
    return this->table;
}