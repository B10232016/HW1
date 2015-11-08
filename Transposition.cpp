
#include <iostream>
#include <string>
#include "Transposition.h"

Transposition::Transposition(std::string str){
    origin = str;
}

std::string Transposition::encrypt(){
    std::string _str = origin;
    int height = (_str.length() + _len - 1) / _len;
    char **ptr = NULL;
    ptr = new char*[height];
    for (int i = 0; i < height; i++){
        ptr[i] = new char[_len];
    }

    unsigned int pos = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < _len; j++){
            if (pos < _str.length()){
                if (isupper(_str.at(pos))){
                    _str.at(pos) = tolower(_str.at(pos));
                }
                ptr[i][j] = _str.at(pos);
                pos++;
            }
            else{
                ptr[i][j] = NULL;
            }
        }
    }

    std::string _str1 = "";


    int pos1 = 1;
    while (pos1 <= _len){
        for (int i = 0; i < _len; i++){
            if (pos1 == key[i]){
                for (int j = 0; j < height; j++){
                    if (ptr[j][i] != NULL){
                        _str1 = _str1 + ptr[j][i];
                    }
                }
                pos1++;
            }
        }
    }
    afterCi = _str1;
    return afterCi;
}

std::string Transposition::decrypt(){
    char* word_array = (char*)new char(origin.length() + 1);
    int count = 0;
    for(int i = 0; i < _len; i++){
        for(int j = 0; j < _len; j++){
            if( key[j] == i + 1 ){
                int high = origin.length() / _len;
                if((int)origin.length() % _len >= j + 1){
                    high++;
                }
                for(int k = 0; k < high; k++){
                    word_array[ k * _len + j] = origin.at(count) ;
                    count++ ;
                }
            }
        }
    }
    word_array[origin.length() + 1] = '\0';
    afterDe = std::string(word_array);
    return afterDe;
}
