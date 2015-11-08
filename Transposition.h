#ifndef TRANSPOSITION
#define TRANSPOSITION

#include <iostream>

class Transposition
{
public:
    Transposition(std::string);
    void get_key(int* in_key,int in_len){
        key = in_key;
        _len = in_len;
    }
    std::string encrypt();
    std::string decrypt();
private:
    std::string origin;
    std::string afterCi;
    std::string afterDe;
    int* key;
    int _len;
};

#endif // TRANSPOSITION

