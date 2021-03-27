#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include "BiList.h"

class BiListOperations
{
private:
    BiList* list;
    Additional* lib;
public:
    BiListOperations();
    ~BiListOperations();
    void mainLoop();
    //N lub n
    void createList();    
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
    void showList();
    //D lub d
    void removeList();
};

//KONSTRUKTOR
BiListOperations::BiListOperations(){
    this->list = nullptr;
}

//DESTRUKTOR
BiListOperations::~BiListOperations(){
    delete this->list;
}

/*********************RESZTA METOD POMOCNICZYCH****************************************/
void BiListOperations::mainLoop(){
    char option;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA LISTY\n\n"
                  << "N lub n. Stworz nowa liste\n"
                  << "1. Dodaj liczbe na poczatku listy\n"
                  << "2. Dodaj liczbe na koncu listy\n"
                  << "3. Dodaj liczbe w dowolnym miejscu listy\n"
                  << "4. Usun liczbe z poczatku listy\n"
                  << "5. Usun liczbe z konca listy\n"
                  << "6. Usun liczbe z dowolnego miejsca listy\n"
                  << "F lub f. Wypelnij liste recznie\n"
                  << "S lub s. Wyswietl liste\n"
                  << "D lub d. Usun liste\n"
                  << "X lub x. Zakoncz operacje na liscie\n\n"
                  << "Wpisz numer lub znak operacji: ";
        std::cin >> option;
        fflush(stdin);

        switch(option){
            case 'N':
                createList();
                break;
            case 'n':
                createList();
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
                showList();
                break;
            case 's':
                showList();
                break;

            case 'D':
                removeList();
                break;
            case 'd':
                removeList();
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

void BiListOperations::createList(){
    system("cls");
    if(this->list == nullptr){
        this->list = new BiList();
        std::cout << "Stworzono liste!";
        sleep(2);
    }
    else{
        char decision;
        std::cout << "Czy chcesz nadpisac obecna liste?\n"
                  << "Wpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);
        switch(decision){
            case 'T':
                system("cls");
                this->list = new BiList();
                std::cout << "Stworzono liste!";
                sleep(2);
            break;
            case 't':
                system("cls");
                this->list = new BiList();
                std::cout << "Stworzono liste!";
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

void BiListOperations::addAtTheBeginning(){
    system("cls");
    if(this->list != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->list->addAtTheBeginning(number);
            system("cls");
            std::cout << "Dodano na poczatek!";
            sleep(2);
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawna liczbe!";
            sleep(2);
        }
    }
    else{
        system("cls");
        std::cout << "Nie stworzono listy!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BiListOperations::addAtTheEnd(){
    system("cls");
    if(this->list != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            this->list->addAtTheEnd(number);
            system("cls");
            std::cout << "Dodano na koniec!";
            sleep(2);
        }
        else{
            system("cls");
            std::cout << "Wprowadzono niepoprawna liczbe!";
            sleep(1);
        }
    }
    else{
        system("cls");
        std::cout << "Nie stworzono listy!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BiListOperations::addOnPosition(){

}

void BiListOperations::removeAtTheBeginning(){

}

void BiListOperations::removeAtTheEnd(){

}
 
void BiListOperations::removeOnPosition(){

}

void BiListOperations::enterNumbers(){

}

void BiListOperations::showList(){
    system("cls");
    if(this->list != nullptr){
        this->list->showList();
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    else{
        std::cout << "Nie stworzono listy!";
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    system("cls");
}

void BiListOperations::removeList(){

}