#pragma once

#include "BinaryHeap.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include "Additional.h"
#include <fstream>
#include "clock2.h"

class BinaryHeapOperations
{
private:
    BinaryHeap* heap;
    Additional* lib;
    std::string path;
    std::fstream handler;
    Clock2* cl;

    void Test(int quantity, char decision2);

public:
    BinaryHeapOperations();
    ~BinaryHeapOperations();

    void mainLoop();
    void readFromFile();
    void readData(std::string name);
    void searchKey();

    //A lub a
    void autoTest();
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
    this->cl = new Clock2();
    this->path = "D:/STUDIA/IV semestr/SDiZO/Projekt/SDiZO_project/App/BinaryHeapLib/";
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
                  << "A lub a. Test automatyczny\n"
                  << "N lub n. Stworz nowy kopiec\n"
                  << "1. Dodaj liczbe do kopca\n"
                  << "2. Usun liczbe z korzenia\n"
                  << "3. Dodaj n liczb do kopca\n"
                  << "4. Usun z korzenia n liczb\n"
                  << "5. Wprowadz dane recznie i zbuduj kopiec\n"
                  << "K lub k. Znajdz wartosc w kopcu (jako tablica)\n"
                  << "W lub w. Wczytaj dane z pliku i zbuduj kopiec\n"
                  << "S lub s. Pokaz zawartosc kopca\n"
                  << "D lub D. Usun kopiec\n"
                  << "X lub x. Zakoncz operacje na kopcu\n\n"
                  << "Wpisz numer lub znak operacji: ";
        
        std::cin >> operation;
        fflush(stdin);

        switch(operation){
            case 'A':
                autoTest();
                break;
            case 'a':
                autoTest();
                break;

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
                pushN();
                break;

            case '4':
                popN();
                break;
            
            case '5':
                manualPush();
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
                return;
                break;
            case 't':
                system("cls");
                delete this->heap;
                this->heap = nullptr;
                std::cout << "Kopiec usuniety!";
                sleep(2);
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

void BinaryHeapOperations::searchKey(){
    system("cls");
    if(this->heap != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora chcesz znalezc: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            int result = this->heap->searchKey(number);
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
        std::cout << "Nie stworzono kopca!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BinaryHeapOperations::readFromFile(){
    system("cls");
    readData("dane.txt");
    system("cls");
}

void BinaryHeapOperations::readData(std::string name){
    this->handler.close();
    std::string PATH = this->path + name;
    this->handler.open(PATH);
    
    std::string line;
    
    //Pierwsza linia
    getline(this->handler, line);
    
    if(this->heap == nullptr){
        this->heap = new BinaryHeap();
    }
    else{
        system("cls");
        std::cout << "Usun obecny kopiec!";
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
            this->heap->heapPush(data);
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

void BinaryHeapOperations::autoTest(){
    system("cls");
    delete this->heap;
    char decision1, decision2;
    int quantity;
    std::cout << "Ile losowych danych ma znalezc sie w strukturze?\n"
              << "1. 250 tys.\n"
              << "2. 500 tys.\n"
              << "3. 750 tys.\n"
              << "4. 1 mln\n\n"
              << "Wprowadz numer: ";
    std::cin >> decision1;
    fflush(stdin);
    switch(decision1){
        case '1':
            quantity = 250000;
            break;
        case '2':
            quantity = 500000;
            break;
        case '3':
            quantity = 750000;
            break;
        case '4':
            quantity = 1000000;
            break;
        
        default:
            system("cls");
            std::cout << "Wprowadzono niepoprawny znak!\n"
                      << "Operacja anulowana!";
            sleep(2);
            return;
            break;
    }

    this->heap = new BinaryHeap(quantity);

    //Uruchom  generator liczb pseudolosowych
    srand(time(NULL));
    //Wypełnienie struktury losowymi liczbami:

    for(int i=0; i<quantity; i++){
        int input;
        do{
            input = rand();
            this->heap->getArray()[i] = input;
        }while(input == 1); //Jedynka będzie kluczem, który będę wyszukiwał w testach
    }

    this->heap->buildHeap();

    system("cls");
    std::cout << "Ktora operacja ma zostac przeanalizowana?\n"
              << "1. Dodawanie klucza do kopca\n"
              << "2. Usuwanie korzenia\n"
              << "3. Wyszukanie pierwszego wystapienia klucza\n\n"
              << "Wpisz jej numer: ";
    std::cin >> decision2;
    fflush(stdin);

    switch(decision2){
        case '1':
            Test(quantity, decision2);
            break;
        
        case '2':
            Test(quantity, decision2);
            break;
        
        case '3':
            Test(quantity, decision2);
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

void BinaryHeapOperations::Test(int quantity, char decision2){
    system("cls");
    int numOp = 100;
    int results[numOp];
    int INDEX[numOp];
    int input, average, index = quantity/2;

    for(int i=0; i<numOp; i++){
        do{
            input = rand();
            switch(decision2){
                case '1':
                    this->cl->startTime();
                    this->heap->heapPush(input);
                    this->cl->endTime();
                    //Odbudowuję liczbę danych
                    this->heap->heapPop();
                    break;
                case '2':
                    this->cl->startTime();
                    this->heap->heapPop();
                    this->cl->endTime();
                    //Odbudowuję liczbę danych
                    this->heap->heapPush(input);
                    break;
                case '3':
                    int output;
                    //Celowo umieszczam jedynkę
                    this->heap->heapPush(1);
                    this->cl->startTime();
                    output = this->heap->searchKey(1);
                    this->cl->endTime();
                    INDEX[i] = output;
                    if(output != -1){
                        int result = this->cl->executionTime();
                        if(result){
                            results[i] = result;
                        }
                        continue;
                    }
                    break;
            }
            int result = this->cl->executionTime();
            if(result){
                results[i] = result;
            }
        }while(this->cl->executionTime() == 0); //Nieuwzględnione błędy - zabezpieczenie
    }

    if(decision2 == '3'){
        std::cout << "Znalezione indeksy: [";
        for(int i=0; i<numOp; i++){
            std::cout << " " << INDEX[i] << " ";
        }
        std::cout << "]\n\n";
    }

    average = this->lib->average(results, numOp);

    std::cout << "Rezultaty: [";
    for(int i=0; i<numOp; i++){
        std::cout << " " <<results[i] << " ";
    }
    std::cout << "]\n\n";
    std::cout << "Sredni czas operacji: " << average << "\n\n";
    std::cout << "Wcisnij Enter, aby kontynuowac!";
    std::cin.get();
    fflush(stdin);
    system("cls");
}
