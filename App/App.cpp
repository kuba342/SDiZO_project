#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "App.h"



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
    options = "Wybierz opcje:\n1.Opcja nr 1\n";
}

/*DESTRUKTOR*/
App::~App()
{
}

//Implementacja metod:
void App::showMessage(){
    //Wiadomość powitalna:
    cout << GREETINGS_MESSAGE
         << options;
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
                cout << "Wykonuje opcje nr 1\n";
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
