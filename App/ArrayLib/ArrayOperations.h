#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include "Array.h"
#include "Additional.h"

class ArrayOperations
{
private:
    /* data */
    Array *array;
    Additional *lib;
public:
    ArrayOperations();
    ~ArrayOperations();
    void mainLoop();
    //N lub n
    bool createTab();
    void createProcedure();
    //1
    void addAtTheBeginning();
    //2
    void addAtTheEnd();
    //3
    void addOnPosition();
    //4
    void removeAtTheBeginning();
    //5
    void removeAtTheEnd();
    //6
    void removeOnPosition();
    //F lub f
    void enterNumbers();
    //S lub s
    void showArray();
    //D lub d
    void removeTab();
};

//KONSTRUKTOR
ArrayOperations::ArrayOperations()
{
    this->lib = new Additional();
    this->array = nullptr;
}

//DESTRUKTOR
ArrayOperations::~ArrayOperations()
{
}

/*********************RESZTA METOD POMOCNICZYCH****************************************/
void ArrayOperations::mainLoop(){
    char number;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA TABLICY\n\n"
                  << "N lub n. Stworz nowa tablice\n"
                  << "1. Dodaj liczbe na poczatku tablicy\n"
                  << "2. Dodaj liczbe na koncu tablicy\n"
                  << "3. Dodaj liczbe w dowolnym miejscu\n"
                  << "4. Usun liczbe z poczatku tablicy\n"
                  << "5. Usun liczbe z konca tablicy\n"
                  << "6. Usun liczbe z konca tablicy\n"
                  << "F lub f. Wypelnij tablice recznie\n"
                  << "S lub s. Wyswietl tablice\n"
                  << "D lub d. Usun tablice\n"
                  << "X lub x. Zakoncz operacje na tablicy\n\n"
                  << "Wpisz numer lub znak operacji: ";
        std::cin >> number;
        fflush(stdin);
        switch(number){
            case 'N':
                createProcedure();
                break;
            case 'n':
                createProcedure();
                break;

            case '1':
                addAtTheBeginning();
                break;
            
            case '2':
                addAtTheEnd();
                break;
            
            case '3':
                addOnPosition();
                break;

            case '4':
                removeAtTheBeginning();
                break;

            case '5':
                removeAtTheEnd();
                break;
            
            case '6':
                removeOnPosition();
                break;


            case 'F':
                enterNumbers();
                break;
            case 'f':
                enterNumbers();
                break;
            
            case 'S':
                showArray();
                break;
            case 's':
                showArray();
                break;

            case 'D':
                removeTab();
                break;
            case 'd':
                removeTab();
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
                sleep(1);
                break;
        }
        system("cls");
    }
}

bool ArrayOperations::createTab(){
    system("cls");
    std::string input;
    std::cout << "Ile elementow ma miec tablica?\nWpisz: ";
    std::cin >> input;
    fflush(stdin);
    if(this->lib->isNum(input)){
        int number = std::stoi(input);
        this->array = new Array(number);
        std::cout << "Stworzono tablice!";
        sleep(1);
        system("cls");
        return true;
    }
    else{
        system("cls");
        std::cout << "Wprowadzono nieprawidlowa liczbe!";
        sleep(2);
        system("cls");
        return false;
    }
}

void ArrayOperations::createProcedure(){
    if(this->array == nullptr){
        while(!createTab()){}
    }
    else{
        char decision;
        system("cls");
        std::cout << "Czy chcesz nadpisac obecna tablice?\n"
                  << "Wpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);
        switch(decision){
            case 'T':
                while(!createTab()){}
            break;
            case 't':
                while(!createTab()){}
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

void ArrayOperations::addAtTheBeginning(){
    system("cls");
    if(this->array != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->array->addAtTheBeginning(number);
            system("cls");
            std::cout << "Dodano na poczatek!";
            sleep(1);
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawna liczbe!";
            sleep(1);
        }
    }
    else{
        system("cls");
        std::cout << "Nie stworzono tablicy!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::addAtTheEnd(){
    system("cls");
    if(this->array != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->array->addAtTheEnd(number);
            system("cls");
            std::cout << "Dodano na koniec!";
            sleep(1);
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawna liczbe!";
            sleep(1);
        }
    }
    else{
        system("cls");
        std::cout << "Nie stworzono tablicy!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::addOnPosition(){

}

void ArrayOperations::removeAtTheBeginning(){

}

void ArrayOperations::removeAtTheEnd(){

}

void ArrayOperations::removeOnPosition(){

}

void ArrayOperations::enterNumbers(){
    system("cls");
    if(this->array == nullptr){
        std::cout << "Nie stworzono tablicy!";
        sleep(1);
        system("cls");
        return;
    }
    else{
        int index = this->array->getSize();
        std::string bufor;
        std::cout << "Wprowadzaj dane:\n";
        for(int i=0; i<index; i++){
            do {
                printf("Tab[%d] = ", i);
                std::cin >> bufor;
                fflush(stdin);
                if(this->lib->isNum(bufor)){
                    int number = std::stoi(bufor);
                    this->array->setElement(i,number);
                }
                else{
                    std::cout << "\nWprowadzono niepoprawne znaki!";
                }
                printf("\n");
            } while(!(this->lib->isNum(bufor)));
        }
    }
    system("cls");
}

void ArrayOperations::showArray(){
    system("cls");
    this->array->showArray();
    std::cout << "\nWcisnij Enter, aby kontynuowac!";
    std::cin.get();
    fflush(stdin);
    system("cls");
}

void ArrayOperations::removeTab(){

}