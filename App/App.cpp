#include <stdio.h>
#include <iostream>
#include "App.h"


using namespace std;

int main(){
    App app = App();
    app.showMessage();
    return 0;
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

App::App(/* args */)
{
    GREETINGS_MESSAGE = "Program na zaliczenie projektu do kursu:\nStruktury danych i złożoność obliczeniowa\nJakub Derda 252819\n\n";
    chooseOption = "Wybierz opcję:\n";
    option_1 = "1.Opcja nr 1\n";
    option_2 = "2.Opcja nr 2\n";
    option_3 = "3.Zakończ program\n";
}