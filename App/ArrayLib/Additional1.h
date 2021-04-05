#pragma once
#include <string>

class Additional1{
public:
    Additional1();
    bool isNum(std::string str);
};

Additional1::Additional1(){
}

bool Additional1::isNum(std::string str){
    for( int a = 0; a < str.length(); a++ ) {
        if(str[a] > '0' + 9 || str[a] < '0') return false;
    }
    return true;
}