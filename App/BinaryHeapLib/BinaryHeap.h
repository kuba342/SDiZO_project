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
    int searchKey(int key);
    //Operacje na kopcu
    void heapify(int index);
    void buildHeap();
    void heapPush(int number);
    void heapPop();
    void newArray(int size);

    //relacja rodzic - syn
    int parent(int i);
    int leftSon(int i);
    int rightSon(int i);
    //Gettery i settery
    int* getArray();
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

//Przejrzeć ten konstruktor jak będzie potrzebny
BinaryHeap::BinaryHeap(int size){
    this->array = new int[size];
    this->heapSize = size;
}

BinaryHeap::~BinaryHeap(){
    delete [] this->array;
}

/**************RESZTA METOD*********************/
void BinaryHeap::swap(int index1, int index2){
    int bufor;
    if(index1 >= this->heapSize || index2 >= this->heapSize){
        return;
    }
    else{
        bufor = this->array[index1];
        this->array[index1] = this->array[index2];
        this->array[index2] = bufor;
    }
}

//Być może jest ok - trzeba mocno przetestować te operacje
void BinaryHeap::heapify(int index){
    int left, right, largest;

    largest = index;
    left = 2*index+1;
    right = 2*index+2;

    if((left < this->heapSize) && (this->array[left] > this->array[index])){
        largest = left;
    }

    if((right < this->heapSize) && (this->array[right] > this->array[largest])){
        largest = right;
    }

    if(largest != index){
        swap(index, largest);
        heapify(largest);
    }
}

void BinaryHeap::buildHeap(){
    int i = (this->heapSize/2)-1;

    for(i; i>=0; i--){
        this->heapify(i);
    }
}

//DZIAŁA!
void BinaryHeap::heapPush(int number){
    
    if(this->getHeapSize() == 0){
        this->heapSize++;
        this->array = new int[this->getHeapSize()];
        this->setElement(0, number);
    }
    else{
        int child = this->getHeapSize();    //Indeks dziecka
        this->heapSize++;
        int parent = this->parent(child);

        //Alokacja pamięci
        int* Tab;
        Tab = new int[this->getHeapSize()];
        for(int j=0; j<child; j++){
            Tab[j] = this->array[j];
        }
        delete [] array;
        this->array = Tab;
        //Koniec alokacji nowego obszaru
        
        while(child>0 && this->array[parent] < number){
            this->array[child] = this->array[parent];
            child = parent;
            parent = this->parent(child);
        }
        this->setElement(child, number);
    }
}

//DZIAŁA!
void BinaryHeap::heapPop(){
    if(this->heapSize){
        int i, j, v;
        this->heapSize--;
        //Ostatni element kopca jako indeks pomniejszony wcześniej o 1
        v = this->array[this->heapSize];
        //v = this->getElement(this->heapSize);
        //Początek od korzenia
        i = 0; //korzeń
        j = 1; //  <- lewy syn

        while(j<this->heapSize){
            if((j+1 < this->heapSize) && (this->array[j+1] > this->array[j])){
                j++;
            }
            if(v >= this->array[j]){
                break;
            }
            this->array[i] = this->array[j];
            i = j;
            j = (2*j)+1;
        }
        this->array[i] = v;
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

void BinaryHeap::newArray(int size){
    if(this->array != nullptr){
        delete [] array;
        this->array = new int[size];
    }
    else{
        this->array = new int[size];
    }
}

int BinaryHeap::searchKey(int key){
    for(int i=0; i<this->heapSize; i++){
        if(this->array[i] == key){
            return i;
        }
    }
    return -1;  //Jeśli -1, to nie występuje
}

/**************METODY OBLICZAJĄCE INDEKSY******/
int BinaryHeap::parent(int i){
    return (i-1)/2;
}

int BinaryHeap::leftSon(int i){
    return (2*1)+1;
}

int BinaryHeap::rightSon(int i){
    return (2*i)+2;
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

int* BinaryHeap::getArray(){
    return this->array;
}
