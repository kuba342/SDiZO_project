#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include "BRTree.h"
#include "Additional3.h"
#include "Node.h"
#include "clock3.h"


class BRTreeOperations
{
private:
    BRTree* tree;
    Additional3* lib;
    std::string path;
    std::fstream handler;
    Clock3* cl;

    void Test(int quantity, char decision2);

public:
    BRTreeOperations();
    ~BRTreeOperations();

    void mainLoop();
    //A lub a
    void autoTest();
    //N lub n
    void createTree();
    //1
    void addElement();
    //2
    void removeElement();
    //K lub k
    void searchKey();
    //S lub s
    void showTree();
    //D lub d
    void removeTree();
    //W lub w
    void readFromFile();
    void readData(std::string name);
};

BRTreeOperations::BRTreeOperations(){
    this->tree = nullptr;
    this->lib = new Additional3();
    this->cl = new Clock3();
    this->path = "D:/STUDIA/IV semestr/SDiZO/Projekt/SDiZO_project/App/BRTree/";
}

BRTreeOperations::~BRTreeOperations(){
    delete this->tree;
}

void BRTreeOperations::mainLoop(){
    char option;
    while(1){
        system("cls");
        std::cout << "OPERACJE DLA DRZEWA CZERWONO-CZARNEGO\n\n"
                  << "A lub a. Testy automatyczne\n"
                  << "N lub n. Stworz nowe drzewo\n"
                  << "1. Dodaj liczbe do drzewa\n"
                  << "2. Usun liczbe z drzewa\n"
                  << "K lub k. Znajdz wartosc w drzewie\n"
                  << "W lub w. Wczytaj dane z pliku\n"
                  << "S lub s. Wyswietl drzewo (inorder)\n"
                  << "D lub d. Usun drzewo\n"
                  << "X lub x. zakoncz operacje na drzewie\n\n"
                  << "Wpisz numer lub znak operacji: ";
        std::cin >> option;
        fflush(stdin);

        switch(option){
            case 'N':
                createTree();
                break;
            case 'n':
                createTree();
                break;
            
            case 'A':
                autoTest();
                break;
            case 'a':
                autoTest();
                break;

            case '1':
                addElement();
                break;
            case '2':
                removeElement();
                break;

            case 'K':

                break;
            case 'k':

                break;

            case 'W':
                readFromFile();
                break;
            case 'w':
                readFromFile();
                break;
            
            case 'S':
                showTree();
                break;
            case 's':
                showTree();
                break;
            
            case 'D':
                removeTree();
                break;
            case 'd':
                removeTree();
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

void BRTreeOperations::createTree(){
    system("cls");
    if(this->tree == nullptr){
        this->tree = new BRTree();
        std::cout << "Stworzono drzewo!";
        sleep(2);
    }
    else{
        char decision;
        std::cout << "Czy chcesz nadpisac obecne drzewo?\n"
                  << "Wpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);
        switch(decision){
            case 'T':
                system("cls");
                this->tree = new BRTree();
                std::cout << "Stworzono drzewo!";
                sleep(2);
            break;
            case 't':
                system("cls");
                this->tree = new BRTree();
                std::cout << "Stworzono drzewo!";
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

void BRTreeOperations::addElement(){
    system("cls");
    if(this->tree != nullptr){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie dodana: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            //this->tree->treeInsert(number);
            this->tree->addElement(number);
            system("cls");
            std::cout<<"Dodano element!";
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
        std::cout << "Nie stworzono drzewa!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BRTreeOperations::removeElement(){
    system("cls");
    if((this->tree != nullptr) && (this->tree->getSize() != 0)){
        std::string bufor;
        std::cout << "Wprowadz liczbe, ktora zostanie usunieta: ";
        std::cin >> bufor;
        fflush(stdin);
        if(this->lib->isNum(bufor)){
            int number = std::stoi(bufor);
            Node* node = this->tree->treeSearch(this->tree->getRoot(), number);
            if(node != this->tree->getNIL()){
                this->tree->deleteElement(number);
                system("cls");
                std::cout << "Usunieto element!";
                sleep(2);
            }
            else{
                system("cls");
                std::cout << "Nie ma takiego klucza!\n"
                          << "Operacja anulowana!";
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
        std::cout << "Nie stworzono drzewa lub nie ma w nim danych!\n"
                  << "Nie wykonano operacji!";
        sleep(2);
    }
    system("cls");
}

void BRTreeOperations::showTree(){
    system("cls");
    if(this->tree != nullptr){
        std::cout << "Zawartosc drzewa w porzadku inorder: [";
        this->tree->inorderTreeWalk(this->tree->getRoot());
        std::cout << "]\n";
        std::cout << "Korzen: " << this->tree->getRoot()->getColor() <<this->tree->getRoot()->getKey() << "\n";
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    else{
        std::cout << "Nie stworzono drzewa!";
        std::cout << "\nWcisnij Enter, aby kontynuowac!";
        std::cin.get();
        fflush(stdin);
    }
    system("cls");
}

void BRTreeOperations::removeTree(){
    system("cls");
    if(this->tree != nullptr){
        char decision;
        std::cout << "Czy chcesz usunac istniejace drzewo?\nWpisz T/N: ";
        std::cin >> decision;
        fflush(stdin);

        switch(decision){
            case 'T':
                system("cls");
                delete this->tree;
                this->tree = nullptr;
                std::cout << "Drzewo usuniete!";
                sleep(2);
                return;
                break;
            case 't':
                system("cls");
                delete this->tree;
                this->tree = nullptr;
                std::cout << "Drzewo usuniete!";
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
        system("cls");
        std::cout << "Nie stworzono drzewa!\n"
                  << "Operacja anulowana!";
        sleep(2);
    }
    system("cls");
}

void BRTreeOperations::readFromFile(){
    system("cls");
    readData("dane.txt");
    system("cls");
}

void BRTreeOperations::readData(std::string name){
    this->handler.close();
    std::string PATH = this->path + name;
    this->handler.open(PATH);

    std::string line;

    getline(this->handler, line);

    if(this->tree == nullptr){
        this->tree = new BRTree();
    }
    else{
        system("cls");
        std::cout << "Usun obecne drzewo!";
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
            this->tree->addElement(data);
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

void BRTreeOperations::autoTest(){
    system("cls");
    delete this->tree;
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

    this->tree = new BRTree();
    //Uruchom  generator liczb pseudolosowych
    srand(time(NULL));
    //Wypełnienie struktury losowymi liczbami:
    for(int i=0; i<quantity; i++){
        int input;
        input = rand();
        this->tree->addElement(input);
    }

    system("cls");
    std::cout << "Ktora operacja ma zostac przeanalizowana?\n"
              << "1. Dodawanie klucza do drzewa czerwono-czarnego\n"
              << "2. Usuwanie korzenia\n"
              << "3. Usuwanie losowego elementu\n"
              << "4. Wyszukanie pierwszego wystapienia losowego klucza\n\n"
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
        
        case '4':
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

void BRTreeOperations::Test(int quantity, char decision2){
    system("cls");
    int numOp = 100;
    int results[numOp];
    int INDEX[numOp];
    int input, average, index = quantity/2, rootKey;
    Node* node = nullptr;
    Node* node1 = nullptr;

    for(int i=0; i<numOp; i++){
        do{
            input = rand();
            switch(decision2){
                case '1':
                    this->cl->startTime();
                    this->tree->addElement(input);
                    this->cl->endTime();
                    //Odbudowuję liczbę danych
                    this->tree->deleteElement(input);
                    break;
                case '2':
                    rootKey = this->tree->getRoot()->getKey();
                    this->cl->startTime();
                    this->tree->deleteElement(rootKey);
                    this->cl->endTime();
                    //Odbudowuję liczbę danych
                    this->tree->addElement(rootKey);
                    break;
                case '3':
                    node = nullptr;
                    node = this->tree->treeSearch(this->tree->getRoot(), input);
                    if(node != this->tree->getNIL()){
                        this->cl->startTime();
                        this->tree->deleteElement(input);
                        this->cl->endTime();
                        //Odbudowuję liczbę danych
                        this->tree->addElement(input);
                    }
                    break;
                case '4':
                    node1 = nullptr;
                    node1 = this->tree->treeSearch(this->tree->getRoot(), input);
                    if(node1 != this->tree->getNIL()){
                        this->cl->startTime();
                        this->tree->treeSearch(this->tree->getRoot(), input);
                        this->cl->endTime();
                    }
                    break;
            }
            int result = this->cl->executionTime();
            if(result){
                results[i] = result;
            }
        }while(this->cl->executionTime() == 0);
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

