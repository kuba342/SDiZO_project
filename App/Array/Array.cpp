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
//Zamień dwie wartości w tablicy
void Array::swap(int beginning, int end){
    int bufor;
    if(beginning>this->size || end>this->size){
        std::cout << "Nieprawidlowe indeksy";
        return;
    }
    else{
        bufor = this->table[beginning];
        this->table[beginning] = this->table[end];
        this->table[end] = bufor;
    }
}

void Array::addAtTheBeginning(int number){
    this->size++;
    int* Tab;
    Tab = new int[size];
    Tab[0] = number;
    for(int i=1; i<size; i++){
        Tab[i] = this->table[i];
    }
    delete [] table;
    this->table = Tab;
}

void Array::addAtTheEnd(int number){
    this->size++;
    int* Tab;
    Tab = new int[size];
    Tab[size-1] = number;
    for(int i=0; i<size-1; i++){
        Tab[i] = this->table[i];
    }
    delete [] table;
    this->table = Tab;
}

void Array::removeAtTheBeginning(){
    this->size--;
    int* Tab;
    Tab = new int[size];
    for(int i=0; i<size; i++){
        Tab[i] = this->table[i+1];
    }
    delete [] table;
    this->table = Tab;
}

void Array::removeAtTheEnd(){
    this->size--;
    int* Tab;
    Tab = new int[size];
    for(int i=0; i<size; i++){
        Tab[i] = this->table[i];
    }
    delete [] table;
    this->table = Tab;
}

//Metoda, która nie usuwa danych lecz dodaje nowe "pomiędzy"
void Array::addOnPosition(int number, int numberOfPosition){
    this->size++;
    int* Tab;
    Tab = new int[size];
    for(int i=0; i<numberOfPosition; i++){
        Tab[i] = this->table[i];
    }
    Tab[numberOfPosition] = number;
    if(numberOfPosition < this->size-1){
        for(int i=numberOfPosition+1; i<size; i++){
            Tab[i] = table[i-1];
        }
        delete [] table;
        this->table = Tab;
    } 
    else{
        delete [] table;
        this->table = Tab;
    }
}


void Array::removeOnPosition(int number, int numberOfPosition){
    
}

std::string Array::toString(){
    std::string bufor;
    bufor = "Zawartosc tablicy: [";
    for(int i=0; i<this->size; i++){
        bufor += " ";
        bufor += this->table[i];
        bufor += " ";
    }
    bufor+= "]\n";
    return bufor;
}


/*SETTERY I GETTERY*/
int Array::getSize(){
    return this->size;
}

int* Array::getTable(){
    return this->table;
}