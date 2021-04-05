#pragma once

#include <iostream>

class Array
{
private:
    /* data */
    int* table;
    int size;
public:
    bool fullTable;
    Array();
    Array(int Size);
    ~Array();
    //Settery ii gettery
    int getSize();
    int* getTable();
    void setElement(int index, int element);
    //Operacje na elementach tablicy
    void swap(int beginning, int end);
    void addAtTheBeginning(int number);
    void addAtTheEnd(int number);
    void removeAtTheBeginning();
    void removeAtTheEnd();
    void addOnPosition(int number, int numberOfPosition);
    void removeOnPosition(int numberOfPosition);
    void showArray();
    int searchKey(int key);
};


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
        Tab[i] = this->table[i-1];
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
    for(int i=0; i<this->size; i++){
        if(i<numberOfPosition){
            Tab[i] = this->table[i];
        }
        else if(i==numberOfPosition){
            Tab[i] = number;
        }
        else{
            Tab[i] = this->table[i-1];
        }
    }
    delete [] table;
    this->table = Tab;
}

void Array::removeOnPosition(int numberOfPosition){
    this->size--;
    int* Tab;
    Tab = new int[size];
    for(int i=0; i<this->size; i++){
        if(i >= numberOfPosition){
            Tab[i] = this->table[i+1];
        }
        else{
            Tab[i] = this->table[i];
        }
    }
    delete [] table;
    this->table = Tab;
}

void Array::showArray(){
    printf("Zawartosc tablicy: [");
    for(int i=0; i<this->size; i++){
        printf(" %d ", this->table[i]);
    }
    printf("]\n");
}

int Array::searchKey(int key){
    for(int i=0; i<this->size; i++){
        if(this->table[i] == key){
            return i;
        }
    }
    return -1;  //Jeśli -1, to nie występuje
}

/*SETTERY I GETTERY*/
int Array::getSize(){
    return this->size;
}

int* Array::getTable(){
    return this->table;
}

void Array::setElement(int index, int element){
    this->table[index] = element;
}