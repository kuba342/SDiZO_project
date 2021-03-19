#pragma once

#include <string>
#include "ArrayLib/Array.h"
#include "ArrayLib/ArrayOperations.h"

class App
{
private:
    /* data */
    char optionChar;
    std::string GREETINGS_MESSAGE;
    std::string OPTIONS;
    Array *array;
    ArrayOperations *arrayOp;
public:
    App();
    ~App();
    //Deklaracje metod:
    void showMessage();
    void mainLoop();
    void arrayOperations();
    void loopWithTxt();
    void loopWithoutTxt();
};