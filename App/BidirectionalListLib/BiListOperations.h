#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include "BiList.h"
#include "Additional2.h"
#include <fstream>

class BiListOperations
{
private:
    BiList* list;
    Additional2* lib;
    std::string path;
    std::fstream handler;

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
    //S lub s
    void showList();
    //D lub d
    void removeList();
    void searchKey();
    
    void readFromFile();
    void readData(std::string name);    
};

//KONSTRUKTOR
BiListOperations::BiListOperations(){
    this->list = nullptr;
    this->lib = new Additional2();
    this->path = "D:/STUDIA/IV semestr/SDiZO/Projekt/SDiZO_project/App/BidirectionalListLib/";
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
                  << "K lub k. Znajdz wartosc w liscie\n"
                  << "W lub w. Wczytaj dane z pliku\n"
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
            
            case 'K':
                searchKey();
                break;
            case 'k':
                searchKey();
                break;

            case 'W':
                readFromFile();
                break;
            
            case 'w':
                readFromFile();
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
    system("cls");
    if(this->list != nullptr){
        std::string bufor;
        std::cout << "Jako ktory element umiescic liczbe?\n"
                  << "(dziala jak indeksy w tablicy)\n"
                  << "Wpisz numer: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor) && (std::stoi(bufor) < this->list->getCount())){
            int index = std::stoi(bufor);
            std::cout << "\nJaka wartosc?\nWpisz: ";
            std::cin >> bufor;
            fflush(stdin);
            if(this->lib->isNum(bufor)){
                int number = std::stoi(bufor);
                this->list->addOnPosition(this->list->getElement(index), number);
                system("cls");
                std::cout << "Dodano nowy element do listy!";
                sleep(2);
            }
            else{
                system("cls");
                std::cout << "Wprowadzone znaki nie sa liczba!";
                sleep(2);
                system("cls");
            }
        }
        else{
            system("cls");
            std::cout << "Wprowadzone znaki nie sa liczba lub zly numer kolejnosci!";
            sleep(3);
            system("cls");
        }
    }
    else{
        std::cout << "Musisz najpierw stworzyc liste!";
        sleep(2);
    }
    system("cls");
}

void BiListOperations::removeAtTheBeginning(){
    system("cls");
    if(this->list != nullptr && this->list->getCount() > 0){
        this->list->removeAtTheBeginning();
        std::cout << "Usunieto pierwszy element!";
        sleep(2);
    }
    else{
        std::cout << "Nie stworzono listy lub nie ma w niej danych!";
        sleep(2);
    }
    system("cls");
}

void BiListOperations::removeAtTheEnd(){
    system("cls");
    if(this->list != nullptr && this->list->getCount() > 0){
        this->list->removeAtTheEnd();
        std::cout << "Usunieto ostatni element!";
        sleep(2);
    }
    else{
        std::cout << "Nie stworzono listy lub nie ma w niej danych!";
        sleep(2);
    }
    system("cls");
}
 
void BiListOperations::removeOnPosition(){
    system("cls");
    if(this->list != nullptr){
        std::string bufor;
        std::cout << "Ktory w kolejnosci element (liczac od zera) usunac?\nWpisz: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor) && (std::stoi(bufor) < this->list->getCount())){
            int index = std::stoi(bufor);
            this->list->removeOnPosition(this->list->getElement(index));
            system("cls");
            std::cout << "Usunieto wskazany element!";
            sleep(2);
            system("cls");
        }
        else{
            system("cls");
            std::cout << "Wprowadzone znaki nie sa liczba lub zly numer w kolejnosci!";
            sleep(3);
            system("cls");
        }
    }
    else{
        std::cout << "Musisz najpierw stworzyc liste!";
        sleep(2);
    }
    system("cls");
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
    system("cls");
    if(this->list != nullptr){
        char decision;
        std::cout << "Czy chcesz usunac istniejaca liste?\nWpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);

        switch(decision){
            case 'T':
                system("cls");
                delete this->list;
                this->list = nullptr;
                std::cout << "Lista usunieta!";
                sleep(2);
                break;
            case 't':
                system("cls");
                delete this->list;
                this->list = nullptr;
                std::cout << "Lista usunieta!";
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
        std::cout << "Nie stworzono listy - operacja anulowana!";
        sleep(2);
    }
    system("cls");
}

void BiListOperations::searchKey(){
    system("cls");
    if(this->list != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora chcesz znalezc: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            int result = this->list->searchKey(number);
            if(result == -1){
                system("cls");
                std::cout << "Nie znaleziono tego klucza!";
                sleep(2);
            }
            else{
                system("cls");
                std::cout << "Klucz jest na pozycji: " << result;
                sleep(3);
            }
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

void BiListOperations::readFromFile(){
    system("cls");
    readData("dane.txt");
    system("cls");
}

void BiListOperations::readData(std::string name){
    std::string PATH = this->path + name;
    this->handler.open(PATH);
    
    std::string line;
    
    //Pierwsza linia
    getline(this->handler, line);
    
    if(this->list == nullptr){
        this->list = new BiList();
    }
    else{
        system("cls");
        std::cout << "Usun obecna liste!";
        sleep(2);
        system("cls");
        return;
    }

    int sizeA = std::stoi(line);
    int data;

    for(int i=0; i<sizeA; i++){
        getline(this->handler, line);
        if(this->lib->isNum(line)){
            data = std::stoi(line);
            this->list->addAtTheEnd(data);
        }
        else{
            system("cls");
            std::cout << "Nieprawidlowe dane w pliku!\n"
                      << "Operacja anulowana!";
            sleep(2);
            system("cls");
            return;
        }
    }

    this->handler.close();
}