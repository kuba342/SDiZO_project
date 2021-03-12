#include <iostream>
#include <stdio.h>
#include <string>

//using namespace std;

class App
{
//private:
    /* data */
    std::string GREETINGS_MESSAGE;
    std::string chooseOption;
    std::string option_1;
    std::string option_2;
    std::string option_3;
public:
    App(/* args */);
    ~App();
    //Deklaracje metod:
    void showMessage();
};

App::~App()
{
}
