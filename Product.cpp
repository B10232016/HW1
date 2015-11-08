
#include <iostream>
#include <string>
#include "Product.h"

Product::Product(std::string str){
    origin = str;
}
std::string extend(std::string input, int len){
    std::string new_one = input;
    if(input.length() % len != 0)
        for(unsigned int i = 0; i < len - input.length() % len; i++){
            new_one += ' ';
        }
    return new_one;
}
std::string Product::encrypt(){
    std::string _str = origin;
    _str = extend(_str , _len);
    std::string extend_origin = extend(origin , _len);

    for (unsigned int i = 0; i < _str.length(); i++){
        _str.at(i) = extend_origin.at(i + key[i % _len] - 1 - ( i % _len ));
        if (isupper(extend_origin.at(i))){
            _str.at(i) = toupper(_str.at(i));
        }
        else if (islower(extend_origin.at(i))){
            _str.at(i) = tolower(_str.at(i));
        }
    }

    afterCi = _str;
    return afterCi;
}

std::string Product::decrypt(){
    std::string _str = origin;
    _str = extend(_str , _len);
    std::string extend_origin = extend(origin , _len);
    for (unsigned int i = 0; i < _str.length(); i++){
        _str.at(i + key[i % _len] - 1 - ( i % _len )) = extend_origin.at(i);

        if (isupper(extend_origin.at(i))){
            _str.at(i) = toupper(_str.at(i));
        }
        else if (islower(extend_origin.at(i))){
            _str.at(i) = tolower(_str.at(i));
        }
    }
    afterDe = _str;
    return afterDe;
}
