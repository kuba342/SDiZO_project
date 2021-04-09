#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include "Array.h"
#include "Additional1.h"
#include <fstream>
#include "clock.h"
#include <time.h>

class ArrayOperations
{
private:
    Array* array;
    std::fstream handler;
    std::string path;
    Clock* cl;

public:
    Additional1* lib;
    ArrayOperations();
    ~ArrayOperations();
    void mainLoop();
    //A lub a
    void autoTest();
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
    void entering();
    //S lub s
    void showArray();
    //D lub d
    void removeTab();
    void readFromFile();
    void readData(std::string name);
    void searchKey();
    //SETTERY I GETTERY
    Array* getArray();
    void setArray(Array* array);
};

//KONSTRUKTOR
ArrayOperations::ArrayOperations(){
    this->lib = new Additional1();
    this->array = nullptr;
    this->path = "D:/STUDIA/IV semestr/SDiZO/Projekt/SDiZO_project/App/ArrayLib/";
    this->cl = new Clock();
}

//DESTRUKTOR
ArrayOperations::~ArrayOperations()
{
    delete this->array;
    delete this->lib;
}

/*********************RESZTA METOD POMOCNICZYCH****************************************/
void ArrayOperations::mainLoop(){
    char number;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA TABLICY\n\n"
                  << "A lub a. Test automatyczny\n"
                  << "N lub n. Stworz nowa tablice\n"
                  << "1. Dodaj liczbe na poczatku tablicy\n"
                  << "2. Dodaj liczbe na koncu tablicy\n"
                  << "3. Dodaj liczbe w dowolnym miejscu tablicy\n"
                  << "4. Usun liczbe z poczatku tablicy\n"
                  << "5. Usun liczbe z konca tablicy\n"
                  << "6. Usun liczbe z dowolnego miejsca tablicy\n"
                  << "K lub k. Znajdz wartosc w tablicy\n"
                  << "W lub w. Wczytaj dane z pliku\n"
                  << "F lub f. Wypelnij tablice recznie\n"
                  << "S lub s. Wyswietl tablice\n"
                  << "D lub d. Usun tablice\n"
                  << "X lub x. Zakoncz operacje na tablicy\n\n"
                  << "Wpisz numer lub znak operacji: ";
        std::cin >> number;
        fflush(stdin);
        switch(number){
            case 'A':
                autoTest();
                break;
            case 'a':
                autoTest();
                break;
            
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
            this->cl->startTime();
            this->array->addAtTheBeginning(number);
            this->cl->endTime();
            system("cls");
            std::cout << "Dodano na poczatek!\n"
                      << "Czas operacji: " << this->cl->executionTime();
            sleep(5);
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
    system("cls");
    if(this->array != nullptr){
        std::string bufor;
        std::cout << "Pod ktorym indeksem umiescic liczbe?\nWpisz: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor) && (std::stoi(bufor) <= this->array->getSize())){
            int index = std::stoi(bufor);
            std::cout << "\nJaka wartosc?\nWpisz: ";
            std::cin >> bufor;
            fflush(stdin);
            if(this->lib->isNum(bufor)){
                int number = std::stoi(bufor);
                this->array->addOnPosition(number, index);
                system("cls");
                std::cout << "Dodano nowy element do tablicy!";
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
            std::cout << "Wprowadzone znaki nie sa liczba lub zly indeks!";
            sleep(3);
            system("cls");
        }
    }
    else{
        std::cout << "Musisz najpierw stworzyc tablice!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::removeAtTheBeginning(){
    system("cls");
    if(this->array != nullptr && this->array->getSize() > 0){
        this->array->removeAtTheBeginning();
        std::cout << "Usunieto pierwszy element!";
        sleep(2);
    }
    else{
        std::cout << "Nie stworzono tablicy lub nie ma w niej danych!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::removeAtTheEnd(){
    system("cls");
    if(this->array != nullptr && this->array->getSize() > 0){
        this->array->removeAtTheEnd();
        std::cout << "Usunieto ostatni element!";
        sleep(2);
    }
    else{
        std::cout << "Nie stworzono tablicy lub nie ma w niej danych!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::removeOnPosition(){
    system("cls");
    if(this->array != nullptr){
        std::string bufor;
        std::cout << "Pod ktorym indeksem usunac liczbe?\nWpisz: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor) && (std::stoi(bufor) < this->array->getSize())){
            int index = std::stoi(bufor);
            this->array->removeOnPosition(index);
            system("cls");
            std::cout << "Usunieto liczbe pod wskazanym indeksem!";
            sleep(2);
            system("cls");
        }
        else{
            system("cls");
            std::cout << "Wprowadzone znaki nie sa liczba lub zly indeks!";
            sleep(3);
            system("cls");
        }
    }
    else{
        std::cout << "Musisz najpierw stworzyc tablice!";
        sleep(2);
    }
    system("cls");
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
        if(this->array->fullTable == true){
            char decision;
            std::cout << "Czy chcesz nadpisac istniejaca tablice?\nWpisz T/N: ";
            std::cin >> decision;
            fflush(stdin);

            switch(decision){
                case 'T':
                    system("cls");
                    entering();
                    break;
                case 't':
                    system("cls");
                    entering();
                    break;
                
                case 'N':
                    return;
                    break;
                case 'n':
                    return;
                    break;
                
                default:
                    system("cls");
                    std::cout << "Wprowadzono niepoprawny znak!\nAnulowano wypelnienie!";
                    sleep(3);
                    return;
                    break;
            }
        }
        else{
            entering();
            this->array->fullTable = true;
        }
    }
    system("cls");
}

void ArrayOperations::entering(){
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

void ArrayOperations::showArray(){
    system("cls");
    if(this->array != nullptr){
        this->array->showArray();
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    else{
        std::cout << "Nie stworzono tablicy!";
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    system("cls");
}

void ArrayOperations::removeTab(){
    system("cls");
    if(this->array != nullptr){
        char decision;
        std::cout << "Czy chcesz usunac istniejaca tablice?\nWpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);

        switch(decision){
            case 'T':
                system("cls");
                delete this->array;
                this->array = nullptr;
                std::cout << "Tablica usunieta!";
                sleep(3);
                return;
                break;
            case 't':
                system("cls");
                delete this->array;
                this->array = nullptr;
                std::cout << "Tablica usunieta!";
                sleep(3);
                return;
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
        std::cout << "Nie stworzono tablicy - operacja anulowana!";
        sleep(3);
    }
    system("cls");
}

void ArrayOperations::searchKey(){
    system("cls");
    if(this->array != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora chcesz znalezc: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            int result = this->array->searchKey(number);
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
        std::cout << "Nie stworzono tablicy!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void ArrayOperations::readFromFile(){
    system("cls");
    readData("dane.txt");
    system("cls");
}

void ArrayOperations::readData(std::string name){
    this->handler.close();
    std::string PATH = this->path + name;
    this->handler.open(PATH);
    
    std::string line;
    
    //Pierwsza linia
    getline(this->handler, line);
    
    if(this->array == nullptr){
        //Tutaj procedura tworzenia nowej tablicy
        if(this->lib->isNum(line)){
            int number = std::stoi(line);
            this->array = new Array(number);
        }
        else{
            system("cls");
            std::cout << "Blad wczytywania z pliku!";
            sleep(2);
            system("cls");
        }
    }
    else{
        system("cls");
        std::cout << "Usun tablice obecna!";
        sleep(2);
        system("cls");
        this->handler.close();
        return;
    }

    int sizeA = std::stoi(line);
    int data;

    for(int i=0; i<sizeA; i++){
        getline(this->handler, line);
        if(this->lib->isNum(line)){
            data = std::stoi(line);
            this->array->getTable()[i] = data;
        }
        else{
            system("cls");
            std::cout << "Nieprawidlowe dane w pliku!\n"
                      << "Operacja anulowana!";
            sleep(2);
            system("cls");
            this->handler.close();
            return;
        }
    }
    this->handler.close();
}

Array* ArrayOperations::getArray(){
    return this->array;
}

void ArrayOperations::setArray(Array* array){
    this->array = array;
}

/*void ArrayOperations::autoTest(){
    system("cls");
    delete array;
    
    this->array = new Array(10000000);
    
    for(int i=0; i<10000000; i++){
        this->array->getTable()[i] = i;
    }
    this->cl->startTime();
        
        this->array->addAtTheBeginning(99999);

    this->cl->endTime();
    //this->array->showArray();
    std::cout << "Czas wykonania: " << this->cl->executionTime() << "\n";
    std::cout << "\nWcisnij Enter, aby kontynuowac!";
    std::cin.get();
    fflush(stdin);
    system("cls");
}*/


void ArrayOperations::autoTest(){
    system("cls");
    delete this->array;
    char decision1, decision2;
    int quantity;
    std::cout << "Ile losowych danych ma znalezc sie w strukturze?\n"
              << "1. 100 tys.\n"
              << "2. 500 tys.\n"
              << "3. 1 mln\n"
              << "4. 2 mln\n\n"
              << "Wprowadz numer: ";
    std::cin >> decision1;
    fflush(stdin);
    switch(decision1){
        case '1':
            quantity = 100000;
            break;
        case '2':
            quantity = 200000;
            break;
        case '3':
            quantity = 1000000;
            break;
        case '4':
            quantity = 2000000;
            break;
        
        default:
            system("cls");
            std::cout << "Wprowadzono niepoprawny znak!\n"
                      << "Operacja anulowana!";
            sleep(2);
            return;
            break;
    }

    this->array = new Array(quantity);

    srand(time(NULL));
    //Wypełnienie struktury losowymi liczbami:
    for(int i=0; i<quantity; i++){
        this->array->getTable()[i] = rand();
    }

    system("cls");
    std::cout << "Ktora operacja ma zostac przeanalizowana?\n"
              << "1. Dodawanie na poczatek tablicy\n"
              << "2. Dodawanie na koncu tablicy\n"
              << "3. Dodawanie w srodku tablicy\n"
              << "4. Usuwanie z poczatku tablicy\n"
              << "5. Usuwanie z konca tablicy\n"
              << "6. Usuwanie ze srodka tablicy\n"
              << "7. Wyszukanie pierwszego wystapienia klucza\n\n"
              << "Wpisz jej numer:";
    std::cin >> decision2;
    fflush(stdin);

    switch(decision2){
        case '1':

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':

            break;
        case '7':

            break;
        
        default:
            system("cls");
            std::cout << "Wprowadzono niepoprawny znak!\n"
                      << "Operacja anulowana!";
            sleep(2);
            return;
            break;
    }

    system("cls");
}
