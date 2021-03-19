#pragma once
#include <string>
#include "Array.h"

class App
{
private:
    /* data */
    int optionNumber;
    std::string GREETINGS_MESSAGE;
    std::string OPTIONS;
    Array array;
public:
    App();
    ~App();
    //Deklaracje metod:
    void showMessage();
    void mainLoop();
    void arrayOperations();
};
