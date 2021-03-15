#include <iostream>
#include <stdio.h>
#include <string>

//using namespace std;

class App
{
//private:
    /* data */
    int optionNumber;
    std::string GREETINGS_MESSAGE;
    std::string options;
public:
    App(/* args */);
    ~App();
    //Deklaracje metod:
    void showMessage();
    void mainLoop();
};
