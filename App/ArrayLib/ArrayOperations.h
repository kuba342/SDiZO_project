#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include "Array.h"

class ArrayOperations
{
private:
    /* data */
    Array *array;
public:
    ArrayOperations();
    ~ArrayOperations();
    void mainLoop();
    void createTab();
    void createProcedure();
    void removeTab();
    void enterNumbers();
    void showArray();
};

ArrayOperations::ArrayOperations()
{
}

ArrayOperations::~ArrayOperations()
{
}

void ArrayOperations::mainLoop(){
    char number;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA TABLICY\n"
                  << "1. Stworz nowa tablice\n"
                  << "2. Wypelnij tablice recznie\n"
                  << "3. Wyswietl tablice\n"
                  << "4. Usun tablice\n"
                  << "X lub x. Zakoncz operacje na tablicy\n\n"
                  << "Wpisz numer lub znak operacji: ";
        std::cin >> number;
        fflush(stdin);
        switch(number){
            case '1':
                createTab();
            break;

            case '2':
                enterNumbers();
            break;

            case '3':
                showArray();
            break;

            case 'X' | 'x':
                system("cls");
                return;
            break;

            default:
                system("cls");
                std::cout << "Niepoprawny numer operacji!";
                sleep(1);
            break;
        }
        system("cls");
    }
}

void ArrayOperations::createTab(){
    system("cls");
    int number;
    std::cout << "Ile elementow ma miec tablica?\nWpisz: ";
    std::cin >> number;
    fflush(stdin);
    if(number - int(number) == 0){
        this->array = new Array(number);
        std::cout << "Stworzono tablice!";
        sleep(1);
    }
    else{
        system("cls");
        std::cout << "Wprowadzono nieprawidłowy znak!";
        sleep(2);
        system("cls");
    }
    system("cls");
}

void ArrayOperations::createProcedure(){
    if(this->array == nullptr){
        createTab();
    }
    else{
        char decision;
        while(decision != 'T' && decision != 't' && decision != 'n' && decision != 'N'){
            std::cout << "Czy chcesz nadpisać obecna tablice?\n"
                      << "Wpisz T/N: ";
            std::cin >> decision;
            switch(decision){
                case 'T' | 't':
                    createTab();
                break;

                case 'N' | 'n':
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
    }
}

void ArrayOperations::enterNumbers(){
    system("cls");
    if(this->array == nullptr){
        std::cout << "Nie stworzono tablicy!";
        sleep(2);
        system("cls");
        return;
    }
    else{
        int index = this->array->getSize();
        int bufor = 0;
        std::cout << "Wprowadzaj dane:\n";
        for(int i=0; i<index; i++){
            do {
                printf("Tab[%d] = ", i);
                std::cin >> bufor;
                fflush(stdin);
                if(bufor - int(bufor) == 0){
                    this->array->setElement(i,bufor);
                }
                else{
                    std::cout << "\nWprowadzono niepoprawne znaki!";
                }
                printf("\n");
            } while(bufor - int(bufor) != 0);

            //Tu z tą pętlą jest problem!!!!!!!
        }
    }
    system("cls");
}

void ArrayOperations::showArray(){
    system("cls");
    this->array->showArray();
    std::cout << "\nWcisnij dowolny znak, aby kontynuowac!";
    std::cin.get();
    fflush(stdin);
    system("cls");
}
