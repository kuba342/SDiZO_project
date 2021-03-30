#pragma once

#include "BinaryHeap.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include "Additional.h"

class BinaryHeapOperations
{
private:
    BinaryHeap* heap;
    Additional* lib;

public:
    BinaryHeapOperations();
    ~BinaryHeapOperations();

    void mainLoop();
};

BinaryHeapOperations::BinaryHeapOperations(){
    this->heap = nullptr;
    this->lib = new Additional();
}

BinaryHeapOperations::~BinaryHeapOperations(){
    delete this->heap;
    delete this->lib;
}

void BinaryHeapOperations::mainLoop(){
    char operation;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA KOPCA BINARNEGO\n\n"
                  << "N lub n. Stworz nowy kopiec"
                  << "";
        
        std::cin >> operation;
        fflush(stdin);

        switch(operation){

        }
        system("cls");
    }
}
