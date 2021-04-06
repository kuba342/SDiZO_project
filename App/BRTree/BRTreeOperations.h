#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include "BRTree.h"
#include "Additional3.h"
#include "Node.h"


class BRTreeOperations
{
private:
    BRTree* tree;
    Additional3* lib;
    std::string path;
    std::fstream handler;

public:
    BRTreeOperations();
    ~BRTreeOperations();

    void mainLoop();
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
};

BRTreeOperations::BRTreeOperations(){
    this->tree = nullptr;
    this->lib = new Additional3();
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

                break;
            case 'a':

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

                break;
            case 'w':

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
            if(node != nullptr){
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
