#pragma once
#include <string>

class Additional3{
public:
    bool isNum(std::string str);
};

bool Additional3::isNum(std::string str){
    for(int a = 0; a < str.length(); a++) {
        if(str[a] > '0' + 9 || str[a] < '0') return false;
    }
    return true;
}