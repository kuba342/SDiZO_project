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





App::App(/* args */)
{
    GREETINGS_MESSAGE = "Program na zaliczenie projektu do kursu:\nStruktury danych i zlozonosc obliczeniowa\nJakub Derda 252819\n\n";
    chooseOption = "Wybierz opcje:\n";
    option_1 = "1.Opcja nr 1\n";
    option_2 = "2.Opcja nr 2\n";
    option_3 = "3.Zakoncz program\n";
}

//Implementacja metod:
void App::showMessage(){
    //Wiadomość powitalna:
    cout << GREETINGS_MESSAGE;
    //Wybierz opcję:
    cout << chooseOption;
    //Opcje po kolei:
    cout << option_1 + option_2 + option_3;
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
