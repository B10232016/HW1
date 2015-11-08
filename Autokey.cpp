
#include <iostream>
#include <string>
#include "Autokey.h"

Autokey::Autokey(std::string str){
    origin = str;
}
std::string Autokey::real_key(){
    std::string output = "";
    output += key;
    for(unsigned int i = 0 ; i < origin.length() - key.length(); i++ )
        output += origin.at(i);
    return output;
}

std::string Autokey::encrypt(){
    std::string _str = origin;

    std::string realkey = real_key();
    for(unsigned int i = 0; i < _str.length(); i++){
        if (isupper(_str.at(i))){
            _str.at(i) = ((_str.at(i)-'A') ^ (toupper(realkey.at(i))-'A'))%26 + 'A';
        }
        else if (islower(_str.at(i))){
            _str.at(i) = ((_str.at(i)-'a') ^ (tolower(realkey.at(i))-'a'))%26 + 'a';
        }
    }
    afterCi = _str;
    return afterCi;
}

std::string Autokey::decrypt(){
    std::string subkey = key;
    std::string nextkey = "" ;
    int len = key.length();
    afterDe = origin;
    for(unsigned int i = 0 ; i < afterDe.length() ; i++){
        if (isupper(afterDe.at(i))){
                afterDe.at(i) = ((afterDe.at(i) - 'A') ^ (toupper(subkey.at(i % len)) - 'A')) % 26 + 'A';
        }
        else if (islower(afterDe.at(i))){
                afterDe.at(i) = ((afterDe.at(i) - 'a' ) ^ (tolower(subkey.at(i % len)) - 'a')) % 26 + 'a';
        }
        nextkey += afterDe.at(i);
        if( i % len == len - 1 ){
            subkey = nextkey;
            nextkey = "";
        }
    }
    return afterDe;
}
