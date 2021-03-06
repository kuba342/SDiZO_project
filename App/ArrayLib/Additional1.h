#pragma once
#include <string>

class Additional1{
public:
    Additional1();
    bool isNum(std::string str);
    int average(int* Tab, int size);
};

Additional1::Additional1(){
}

bool Additional1::isNum(std::string str){
    for( int a = 0; a < str.length(); a++ ) {
        if(str[a] > '0' + 9 || str[a] < '0') return false;
    }
    return true;
}

int Additional1::average(int* Tab, int size){
    int sum = 0, average;
    for(int i=0; i<size; i++){
        sum += Tab[i];
    }
    return average = sum/size;
}