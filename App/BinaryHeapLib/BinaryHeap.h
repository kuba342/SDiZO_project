#pragma once

#include <iostream>
#include <math.h>

class BinaryHeap
{
private:
    int* array;
    int size;

    bool isBinaryHeap;
    int heapSize;

public:
    BinaryHeap();
    BinaryHeap(int size);
    ~BinaryHeap();
    //Operacje na tablicy
    void swap(int index1, int index2);
    //Operacje na kopcu
    void heapify(int index);
    void buildHeap();
    void heapPush(int number);
    void heapPop();

    //relacja rodzic - syn
    int parent(int i);
    int leftSon(int i);
    int rightSon(int i);
    //Gettery i settery
    bool getIsBinaryHeap();
    int getSize(); 
    int getElement(int index);
    int getParent(int index);
    int getLeftSon(int index);
    int getRightSon(int index);
    int getHeapSize();

    void setElement(int index, int element);
    void setHeapSize(int size);

    //wyświetlenie tablicy
    void showArray();
    //wyświetlenie kopca
    void showBinaryHeap();
};

BinaryHeap::BinaryHeap(){
    this->array = nullptr;
    this->size = 0;
    this->isBinaryHeap = false;
    this->heapSize = 0;
}

BinaryHeap::BinaryHeap(int size){
    this->array = new int[size];
    this->size = size;
    this->isBinaryHeap = false;
    this->heapSize = 0;
}

BinaryHeap::~BinaryHeap(){
    delete [] this->array;
}

/**************RESZTA METOD*********************/
void BinaryHeap::swap(int index1, int index2){
    int bufor;
    if(index1 > this->getSize() || index2 > this->getSize()){
        return;
    }
    else{
        bufor = this->getElement(index1);
        setElement(index1, this->getElement(index2));
        setElement(index2, bufor);
    }
}

//Być może jest ok - trzeba mocno przetestować te operacje
void BinaryHeap::heapify(int index){
    int left, right, largest;

    left = this->leftSon(index);
    right = this->rightSon(index);

    if(left <= this->getHeapSize() && (this->getElement(left) > this->getElement(index))){
        largest = left;
    }
    else{
        largest = index;
    }

    if(right <= this->getHeapSize() && (this->getElement(right) > this->getElement(largest))){
        largest = right;
    }

    if(largest != index){
        this->swap(index, largest);
        this->heapify(largest);
    }
}

void BinaryHeap::buildHeap(){
    this->setHeapSize(this->getSize());
    
    int i = floor(this->getSize()/2);

    for(int i; i>=0; i--){
        this->heapify(i);
    }
    this->isBinaryHeap = true;
}

//Dla tych metod należy sprawdzić czy wywołano wcześniej metodę buildHeap() 
//w operacjach
void BinaryHeap::heapPush(int number){
    int i, j;

    i = this->getHeapSize();
    this->heapSize++;
    //Przepisanie do nowej lokalizacji
    int* Tab;
    Tab = new int[this->getHeapSize()];
    for(int i=0; i<this->getHeapSize();i++){
        Tab[i] = this->array[i];
    }
    delete [] array;
    this->array = Tab;
    this->size++;
    //Dalsza część procedury
    j = this->parent(i);

    while(i>0 && (this->array[i] < number)){
        this->setElement(i, this->getElement(j));
        i = j;
        j = this->parent(i);
    }
    this->setElement(i,number);
}

void BinaryHeap::heapPop(){
    if(this->getHeapSize()>0){
        int i, j, v;
        this->heapSize--;
        //Ostatni element kopca
        v = this->getElement(this->heapSize);
        //Początek od korzenia
        i = 0;
        j = 1; //  <- lewy syn

        while(j<this->getHeapSize()){
            if(j+1<this->getHeapSize() && this->getElement(j+1) > this->getElement(j)){
                j++;
            }
            if(v >= this->getElement(j)){
                break;
            }

            this->setElement(i, this->getElement(j));
            i = j;
            j = this->rightSon(j);
        }
        this->setElement(i,v);
        //Przepisanie do nowej lokalizacji
        int* Tab;
        Tab = new int[this->getHeapSize()];
        for(int i=0; i<this->getHeapSize(); i++){
            Tab[i] = this->getElement(i);
        }
        delete [] array;
        this->array = Tab;
        this->size--;
    }
    else return;
}

/**************METODY OBLICZAJĄCE INDEKSY******/
int BinaryHeap::parent(int i){
    return i/2;
}

int BinaryHeap::leftSon(int i){
    return 2*1;
}

int BinaryHeap::rightSon(int i){
    return (2*i)+1;
}

/**************WYŚWIETL KOPIEC/TABLICE******************/
void BinaryHeap::showBinaryHeap(){
    std::cout << "Zawartosc kopca: [";
    for(int i=0; i<this->heapSize; i++){
        std::cout << " " << this->array[i] << " ";
    }
    std::cout << "]";
}

void BinaryHeap::showArray(){
    std::cout << "Zawartosc tablicy z kopcem: [";
    for(int i=0; i<this->size; i++){
        std::cout << " " << this->array[i] << " ";
    }
    std::cout << "]";
}

/**************SETTERY I GETTERY*****************/
int BinaryHeap::getSize(){
    return this->size;
}

bool BinaryHeap::getIsBinaryHeap(){
    return this->isBinaryHeap;
}

int BinaryHeap::getElement(int index){
    return this->array[index];
}

void BinaryHeap::setElement(int index, int element){
    this->array[index] = element;
}

int BinaryHeap::getParent(int index){
    return this->array[parent(index)];
}

int BinaryHeap::getLeftSon(int index){
    return this->array[leftSon(index)];
}

int BinaryHeap::getRightSon(int index){
    return this->array[rightSon(index)];
}

int BinaryHeap::getHeapSize(){
    return this->heapSize;
}

void BinaryHeap::setHeapSize(int size){
    this->heapSize = size;
}
