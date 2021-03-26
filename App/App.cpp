#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "App.h"
#include "ArrayLib/Array.h"


int main(void){
    App app = App();
    app.mainLoop();
    return 0;
}


/*KONSTRUKTOR*/
App::App(/* args */)
{
    GREETINGS_MESSAGE = "Program na zaliczenie projektu do kursu:\nStruktury danych i zlozonosc obliczeniowa\nJakub Derda 252819\n\n";
    OPTIONS = "Wybierz opcje:\n1.Operacje na tablicy dynamicznej\n";
    OPTIONS += "2.Operacje na liscie dwukierunkowej\n";
    OPTIONS += "3.Operacje na kopcu binarnym\n";
    OPTIONS += "4.Operacje na drzewie czerwono-czarnym\n";
    OPTIONS += "X lub x: Koniec programu\n\n";
    OPTIONS += "Wpisz znak opcji i zatwierdz enterem: ";
}

/*DESTRUKTOR*/
App::~App()
{
    system("cls");
    std::cout << "Program zakonczyl swoje dzialanie\nPozdrawiam!";
}

//Implementacja metod:
void App::showMessage(){
    //Wiadomość powitalna:
    std::cout << this->GREETINGS_MESSAGE;
}

void App::mainLoop(){
    
    system("cls");
    showMessage();
    sleep(2);
    system("cls");

    while(1){
        system("cls");
        std::cout << this->OPTIONS;
        std::cin >> this->optionChar;

        switch(this->optionChar){
            case '1':
                system("cls");
                arrayOperations();
                break;
            case '2':
                system("cls");
                listOperations();
                break;
            case '3':
                system("cls");
                heapOperations();
                break;
            case '4':
                system("cls");
                treeOperations();
                break;
            case 'X':
                system("cls");
                exit(0);
                break;
            case 'x':
                system("cls");
                exit(0);
                break;
            default: 
                system("cls");
				printf("WPISANO NIEPOPRAWNY ZNAK!\n");
                sleep(2);
				break;
        }
        system("cls");
    }
}

void App::arrayOperations(){
    this->arrayOp = new ArrayOperations();
    this->arrayOp->mainLoop();
}

void App::listOperations(){
    this->listOp = new BiListOperations();
    std::cout << "TU BEDA OPERACJE";
    sleep(2);
}

void App::heapOperations(){
    this->heapOp = new BinaryHeapOperations();
    std::cout << "TU BEDA OPERACJE";
    sleep(2);
}

void App::treeOperations(){
    this->treeOp = new BRTreeOperations();
    std::cout << "TU BEDA OPERACJE";
    sleep(2);
}
