#pragma once

#include <string>
#include "ArrayLib/Array.h"
#include "ArrayLib/ArrayOperations.h"
#include "LinkedListLib/LinkedListOperations.h"
#include "BinaryHeapLib/BinaryHeapOperations.h"
#include "BRTree/BRTreeOperations.h"

class App
{
private:
    /* data */
    char optionChar;
    std::string GREETINGS_MESSAGE;
    std::string OPTIONS;
    ArrayOperations *arrayOp;
    LinkedListOperations *listOp;
    BinaryHeapOperations *heapOp;
    BRTreeOperations *treeOp;
public:
    App();
    ~App();
    //Deklaracje metod:
    void showMessage();
    void mainLoop();
    void arrayOperations();
    void listOperations();
    void heapOperations();
    void treeOperations();
};