#include <iostream>
#include <string>

class Array
{
private:
    /* data */
    int* table;
    int size;
public:
    Array();
    Array(int Size);
    ~Array();
    std::string toString();
    int getSize();
    int* getTable();
};
