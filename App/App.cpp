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
    OPTIONS = "Wybierz opcje:\n1.Operacje na tablicy dynamicznej\n2.Operacje na liscie dwukierunkowej\n3.Koniec programu\n";
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
        std::cout << "Czy chcesz wczytac dane z pliku?\n"
                  << "T/N: ";
        std::cin >> this->optionChar;

        switch(this->optionChar){
            case 'T' | 't':
                loopWithTxt();
            break;

            case 'N' | 'n':
                loopWithoutTxt();
            break;

            default:
                system("cls");
                std::cout << "Wprowadzono niepoprawny znak!";
                sleep(2);
                system("cls");
            break;
        }
        fflush(stdin);
    }
}

void App::loopWithTxt(){
    std::cout << "Tu jeszcze nic nie ma, ale na wszystko przyjdzie czas ;)";
    exit(0);
}

void App::loopWithoutTxt(){
    while(1){
        system("cls");
        std::cout << this->OPTIONS;
        std::cin>>this->optionChar;

        switch(this->optionChar){
            case '1':
                system("cls");
                /*std::cout << "Wykonuje opcje nr 1\n";
                sleep(2);*/
                arrayOperations();
                break;
            case '2':
                system("cls");
                std::cout << "Wykonuje opcje nr 2\n";
                sleep(2);
                break;
            case '3':
                system("cls");
                exit(0);
                break;
            default: 
                system("cls");
				printf("\nWPISANO NIEPOPRAWNY ZNAK!\n");
                sleep(2);
				break;
        }
        system("cls");
    }
}

void App::arrayOperations(){
    this->arrayOp = new ArrayOperations();
    this->arrayOp->mainLoop();
    //new ArrayOperations();
    /*system("cls");
    int elements;
    std::cout << "Ile elementow ma miec tablica?\nWprowadz liczbe: ";
    std::cin >> elements;
    if(elements){
        array = new Array(elements);
        std::cout << "Wprowadz elementy tablicy:\n";
        array->enterNumbers();
        array->showArray();
        sleep(5);
    }*/
}