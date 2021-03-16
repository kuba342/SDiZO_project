#include <iostream>
#include <string>

class Array
{
private:
    /* data */
    int* table;
    int size;
public:
    //Konstruktory
    Array();
    Array(int Size);
    //Destruktor
    ~Array();
    std::string toString();
    //Settery ii gettery
    int getSize();
    int* getTable();
    //Operacje na elementach tablicy
    void swap(int beginning, int end);
    void addAtTheBeginning(int number);
    void addAtTheEnd(int number);
    void removeAtTheBeginning();
    void removeAtTheEnd();
    void addOnPosition(int number, int numberOfPosition);
    void removeOnPosition(int number, int numberOfPosition);

};
