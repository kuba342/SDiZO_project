#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "App.h"
#include "Array.h"

using namespace std;

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
}

/*DESTRUKTOR*/
App::~App()
{
    system("cls");
    cout << "Program zakonczyl swoje dzialanie\nPozdrawiam!";
}

//Implementacja metod:
void App::showMessage(){
    //Wiadomość powitalna:
    cout << this->GREETINGS_MESSAGE
         << this->OPTIONS;
}

void App::mainLoop(){
    
    while(1){
        system("cls");
        this->showMessage();
        cout<<"Opcja: ";
        cin>>this->optionNumber;
        fflush(stdin);

        switch(this->optionNumber){
            case 1:
                App::arrayOperations();
                break;
            case 2:
                cout << "Wykonuje opcje nr 2\n";
                
                break;
            case 3:
                exit(0);
                break;
            default: 
				printf("\n\nWPISANO NIEPOPRAWNY ZNAK!\n\n");
				break;
        }
        system("cls");
    }
}


void App::arrayOperations(){
    system("cls");
    int elements;
    cout << "Ile elementów ma mieć tablica?\nWprowadz liczbe: ";
    cin >> elements;
    if(elements){
        this->array = Array(elements);
        cout << "Wprowadz elementy tablicy:";
        array.enterNumbers();
        cout << array.toString();
    }
}