#ifndef AUTOKEY
#define AUTOKEY

#include <iostream>

class Autokey
{
public:
    Autokey(std::string str);
    void get_key(std::string input){
        key = input;
    }

    std::string real_key();
    std::string encrypt();
    std::string decrypt();
private:
    std::string origin;
    std::string afterCi;
    std::string afterDe;
    std::string key;
};

#endif // AUTOKEY

