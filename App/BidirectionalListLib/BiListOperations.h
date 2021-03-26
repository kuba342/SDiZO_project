#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include "BiList.h"

class BiListOperations
{
private:
    BiList* list;

public:
    BiListOperations();
    ~BiListOperations();
    void mainLoop();
    
    void createList();
    //1
    void addAtTheBeginning();
    //2
    void addAtTheEnd();
    //3
    void addOnPosition();
    //4
    void removeAtTheBeginning();
    //5
    void removeAtTheEnd();
    //6
    void removeOnPosition();


};

BiListOperations::BiListOperations()
{
}

BiListOperations::~BiListOperations()
{
}

