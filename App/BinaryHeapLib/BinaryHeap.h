#pragma once

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
    ~BinaryHeap();
    //Operacje na tablicy
    void swap(int index1, int index2);
    //Operacje na kopcu
    void heapify(int index);
    void buildHeap();

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

    //wyświetlenie kopca
    void showBinaryHeap();
};

BinaryHeap::BinaryHeap(){
    this->array = nullptr;
    this->size = 0;
    this->isBinaryHeap = false;
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

    if(left <= this->getHeapSize() && this->getElement(left) > this->getElement(index)){
        largest = left;
    }
    else{
        largest = index;
    }

    if(right <= this->getHeapSize() && this->getElement(right) > this->getElement(largest)){
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

/**************WYŚWIETL KOPIEC******************/
void BinaryHeap::showBinaryHeap(){
    double level;
    level = log2(this->getHeapSize());
    

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
