#ifndef CAESAR
#define CAESAR

#include <iostream>

class Caesar
{
public:
    Caesar(std::string);
    void getkey(int);
    std::string encrypt();
    std::string decrypt();
private:
    std::string origin;
    std::string afterCi;
    std::string afterDe;
    int key;
};

#endif // CAESAR

