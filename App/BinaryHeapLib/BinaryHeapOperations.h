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

    //Operacje na kopcu
    void createHeap();
    void showHeap();
    void removeHeap();
    void heapPush();
    void heapPop();
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
                  << "N lub n. Stworz nowy kopiec\n"
                  << "1. Dodaj liczbe do kopca\n"
                  << "2. Usun liczbe z korzenia\n"
                  << "3. Wczytaj dane z pliku i zbuduj kopiec\n"
                  << "4. Dodaj n liczb do kopca\n"
                  << "5. Usun z korzenia n liczb\n"
                  << "S lub s. Pokaz zawartosc kopca\n"
                  << "D lub D. Usun kopiec\n"
                  << "X lub x. Zakoncz operacje na kopcu\n\n"
                  << "Wpisz numer lub znak operacji: ";
        
        std::cin >> operation;
        fflush(stdin);

        switch(operation){
            case 'N':
                createHeap();
                break;
            case 'n':
                createHeap();
                break;
            
            case '1':
                heapPush();
                break;
            
            case '2':
                heapPop();
                break;
            
            case '3':
                
                break;

            case '4':
                
                break;

            case '5':
                
                break;
            

            case 'S':
                showHeap();
                break;
            case 's':
                showHeap();
                break;

            case 'D':
                removeHeap();
                break;
            case 'd':
                removeHeap();
                break;

            case 'X':
                system("cls");
                return;
                break;
            case 'x':
                system("cls");
                return;
                break;

            default:
                system("cls");
                std::cout << "Niepoprawny numer operacji!";
                sleep(2);
                break;
        }
        system("cls");
    }
}

void BinaryHeapOperations::createHeap(){
    system("cls");
    if(this->heap == nullptr){
        this->heap = new BinaryHeap();
        std::cout << "Stworzono kopiec binarny! ";
        sleep(2);
    }
    else{
        char decision;
        std::cout << "Czy chcesz nadpisac obecny kopiec?\n"
                  << "Wpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);
        switch(decision){
            case 'T':
                system("cls");
                this->heap = new BinaryHeap();
                std::cout << "Stworzono kopiec binarny!";
                sleep(2);
            break;
            case 't':
                system("cls");
                this->heap = new BinaryHeap();
                std::cout << "Stworzono kopiec binarny!";
                sleep(2);
            break;

            case 'N':
                return;
            break;
            case 'n':
                return;
            break;

            default:
                system("cls");
                std::cout << "Niepoprawny znak!";
                sleep(1);
                system("cls");
            break;
        }
    }
    system("cls");
}

void BinaryHeapOperations::showHeap(){
    system("cls");
    if(this->heap != nullptr){
        this->heap->showBinaryHeap();
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    else{
        std::cout << "Nie stworzono kopca!\n"
                  << "Wcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    system("cls");
}

void BinaryHeapOperations::removeHeap(){
    system("cls");
    if(this->heap != nullptr){
        char decision;
        std::cout << "Czy chcesz usunac istniejacy kopiec?\nWpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);

        switch(decision){
            case 'T':
                system("cls");
                delete this->heap;
                this->heap = nullptr;
                std::cout << "Kopiec usuniety!";
                sleep(2);
                break;
            case 't':
                system("cls");
                delete this->heap;
                this->heap = nullptr;
                std::cout << "Kopiec usuniety!";
                sleep(2);
                break;
                
            case 'N':
                return;
                break;
            case 'n':
                return;
                break;
                
            default:
                system("cls");
                std::cout << "Wprowadzono niepoprawny znak!\nAnulowano usuwanie!";
                sleep(3);
                return;
                break;
        }
    }
    else{
        std::cout << "Nie stworzono kopca - operacja anulowana!";
        sleep(2);
    }
    system("cls");
}

void BinaryHeapOperations::heapPush(){
    system("cls");
    if(this->heap != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->heap->heapPush(number);
            system("cls");
            std::cout << "Dodano do kopca!";
            sleep(2);
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawna liczbe!";
            sleep(2);
        }
    }
    else{
        std::cout << "Nie stworzono kopca!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BinaryHeapOperations::heapPop(){
    system("cls");
    if(this->heap!=nullptr){
        if(this->heap->getHeapSize()){
            this->heap->heapPop();
            std::cout << "Usunieto korzen!";
            sleep(2);
        }
        else{
            std::cout << "Kopiec jest pusty!\n"
                      << "Operacja anulowana!";
            sleep(2);
        }
    }
    else{
        std::cout << "Nie stworzono kopca!\n"
                  << "Operacja anulowana!";
        sleep(2);
    }
    system("cls");
}
