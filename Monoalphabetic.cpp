#include <iostream>
#include "Monoalphabetic.h"

Monoalphabetic::Monoalphabetic(std::string str){
    origin = str;
}

std::string Monoalphabetic::encrypt(){
    std::string _str = origin;
    for (int i = 0; i < _str.length(); i++){
        if (isupper(_str.at(i))){
            _str.at(i) = toupper(key.at(_str.at(i) - 'A'));
        }
        else if (islower(_str.at(i))){
            _str.at(i) = tolower(key.at(_str.at(i) - 'a'));
        }
        std::cout<<i<<","<<origin.at(i)<<"->"<<_str.at(i)<<std::endl;
    }
    afterCi = _str;
    return afterCi;
}

std::string Monoalphabetic::decrypt(){
    std::string _str = origin;
    for (int i = 0; i < _str.length(); i++){
        if (isupper(_str.at(i))){
            _str.at(i) = toupper(antikey.at(_str.at(i) - 'A'));
        }
        else if (islower(_str.at(i))){
            _str.at(i) = tolower(antikey.at(_str.at(i) - 'a'));
        }
    }
    afterDe = _str;
    return afterDe;
}
