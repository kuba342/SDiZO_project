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
    void manualPush();
    void pushN();
    void popN();
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
                  << "6. Wprowadz dane recznie i zbuduj kopiec\n"
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
                pushN();
                break;

            case '5':
                popN();
                break;
            
            case '6':
                manualPush();
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

void BinaryHeapOperations::manualPush(){
    system("cls");
    if(this->heap != nullptr && this->heap->getHeapSize() == 0){
        std::string bufor;
        std::cout << "Ile liczb chcesz wpisac do kopca?\n"
                  << "Wpisz: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->heap->setHeapSize(number);
            this->heap->newArray(number);
            
            std::string input;
            for(int i=0; i<number; i++){
                do{
                    std::cout << "Liczba nr " << i+1 << ": ";
                    std::cin >> input;
                    fflush(stdin);
                    if(this->lib->isNum(input)){
                        int in = std::stoi(input);
                        this->heap->setElement(i, in);
                    }
                    else{
                        std::cout << "\nWprowadzono niepoprawne znaki!";
                    }
                    std::cout << "\n";
                }while(!(this->lib->isNum(input)));
            }

            this->heap->buildHeap();
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawne znaki!\n"
                      << "Operacja anulowana!";
            sleep(2);
        }
    }
    else{
        std::cout << "Trzeba najpierw stworzyc kopiec!\n"
                  << "lub\n"
                  << "Istnieje juz kopiec - wtedy usun\n"
                  << "Operacja anulowana!";
        sleep(3);
    }
    system("cls");
}

void BinaryHeapOperations::pushN(){
    system("cls");
        if(this->heap != nullptr){
            std::string bufor;
            std::cout << "Ile liczb chcesz dopisac do kopca?\n"
                      << "Wpisz: ";
            std::cin >> bufor;
            fflush(stdin);
            if(this->lib->isNum(bufor)){
                int number = std::stoi(bufor);

                std::string input;
                for(int i=0; i<number; i++){
                    do{
                        std::cout << "Liczba nr " << this->heap->getHeapSize()+1 << ": ";
                        std::cin >> input;
                        fflush(stdin);
                        if(this->lib->isNum(input)){
                            int in = std::stoi(input);
                            this->heap->heapPush(in);
                        }
                        else{
                            std::cout << "\nWprowadzono niepoprawne znaki!";
                        }
                        std::cout << "\n";
                    }while(!(this->lib->isNum(input)));
                }
            }
            else{
                system("cls");
                std::cout << "Wprowadzono niepoprawne znaki!\n"
                          << "Operacja anulowana!";
                sleep(2);
            }
        }
        else{
            std::cout << "Trzeba najpierw stworzyc kopiec!\n"
                      << "Operacja anulowana!";
            sleep(2);
        }
    system("cls");
}

void BinaryHeapOperations::popN(){
    system("cls");
        if(this->heap != nullptr && this->heap->getHeapSize()>0){
            std::string bufor;

            std::cout << "Ile elementow chcesz usunac z korzenia?\n"
                      << "Wpisz: ";
            std::cin >> bufor;
            fflush(stdin);

            if(this->lib->isNum(bufor)){
                int number = std::stoi(bufor);

                if(number <= this->heap->getHeapSize()){
                    for(int i=0; i<number; i++){
                        this->heap->heapPop();
                    }
                    system("cls");
                    std::cout << "Usunieto " << number << " liczb(y) z korzenia!";
                    sleep(2);
                }
                else{
                    system("cls");
                    std::cout << "Zbyt duzo elementow chcesz usunac!\n"
                              << "Operacja anulowana!";
                    sleep(2);
                }
            }
            else{
                system("cls");
                std::cout << "Wprowadzono niepoprawne znaki!\n"
                          << "Operacja anulowana!";
                sleep(2);
            }
        }
        else{
            std::cout << "Trzeba najpierw stworzyc kopiec!\n"
                      << "lub\n"
                      << "Umiescic w nim elementy!\n"
                      << "Operacja anulowana!";
            sleep(5);
        }
    system("cls");
}