#include <iostream>
#include "Caesar.h"

Caesar::Caesar(std::string str){
    origin = str;
}
void Caesar::getkey(int input){
    key = input;
}
std::string Caesar::encrypt(){
    std::string _str = origin;
    for (unsigned int i = 0; i < _str.length(); i++){
        if (isupper(_str.at(i))){
            _str.at(i) = (_str.at(i) - 'A' + key) % 26 + 'A';
        }
        else if (islower(_str.at(i))){
            _str.at(i) = (_str.at(i) - 'a' + key) % 26 + 'a';
        }
    }
    afterCi = _str;
    return afterCi;
}

std::string Caesar::decrypt(){
    std::string _str = origin;
    for (unsigned int i = 0; i < _str.length(); i++){
        if (isupper(_str.at(i))){
            _str.at(i) = (_str.at(i) - 'A' - key +26) % 26 + 'A';
        }
        else if (islower(_str.at(i))){
            _str.at(i) = (_str.at(i) - 'a' - key +26) % 26 + 'a';
        }
    }
    afterDe = _str;
    return afterDe;
}
