#pragma once

#include <iostream>
#include <math.h>

class BinaryHeap
{
private:
    int* array;
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
    this->heapSize = 0;
    this->array = new int[this->getHeapSize()];
}

BinaryHeap::BinaryHeap(int size){
    this->array = new int[size];
    this->heapSize = 0;
}

BinaryHeap::~BinaryHeap(){
    delete [] this->array;
}

/**************RESZTA METOD*********************/
void BinaryHeap::swap(int index1, int index2){
    int bufor;
    if(index1 > this->getHeapSize() || index2 > this->getHeapSize()){
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
    int i = floor(this->getHeapSize()/2);

    for(int i; i>=0; i--){
        this->heapify(i);
    }
}

//Dla tych metod należy sprawdzić czy wywołano wcześniej metodę buildHeap() 
//w operacjach
void BinaryHeap::heapPush(int number){
    
    if(this->getHeapSize() == 0){
        this->heapSize++;
        this->array = new int[this->getHeapSize()];
        this->setElement(0, number);
    }
    else{
        this->heapSize++;
        int i = this->getHeapSize();

        //Alokacja pamięci
        int* Tab;
        Tab = new int[i];
        Tab[i-1] = number;
        for(int j=0; j<i-1; j++){
            Tab[j] = this->array[j];
        }
        delete [] array;
        this->array = Tab;
        //Koniec alokacji nowego obszaru

        while(i>0 && this->getElement(parent(i)) < number){
            //this->setElement(i-1, this->getElement(this->parent(i)));
            this->array[i] = this->array[this->parent(i)];
            i = this->parent(i);
        }

        this->setElement(i, number);
    }
    
    
    /*
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
    //Dalsza część procedury
    j = (i-1)/2;

    while(i>0 && (this->array[i] < number)){
        this->setElement(i, this->getElement(j));
        i = j;
        j = (i-1)/2;
    }
    this->setElement(i,number);*/
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

/**************SETTERY I GETTERY*****************/

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
